import math
import time
import rclpy
import rclpy.logging
from rclpy.node import Node


from py_objectdetection.detection_publisher import DetectionPublisher
from py_objectdetection.depth_image_to_map_o3d import DepthImageToMapNode
from custom_interfaces.srv  import SetDepth
from custom_interfaces.msg import WorldMap, MapObject, AABB, MotionGoal, DetectionBuffer, BoundingBox
from geometry_msgs.msg import Vector3, Quaternion
import rclpy.parameter
from sensor_msgs.msg import Imu, Image
from std_msgs.msg import Header, String


def IsNewData(original : Header, compare : Header) -> bool:
    isOriginalInvalid = original.frame_id == "-1"

    if(isOriginalInvalid): return True

    hasDiffFrameID = original.frame_id != compare.frame_id

    hasNewerTimestamp = (compare.stamp.sec > original.stamp.sec) or ( (compare.stamp.sec == original.stamp.sec) and compare.stamp.nanosec > original.stamp.nanosec)

    return hasDiffFrameID and hasNewerTimestamp

class SingleBuoyTest(Node):

    _BUOY_DEPTH             : int = -2

    _SUB_WIDTH              : float = 0.60

    _spin_start_time        : float = None
    
    isFinished              : bool

    _stage                  : int

    _detectionBuffer        : DetectionBuffer

    _currentIMU             : Imu

    _currentImage           : Image

    _worldMapInstance       : WorldMap

    _reachedDepthGoal       : bool

    _waitingForDepthGoal    : bool

    spinMapperNode          : bool

    def __init__(self, heading_topic : str, detection_topic : str, motion_goal_topic : str, image_topic : str, depth_control_service : str, depth_goal_topic : str, world_map_topic : str):
        super().__init__("buoy_test_node")
        
        self._stage = 0

        self._motionGoalPublisher = self.create_publisher(MotionGoal,motion_goal_topic,5)

        self._sub_detbuff = self.create_subscription(DetectionBuffer,detection_topic,self.DetectionCallback,5)
        #self._depth_controller_client = self.create_client(SetDepth,)

        self._sub_imu = self.create_subscription(Imu,heading_topic,self.HeadingCallback,5)
        self._sub_image = self.create_subscription(Image, image_topic,self.ImageCallback,5)
        self._sub_worldmap = self.create_subscription(WorldMap,world_map_topic,self.WorldMapCallback,1)
        self._sub_depthGoal = self.create_subscription(String,depth_goal_topic,self.DepthGoalCallback,5)

        self._depth_control_client = self.create_client(SetDepth,depth_control_service)


        self.isFinished = False
        self.spinMapperNode = False

        self._reachedDepthGoal = False
        self._waitingForDepthGoal = False

        self._detectionBuffer = None
        self._currentIMU = None
        self._currentImage = None
        self._worldMapInstance = None


        self._controlLoopTimer = self.create_timer(0.1, self.ControlLoop)




    def ControlLoop(self):
        detected, bbox = self.IsBuoyDetected()
        if(self.isFinished) : self.destroy_timer(self._controlLoopTimer)
        match self._stage:
            #case -1: ## go to depth 
            case -1: 
                if not self._waitingForDepthGoal:
                    req = SetDepth.Request()

                    req.depth = self._BUOY_DEPTH
                    self._depth_control_client.call_async(req)
                    self._waitingForDepthGoal = True


            case 0: # rotate until buoy detected
                if (not detected):
                    outmsg = MotionGoal()
                    outmsg.goal = "y_le"
                    self._motionGoalPublisher.publish(outmsg)
                    self.get_logger().info("buoy not detected, spinning..")
                else:
                    self._stage = 1
                    self.get_logger().info("buoy detected, proceeding to stage 1")
                    outmsg = MotionGoal()
                    outmsg.goal = "kill"
                    self._motionGoalPublisher.publish(outmsg)

            case 1: # align with buoy
                self.get_logger().info("Aligning with buoy")

                if detected:
                    centered, distance = self.isBBoxCentered(bbox)
                    outmsg = MotionGoal()
                    if centered: 
                        self.get_logger().info("buoy is centered, proceeding to stage 2")
                        self._stage = 2
                        outmsg.goal = "kill"
                        self._motionGoalPublisher.publish(outmsg)
                        return
                    elif distance is None:
                        self.get_logger().warning("SingleBuoyTest::ControlLoop() (Stage 1): Warning! robot is not aligned with buoy and lacks direction, doing nothing...")
                    elif distance < 0:
                        
                        outmsg.goal = "y_le"
                        self._motionGoalPublisher.publish(outmsg)
                    else:
                        outmsg = MotionGoal()
                        outmsg.goal = "y_ri"
                        self._motionGoalPublisher.publish(outmsg)
                    self.get_logger().info(f"publishing motor goal: {outmsg.goal}")
            case 2: # move within LIDAR range
                self.get_logger().info("Attempting to get within LIDAR distance")

                motionGoal = MotionGoal()

                motionGoal.goal = "kill"

                if bbox.width <= 70 and bbox.height <= 70:
                    motionGoal.goal = "f_sl"
                else:
                    self._stage = 3
                    self.get_logger().info("Sub is within lidar range, proceeding to stage 3")
                
                self._motionGoalPublisher.publish(motionGoal)


            case 3: # do something with lidar map (eg display)
                if(self._worldMapInstance is None):
                    self.get_logger().info("Generating Lidar Map") 
                    self.spinMapperNode = True
                    return
                
                buoyIsMapObject, buoyObj = self.IsBuoyMapObject()

                if(not buoyIsMapObject):
                    self.get_logger().error("SingleBuoyTest::ControlLoop() : (Stage 3) Lidar has failed to detect buoy, exiting")
                    self.isFinished = True
                    return

                else: 
                    self.get_logger().info("Buoy has been detected using lidar, proceeding to stage 4")
                    self._stage = 4
                    return


                ### TODO: Implimente Heading Control

                # Calculate x-y distance to the front of the buoy, we have to subtract half extents from the z value as the z value represents the distance along the camera normal
                # Since the camera is the origin of the coordinate system, we can just use the x and y components of the AABB center as the x and y distance

                # center = buoyObj.aabb.center

                # dX = center.x
                # dY = center.y

                # dZ = center.z - (buoyObj.aabb.extents.z * 0.5)

                # ## Calculate the trajectory for the sub such that the sub is 1 sub width center distance left or right of the buoy, by default the units are in meters

                # pt_goal = (dX + self._SUB_WIDTH, dY,dZ)


                # d_theta = math.atan2(pt_goal[0],pt_goal[2])









                

                pass
            case 4: # Spin for a bit
                self.get_logger().info("Spinning Robot")
                outmsg = MotionGoal()

                outmsg.goal = "y_le"
                
                self._motionGoalPublisher.publish(outmsg)

                if( self._spin_start_time is None):
                    self._spin_start_time = time.time()
                elif (time.time() - self._spin_start_time >= 2):
                    self.get_logger().info("Spin limit reached, proceeding to stage 5")
                    self._stage = 5
                    return

                pass
            case 5: # Shutdown
                self.get_logger().info("All stages of node \"SingleBuoyTest\" have been completed! exiting the node")
                self.isFinished = True
                return
                pass

    def isBBoxCentered(self, bbox: BoundingBox, pixelTolerance : int = 10) -> tuple[bool, float]:
        if(self._currentImage is None):
            self.get_logger().warning("SingleBuoyTest::isBBoxCentered() : Warning! node lacks image, please ensure that this node is subscribed to the correct topic!")
            return (False, None)
        else:
            camCenterX = self._currentImage.width / 2
            
            dX = bbox.center_x - camCenterX 

            within : bool = False

            if (abs(dX) < pixelTolerance / 2): 
                within = True
            
            return (within, dX)



    def IsBuoyMapObject(self) -> tuple[bool,MapObject]:
        if self._worldMapInstance is None:
            return (False, None)
    
        for mapObject in self._worldMapInstance.objects:
            if(mapObject.name == 'buoys'):
                return (True,mapObject)
        return (False, None)

        

    def IsBuoyDetected(self) -> tuple[bool,BoundingBox]:
        if self._detectionBuffer is None: 
            return (False, None)
        
        for bbox in self._detectionBuffer.detections:
            if(bbox.name == "buoys"):
                return (True, bbox)
        return (False, None)

    def HeadingCallback(self, msg):
        self._currentIMU = msg 
        

    def DetectionCallback(self, msg):
        self._detectionBuffer = msg
    
    def ImageCallback(self, msg):
        self._currentImage = msg
    
    def DepthGoalCallback(self, msg):
        if(self._reachedDepthGoal == True): return

        if(self._stage == -1):
            self._stage = 0

        self._reachedDepthGoal = True
        pass 

    def WorldMapCallback(self, msg): 
        ### Can optimize a few processes by checking if the published map is new data, if it is then set a flag to let other processes know,
        ### otherwise dont update the worldmap instance.
        self._worldMapInstance = msg

def main(args = None):
    rclpy.init()

    # spin detection node for buoy, heading node is provided by realsense camera
    buoyDetector = DetectionPublisher(parameter_overrides=[rclpy.Parameter("name",value="buoy_detector"),rclpy.Parameter("model_path",value="models/dry_buoy.pt"),rclpy.Parameter("topic",value="camera/camera/color/image_raw")])

    mapperNode = DepthImageToMapNode()

    buoyTestNode = SingleBuoyTest(
        heading_topic="camera/camera/imu",
        detection_topic="DetectionBuffer",
        motion_goal_topic="pid_tuning/MotionGoal", 
        image_topic="camera/camera/color/image_raw", 
        depth_control_service="pid_tuning/set_depth",
        depth_goal_topic="pid_tuning/depth_status",
        world_map_topic="WorldMap"
    )

    while not buoyTestNode.isFinished:
        try:
            rclpy.spin_once(buoyDetector)
            rclpy.spin_once(buoyTestNode)
            if(buoyTestNode.spinMapperNode):
                rclpy.spin_once(mapperNode)
        except SystemExit:
            print("Quitting")
            break

    rclpy.shutdown()

    






if __name__ == '__main__':
    main()