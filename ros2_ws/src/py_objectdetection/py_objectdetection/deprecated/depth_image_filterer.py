'''
[DEPRECATED]
depth_image_filterer.py

Responsible for taking bounding rectangles generated through object detection, and turning them into 3d points
'''

# use points3d = cv2.rgbd.depthTo3D(depth_image, k)



from custom_interfaces.msg import BoundingBox, DetectionBuffer
from geometry_msgs.msg import Polygon, Point32, Point
from sensor_msgs.msg import Image, CameraInfo

from custom_interfaces.action import DetectionAction

import cv2
from cv_bridge import CvBridge

import numpy as np

import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer

class BBoxFilterService(Node):
    _cv_bridge  : CvBridge
    def __init__(self):
        self.declare_parameter("action_name","bbox_filter_action")
        
        name = self.get_parameter("action_name").get_parameter_value().string_value

        super().__init__(name)
        self.action = ActionServer(
            self,
            DetectionAction,
            name,
            self.service_callback
        )
        self._cv_bridge = CvBridge()

    def service_callback(self, goal_handle):

        depth_image : Image = goal_handle.request.depth_image
        camera_info : CameraInfo = goal_handle.request.camera_info
        detections  : DetectionBuffer = goal_handle.request.detections


        # mask depth image to include only detections (we want the rest of the image outside of the bboxes to be black)
        ## construct mask out of bounding boxes

        ### create black image of width and height of the depth image
        mask = np.zeros((depth_image.height,depth_image.width,3), dtype=np.uint8)

        for bbox in detections.detections:
            p1 = (bbox.center_x - bbox.width/2,bbox.center_y - bbox.height/2)
            p2 = (bbox.center_x + bbox.width/2,bbox.center_y + bbox.height/2)
            
            color = (255,255,255)
            mask = cv2.rectangle(mask,p1,p2,color,-1)
        
        result = cv2.bitwise_and(depth_image,depth_image,mask=mask)

        cv2.imshow("mask",mask, cv2.WINDOW_KEEPRATIO)
        cv2.imshow("mask_result", result, cv2.WINDOW_KEEPRATIO)

        goal_handle.publish_feedback(self._cv_bridge.cv2_to_imgmsg(mask))
        

        ## convert ros2 camera_info.k to numpy matrix 
        ## use cv2.rgbd.depthTo3d to convert resulting depth image to 3d point cloud
        k_raw = camera_info.k

        np_k_matrix = np.array([k_raw[0],k_raw[1],k_raw[2]],[k_raw[3],k_raw[4],k_raw[5]],[k_raw[6],k_raw[7],k_raw[8]])

        pointCloud = cv2.rgbd.depthTo3d(result,np_k_matrix)

        print(pointCloud)

        result = DetectionAction.Result()
 

        

        

        



        

def main():
    rclpy.init()

    node = BBoxFilterService()

    rclpy.spin(node)

    rclpy.shutdown()

if __name__ == '__main__':
    main()

        

            








