import math

import rclpy
import rclpy.logging
from rclpy.node import Node
from rclpy.action import ActionServer
from rclpy.action.server import ServerGoalHandle


from py_objectdetection.detection_publisher import DetectionPublisher
from custom_interfaces.action import NavigationGoal
from custom_interfaces.msg import WorldMap, MapObject, AABB, MotionGoal, DetectionBuffer, BoundingBox
from geometry_msgs.msg import Vector3, Quaternion
from builtin_interfaces.msg import Time
from sensor_msgs.msg import Imu, Image
from std_msgs.msg import Header


def IsNewData(original : Header, compare : Header) -> bool:
    isOriginalInvalid = original.frame_id == "-1"

    if(isOriginalInvalid): return True

    hasDiffFrameID = original.frame_id != compare.frame_id

    hasNewerTimestamp = (compare.stamp.sec > original.stamp.sec) or ( (compare.stamp.sec == original.stamp.sec) and compare.stamp.nanosec > original.stamp.nanosec)

    return hasDiffFrameID and hasNewerTimestamp

# class Navigator(Node):
#     m_cachedIMU : Imu
#     m_cachedMap : WorldMap

#     def __init__(self):
#         super().__init__('navigator')
#         self.declare_parameter("imu_topic", "camera/camera/imu")
#         self.declare_parameter("world_map_topic", "WorldMap")
#         self.declare_parameter("action_server_name", "navigation_goal")
#         self.declare_parameter("detection_service_name","detection_service")
        
#         self.m_cachedIMU = Imu()
#         self.m_cachedMap = WorldMap()
        
#         self.m_cachedMap.header.frame_id = "-1"
#         self.m_cachedIMU.header.frame_id = "-1"

#         self.sub_worldMap = self.create_subscription(
#             WorldMap,
#             self.get_parameter("world_map_topic").get_parameter_value().string_value,
#             self.WorldMapCallback,
#             3
#         )

#         self.sub_imu = self.create_subscription(
#             Imu,
#             self.get_parameter("imu_topic").get_parameter_value().string_value,
#             self.IMUCallback,
#             3
#         )

#         self.detection_client = self.create_client(DetectionService,self.get_parameter("detection_service_name").get_parameter_value().string_value)

#         self._actionServer = ActionServer(
#             self,
#             NavigationGoal,
#             self.get_parameter('action_server_name').get_parameter_value().string_value,
#             self.ExecutionCallback
#         )

#     def ExecutionCallback(self, goal_handle: ServerGoalHandle):
#         request : str = goal_handle.request.goal; 

#         self.get_logger().info(f"Goal Recieved: {request}, {type(goal_handle)}")

#         result = NavigationGoal.Result()


#         match request.lower():
#             case 'buoy_test':
#                 self.get_logger().info("Performing Buoy Test...")
#                 self.DoBuoyTest(result)
#             case _:
#                 self.get_logger().warning(f"Navigator::ExecutionCallback() : Warning! Unrecognized Navigation Goal: {request}")
#                 result.success = False



#         return result


#     def WorldMapCallback(self, msg : WorldMap):
#         if (IsNewData(self.m_cachedMap.header,msg.header)) : 
#             self.m_cachedMap = msg
        
#     def IMUCallback(self, msg : Imu):
#         if(IsNewData(self.m_cachedIMU.header, msg.header)) : 
#             self.m_cachedIMU = msg


#     def DoBuoyTest(self, result : NavigationGoal.Result):
#         #1 yaw left until buoy found 
#         #2 once found align self with buoy 
#         #3 move until lidar can be used reliably (buoy takes up certain portion of screen)
#         #4 move to within .6 meters then spin

#         if not self.detection_client.wait_for_service(timeout_sec = 1.0):
#             self.get_logger().error(f"ERROR : Navigator::DoBuoyTest() : MISSING DETECTION SERVICE \"{self.get_parameter("detection_service_name").get_parameter_value().string_value}\"")
#             result.success = False
#             return
        
#         request = DetectionService.Request()

#         future = self.detection_client.call_async(request)

#         while rclpy.ok
        
#     def 
        
        

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
        self._sub_imu = self.create_subscription(Imu,heading_topic,self.HeadingCallback,5)
        self._sub_image = self.create_subscription(Image, image_topic,self.ImageCallback,5)

        self.isFinished = False
        self._detectionBuffer = None
        self._currentIMU = None
        self._currentImage = None


        self._controlLoopTimer = self.create_timer(0.1, self.ControlLoop)




    def ControlLoop(self):
        match self._stage:
            case 0: # rotate until buoy detected
                if (not self.IsBuoyDetected()[0]):
                    outmsg = MotionGoal()
                    outmsg.goal = "y_le"
                    self._motionGoalPublisher.publish(outmsg)
                    self.get_logger().info("buoy not detected, spinning..")
                else:
                    self._stage = 1
                    self.get_logger().info("buoy detected, proceeding to stage 1")

                pass
            case 1: # align with buoy
                self.get_logger().info("Aligning with buoy")

                detected, bbox = self.IsBuoyDetected()

                if detected:
                    centered, distance = self.isBBoxCentered(bbox)

                    if centered: 
                        self.get_logger().info("buoy is centered, proceeding to stage 2")
                        self._stage = 2
                        return
                    else:
                        self.get_logger().warning(f"SingleBuoyTest::ControlLoop() : Buoy is not centered (distance = {distance}), please correct me!")
                        pass
                        



                pass
            case 2: # move within LIDAR range
                pass
            case 3: # do something with lidar map (eg display)
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
    buoyDetector = DetectionPublisher(name='buoy_detector',model_path="models/dry_buoy.pt",image_stream_topic="camera/camera/color/image_raw")

    buoyTestNode = SingleBuoyTest(heading_topic="camera/camera/imu",detection_topic="DetectionBuffer",motion_goal_topic="MotionGoal", image_topic="camera/camera/color/image_raw")

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