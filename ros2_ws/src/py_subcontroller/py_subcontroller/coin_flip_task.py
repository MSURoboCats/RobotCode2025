import math
import rclpy

from rclpy.node import Node

from py_objectdetection.detection_publisher import DetectionPublisher
from py_objectdetection.depth_image_to_map_o3d import DepthImageToMapNode

from py_motors.motor_conductor import MotorConductor
from py_motors.motor_controller import MotorController

from custom_interfaces.srv import SetDepth, SetHeading
from custom_interfaces.msg import MotionGoal, DetectionBuffer, BoundingBox, ImuData, HeadingResult

from sensor_msgs.msg import Image
from std_msgs.msg import String


"""
coin_flip_task.py responsible for completing the qualifying task of rotating the 
AUV and having it drive through a gate of our choosing
"""


class CoinFlipTask(Node):
    _PIXELS_PER_DEGREE      : tuple[float, float] = (640.0/90.0, 480.0/65.0)

    _DESIRED_DEPTH          : float = 1.0

    _stage                  : int


    # cached messages
    m_detectionBuffer       : DetectionBuffer
    m_currentImage          : Image
    m_headingResult         : HeadingResult
    m_currentIMU            : ImuData


    # flags

    f_waitingForDepth       : bool 
    f_depthReached          : bool
    f_swordfishDetected     : bool
    f_isAligningWithFish    : bool
    f_isFinished            : bool

    def __init__(self, detection_pub_topic, heading_cont_service : str, depth_cont_service : str, heading_goal_topic : str, depth_goal_topic : str, motion_goal_topic : str, image_topic : str, imu_topic : str):
        super().__init__("coin_flip_node")

        self._stage = 0

        self.f_waitingForDepth = False
        self.f_depthReached = False
        self.f_swordfishDetected = False
        self.f_isAligningWithFish = False
        self.f_isFinished = False

        self.m_detectionBuffer = None
        self.m_currentImage = None
        self.m_currentIMU = None

        self._depth_control_client = self.create_client(SetDepth,depth_cont_service)
        self._heading_control_client = self.create_client(SetHeading,heading_cont_service)

        self._sub_detection_buffer = self.create_subscription(DetectionBuffer,detection_pub_topic, self.DetectionBufferCallback,5)
        self._sub_depth_goal = self.create_subscription(String, depth_goal_topic, self.DepthGoalCallback,5)
        self._sub_heading_goal = self.create_subscription(HeadingResult,heading_goal_topic,self.HeadingGoalCallback,5)
        self._sub_image = self.create_subscription(Image, image_topic,self.ImageCallback,5)
        self._sub_imu = self.create_subscription(ImuData, imu_topic,self.IMUCallback,5)

        self._pub_motion_goal = self.create_publisher(MotionGoal,motion_goal_topic,5)

        self.main_loop = self.create_timer(0.1, self.StateMachine)

        



    def StateMachine(self):
        detected, bbox = self.IsSwordfishDetected()
        match self._stage:
            case 0:
                self.get_logger().info(f"Stage 1 {self.f_waitingForDepth}, {self.f_depthReached}")
                # Submerge to ~3 feet below surface 
                if(not self.f_waitingForDepth):
                    depth_request = SetDepth.Request()
                    depth_request.depth = self._DESIRED_DEPTH
                    self.f_waitingForDepth = True
                    self.f_depthReached = False
                    self._depth_control_client.call_async(depth_request)
                    self.get_logger().info(f"Attempting to submerge to depth {self._DESIRED_DEPTH}")

                elif self.f_depthReached:
                    self.get_logger().info("Desired depth reached! Proceeding to next stage...")
                    self.f_waitingForDepth = False
                    self._stage = 1
                    return

            case 1:
                # rotate until swordfish is found
                if(not detected):
                    outmsg = MotionGoal()
                    outmsg.goal = "y_le"
                    outmsg.keep_unmodified_throttles = True

                    self.get_logger().info("swordfish not detected, spinning")
                    self._pub_motion_goal.publish(outmsg)
                else: 
                    self._stage = 2
                    self.get_logger().info("swordfish detected, proceeding to next stage")
                    outmsg = MotionGoal()
                    outmsg.goal = "kill"

                    self._pub_motion_goal.publish(outmsg)
                pass
            case 2: 
                #align with swordfish
                self.get_logger().info("Aligning with swordfish")
                if detected:
                    centered, distance = self.IsSwordfishCentered(bbox)


                    if(not centered and not self.f_isAligningWithFish):
                        angularDistance = (distance * (1.0 / self._PIXELS_PER_DEGREE[0])) * (math.pi / 180.0)
                        
                        heading_request = SetHeading.Request()

                        currentEuler = self.m_currentIMU.euler_angles

                        desired_euler = [currentEuler.x + angularDistance, currentEuler.y, currentEuler.z]

                        heading_request.heading = desired_euler

                        heading_request.keep_heading_until_override = True

                        self._heading_control_client.call_async(heading_request)

                        self.f_isAligningWithFish = True
                    elif centered:
                        self.f_isFinished = True
                        return
            case 3:
                pass
                
                        


    def IsSwordfishCentered(self, bbox : BoundingBox, pixelTolerance : int = 10) -> tuple[bool, float]:
        if(self.m_currentImage is None):
            self.get_logger().warning("CoinFlipTask::IsSwordfishCentered() : Warning! node lacks image")
            return (False, None)
        else:
            camCenterX = self.m_currentImage.width / 2

            dX = bbox.center_x - camCenterX

            within : bool = False

            if( abs(dX) < pixelTolerance / 2):
                within = True
            return(within,dX)

    def IsSwordfishDetected(self) -> tuple[bool, BoundingBox]:
        if self.m_detectionBuffer is None:
            return (False, None)
        
        for bbox in self.m_detectionBuffer.detections:
            if bbox.name == "swordfish":
                return (True, bbox)
        return (False, None)


    def ImageCallback(self, msg):
        self.m_currentImage = msg          

    def HeadingGoalCallback(self, msg):
        self.m_headingResult = msg

    def DepthGoalCallback(self, msg):
        self.f_depthReached = True
    
    def DetectionBufferCallback(self, msg):
        self.m_detectionBuffer = msg
    
    def IMUCallback(self, msg):
        self.m_currentIMU = msg


## needed: launch_pid_tuning, realsense ros camera, launch heading_pid_tuning, imu sensor with remap

def main(args = None):
    rclpy.init()

    detectorNode = DetectionPublisher(parameter_overrides=[rclpy.Parameter("name",value="buoy_detector"),rclpy.Parameter("topic",value="camera/camera/color/image_raw")])

    taskNode = CoinFlipTask(
        detection_pub_topic="DetectionBuffer",
        heading_cont_service="heading_pid_tuning/set_heading",
        depth_cont_service="pid_tuning/set_depth",
        heading_goal_topic="heading_pid_tuning/heading_goal_status",
        depth_goal_topic="pid_tuning/depth_status",
        motion_goal_topic="pid_tuning/MotionGoal",
        image_topic="camera/camera/color/image_raw",
        imu_topic="heading_pid_tuning/imu"
    )


    while not taskNode.f_isFinished:
        try:
            rclpy.spin_once(detectorNode)
            rclpy.spin_once(taskNode)
        except SystemExit:
            print("Quitting")
            break
    
    rclpy.shutdown()


if __name__ == '__main__':
    main()
