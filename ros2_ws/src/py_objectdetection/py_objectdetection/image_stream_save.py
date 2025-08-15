import cv2
import os
import rclpy
import cv_bridge

import time 
import datetime

from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge




class ImageStreamSubscriber(Node):

    _cvBridge   : CvBridge

    _frameNumber : int

    _outputFolder : str


    def __init__(self, **kwargs):
        super().__init__('image_stream_subscriber', **kwargs)

        self.declare_parameter("image_stream_topic", "camera/camera/color/image_raw")


        self._sub = self.create_subscription(
            Image,
            self.get_parameter("image_stream_topic").get_parameter_value().string_value,
            self.ImageStreamCallback,
            5
        )

        self._frameNumber = 0
        self._cvBridge = CvBridge()

        cDir = os.getcwd()

        cTime = time.gmtime()

        baseDirectory = cDir[0:cDir.find("ros2_ws")] + "ros2_ws/image_capture"


        self._outputFolder = baseDirectory + f"/captures_{cTime.tm_mon}_{cTime.tm_mday}/"

        if not os.path.isdir(self._outputFolder):
            os.makedirs(self._outputFolder,exist_ok=True)
            print("creating required directories...")

        print(f"Files will be saved at \"{self._outputFolder}\"")



    def ImageStreamCallback(self, image_msg):

        # read image message, convert it to cv2 image, and apply transformations to ensure correct orientation and colorspace
        frame = self._cvBridge.imgmsg_to_cv2(image_msg)
        frame = cv2.flip(frame, -1) 
        frame = cv2.cvtColor(frame,cv2.COLOR_BGR2RGB)

        # save frame to output folder
        save_time = time.gmtime()
        timestamp = f"{save_time.tm_hour}_{save_time.tm_min}_{save_time.tm_sec}"
        
        filename = self._outputFolder + timestamp


        frame_no = 0

        full_path = filename + f"_{frame_no}.png"

        while(os.path.exists(full_path)):
            frame_no += 1
            full_path = filename + f"_{frame_no}.png"



        cv2.imwrite(full_path,frame) 




def main(args=None):
    try:
        rclpy.init(args = args)
        
        image_str_sub = ImageStreamSubscriber()

        rclpy.spin(image_str_sub)

    except KeyboardInterrupt:
        pass
    
    finally:
        rclpy.shutdown()

        print(f"exit finished, files saved to \"{image_str_sub._outputFolder}\"")

if __name__ == '__main__':
    main()
        








        
