'''
DItM_tester.py
"Depth Image to Map tester, does as the name implies

Ideally, this would be a part of a larger state machine / decision making algorithm


'''

import rclpy
from rclpy.node import Node
from rclpy import Future
from rclpy.callback_groups import MutuallyExclusiveCallbackGroup, ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor, ExternalShutdownException

import cv2
from cv_bridge import CvBridge

from custom_interfaces.srv import DetectionService, GenerateWorldMap
from custom_interfaces.msg import DetectionBuffer, WorldMap, AABB

from sensor_msgs.msg import Image



class DITMTester(Node):
    _depth_image : Image = None
    _detection_buffer : DetectionBuffer = None
    _fHasDepthImage : bool
    _cv_bridge : CvBridge

    def __init__(self):
        super().__init__('ditm_tester')

        self.declare_parameter('depth_image_topic','camera/camera/aligned_depth_to_color/image_raw')
        self.declare_parameter('detection_buffer_topic', 'DetectionBuffer')
        self._depth_image = None
        self._fHasDepthImage = False
        self._cv_bridge = CvBridge()

        self.parallel_group = ReentrantCallbackGroup()
        self.in_line_group = MutuallyExclusiveCallbackGroup()

        # subscribe to depth image stream and detection buffer stream. Put subscriptions on parallel threads so values can update irrespective of ROS's execution stack
        self.depth_image_sub = self.create_subscription(
            Image,
            self.get_parameter('depth_image_topic').get_parameter_value().string_value,
            self.depth_image_callback,
            5,
            callback_group= self.parallel_group
        )
        self.detection_buffer_sub = self.create_subscription(
            DetectionBuffer,
            self.get_parameter('detection_buffer_topic').get_parameter_value().string_value,
            self.detection_buffer_callback,
            5,
            callback_group= self.parallel_group
        )
        #self.detection_client = self.create_client(DetectionService, 'detection_service')
        self.map_client = self.create_client(GenerateWorldMap, 'generate_world_map')
        self.gwm_req = GenerateWorldMap.Request()


        # cv2.namedWindow("current_img",cv2.WINDOW_AUTOSIZE)
        cv2.namedWindow("initial_img",cv2.WINDOW_AUTOSIZE)

        """
            THERE IS AN ISSUE WHERE THE DEPTH IMAGE ISNT GATHERED BEFORE BEGIN CALL SERVICES IS CALLED,
            THIS MAKES THE DEPTH IMAGE ALWAYS NULL
            SOLUTION:
                FIND A WAY TO MAKE DEPTH IMAGE GATHERING ASYNCHRONOUS FROM SERVICE STUFF
        """

        while not self.map_client.wait_for_service(timeout_sec=2.5):
            self.get_logger().info("Waiting for generate_world_map service server...")

        self.timer = self.create_timer(1, self.map_generation_timer,self.in_line_group)




    def map_generation_timer(self):
        depth_image = self._depth_image
        detection_buffer = self._detection_buffer

        if (depth_image is None) or (detection_buffer is None):
            self.get_logger().info("no valid depth image and/or detection buffer...")
            return
        else:
            self.get_logger().info("valid depth image and detection buffer found, proceeding to map generation")
            self.gwm_req.depth_image = depth_image
            self.gwm_req.detections = detection_buffer

            future = self.map_client.call_async(self.gwm_req)
            future.add_done_callback(self.map_generated_callback)
            self.destroy_timer(self.timer)

    def map_generated_callback(self, future : Future):
        self.get_logger().info("map generation service ran successfully, attempting to read results")

        try:
            response = future.result()
            if(response.success):
                self.get_logger().info("map generation was successful")
        except Exception as e:
            self.get_logger().error(f"DItM_tester::mag_generated_callback() : ERROR : FAILED TO GET GENERATION RESULTS:\n{e}")   
            
    def depth_image_callback(self, msg):
        self.get_logger().info("depth_image_callback")
        self._depth_image = msg
        # img = self._cv_bridge.imgmsg_to_cv2(msg)
        # cv2.imshow("current_img",img)
        # cv2.waitKey(1)

    def detection_buffer_callback(self,msg):
        self.get_logger().info("detection_buffer_callback")
        self._detection_buffer = msg
    


    
def main():
    rclpy.init(args=None)
    node = DITMTester()
    executor = MultiThreadedExecutor()
    try:
        
        executor.add_node(node)
        executor.spin()

       
    except (KeyboardInterrupt,ExternalShutdownException):
        node.destroy_node()
        executor.shutdown()
        rclpy.shutdown()

   

    # node = DITMTester()

    # rclpy.spin(node)

    # node.destroy_node()
    
    # rclpy.shutdown()  

if __name__ == '__main__':
    main() 






    

      





