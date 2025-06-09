import cv2

from cv_bridge import CvBridge

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image


class VideoPublisher(Node):
    FRAME_RATE = 0.625 
    def __init__(self):
        super().__init__("video_publisher")
        
        self.declare_parameter("usb_port", 0) # the usb port the camera corresponds to in /dev/video (default = video0)
        
        self.port = self.get_parameter("usb_port").get_parameter_value()._integer_value

        self.captureObj = cv2.VideoCapture(self.port)

        if not self.captureObj.isOpened():
            self.get_logger().error("ERROR: COULD NOT FIND CAMERA AT /dev/video%d\n REFUSING TO PUBLISH" % self.port)
        else:
            self.cvBridge = CvBridge()
            #create a video frame publisher with a 5 frame buffer
            self.publisher_ = self.create_publisher(Image,"video_frame",5)
            #have the publisher publish images every FRAME_RATE seconds
            self.timer = self.create_timer(self.FRAME_RATE, self.publisher_callback)
            

            
    def publisher_callback(self):

        #read frame from camera
        success, frame_data = self.captureObj.read()

        if success == True:    
            self.publisher_.publish(self.cvBridge.cv2_to_imgmsg(frame_data))
        else:
            self.get_logger().warning("Failed to read frame from camera on port /dev/video%d" % self.port)

def main(args=None):
    rclpy.init(args=args)

    vid_pub = VideoPublisher()

    rclpy.spin(vid_pub)

    vid_pub.captureObj.release()
    vid_pub.destroy_node()
    
    rclpy.shutdown()



        
        