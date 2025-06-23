import rclpy
import cv2
import cv_bridge


from rclpy.node import Node
from custom_interfaces.msg import BoundingBox
from sensor_msgs.msg import Image as ros2_img

from ultralytics import YOLO
from cv_bridge import CvBridge


class DetectionPublisher(Node):
    _model      : YOLO
    _path       : str
    _task       : str
    _cvBridge   : CvBridge
    def __init__(self):
        super().__init__('detection_publisher')
        self.declare_parameter("model_path", "ultralyticsplus/yolov8s")
        self.declare_parameter("task", "detect")


        self._path = self.get_parameter("model_path").get_parameter_value().string_value
        self._task = self.get_parameter("task").get_parameter_value().string_value


        self._cvBridge = CvBridge()
        self._model = YOLO(self._path,self._task,True)

    
        self._model.overrides['conf'] = 0.25  # NMS confidence threshold
        self._model.overrides['iou'] = 0.45  # NMS IoU threshold
        self._model.overrides['agnostic_nms'] = False  # NMS class-agnostic
        self._model.overrides['max_det'] = 1000  # maximum number of detections per image

        self.publisher_ = self.create_publisher(BoundingBox,'bbox',5)

        self.subscription_ = self.create_subscription(ros2_img,'usb_cam_0/image_raw',self.publisher_callback,5)
        
        cv2.namedWindow("detection_publisher",cv2.WINDOW_KEEPRATIO)
        cv2.resizeWindow("detection_publisher",640,480)



    # reads image from usb_cam, might need to update to reading directly from the device (/dev/video*) for performance purposes 
    def publisher_callback(self, image : ros2_img):

        cv_image = self._cvBridge.imgmsg_to_cv2(image)
        cv_image = cv2.flip(cv_image,0)
        cv_image = cv2.cvtColor(cv_image,cv2.COLOR_BGR2RGB)



        # results = self._model(cv_image)


        # for i in range(len(results)):
        #     for j in range(len(results[i].boxes)):
        #         print(results[i].boxes[j])

               
        #         xywh = results[i].boxes[j].xywh
                
        #         p1 = (int(xywh[0][0]), int(xywh[0][1]))
        #         p2 = (int(p1[0] + xywh[0][2]), int(p1[1] + xywh[0][3]))
        #         cv_image = cv2.rectangle(cv_image,p1,p2,(255,0,0),2)
        #         cv_image = cv2.putText(cv_image,results[i].names[j],p1,cv2.FONT_HERSHEY_PLAIN,1,(255,0,0),1)
        #         print("########\n")
        #     print("------\n")
        
        cv2.imshow("detection_publisher",cv_image)
        cv2.waitKey(100)
            

def main(args=None):
    rclpy.init(args=args)
    detector = DetectionPublisher()
    
    rclpy.spin(detector)

    detector.destroy_node()

    rclpy.shutdown()

if __name__ == '__main__':
    main()
        
        
        



        