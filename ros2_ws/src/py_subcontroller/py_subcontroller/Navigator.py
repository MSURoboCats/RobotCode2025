import math

import rclpy
import rclpy.logging
from rclpy.node import Node
from rclpy.action import ActionServer
from rclpy.action.server import ServerGoalHandle


from py_objectdetection.detection_publisher import DetectionPublisher
from custom_interfaces.action import NavigationGoal
from custom_interfaces.srv  import SetDepth
from custom_interfaces.msg import WorldMap, MapObject, AABB, MotionGoal, DetectionBuffer, BoundingBox
from geometry_msgs.msg import Vector3, Quaternion
from builtin_interfaces.msg import Time
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
    
    isFinished          : bool
    
    _stage              : int

    _detectionBuffer    : DetectionBuffer

    _currentIMU         : Imu

    _currentImage       : Image

    def __init__(self, heading_topic : str, detection_topic : str, motion_goal_topic : str, image_topic : str):
        super().__init__("buoy_test_node")
        
        self._stage = 0

        self._motionGoalPublisher = self.create_publisher(MotionGoal,motion_goal_topic,5)

        self._sub_detbuff = self.create_subscription(DetectionBuffer,detection_topic,self.DetectionCallback,5)
        #self._depth_controller_client = self.create_client(SetDepth,)

        self._sub_imu = self.create_subscription(Imu,heading_topic,self.HeadingCallback,5)
        self._sub_image = self.create_subscription(Image, image_topic,self.ImageCallback,5)

        self.isFinished = False
        self._detectionBuffer = None
        self._currentIMU = None
        self._currentImage = None


        self._controlLoopTimer = self.create_timer(0.1, self.ControlLoop)




    def ControlLoop(self):
        detected, bbox = self.IsBuoyDetected()
        match self._stage:
            #case -1: ## go to depth 

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
                self.get_logger().info("Generating Lidar Map") 
                pass
            case 4: # Spin for a bit
                pass
            case 5: # Shutdown
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


def main(args = None):
    rclpy.init()

    # spin detection node for buoy, heading node is provided by realsense camera
    buoyDetector = DetectionPublisher(parameter_overrides=[rclpy.Parameter("name",value="buoy_detector"),rclpy.Parameter("model_path",value="models/dry_buoy.pt"),rclpy.Parameter("topic",value="camera/camera/color/image_raw")])

    buoyTestNode = SingleBuoyTest(heading_topic="camera/camera/imu",detection_topic="DetectionBuffer",motion_goal_topic="motors/MotionGoal", image_topic="camera/camera/color/image_raw")

    while not buoyTestNode.isFinished:
        try:
            rclpy.spin_once(buoyDetector)
            rclpy.spin_once(buoyTestNode)
        except SystemExit:
            rclpy.logging.get_logger("Quitting")
            rclpy.shutdown()
            return
    

    rclpy.shutdown()
    






if __name__ == '__main__':
    main()