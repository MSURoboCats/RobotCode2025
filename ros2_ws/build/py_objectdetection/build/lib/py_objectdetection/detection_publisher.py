import rclpy
import cv2
import os
import cv_bridge



from rclpy.node import Node
from custom_interfaces.msg import BoundingBox
from custom_interfaces.msg import DetectionBuffer
from custom_interfaces.srv import DetectionService
from sensor_msgs.msg import Image as ros2_img

from ultralytics import YOLO
from cv_bridge import CvBridge

def buildmodel(path : str, task : str) -> YOLO:
    # check if file is valid
    if(not os.path.isfile(path)): 
        print(f"File path \"{path}\" does not point to a valid file! returning")
        return None
    # check if trtmodel exists at path
    split = path.split("/")

    ext = split[len(split) - 1].split(".")[1]

    split[len(split) - 1] = split[len(split) - 1].replace("." + ext,".engine")
    
    nPath = "/".join(split)
    # if a trt model exists, return that
    if(os.path.isfile(nPath)):
        print("trt model \"" + split[len(split) -1] + "\" already exists, using that instead...")
        return YOLO(nPath,task)
    
    # otherwise build the trt model
    print("could not find existing TRT model, building new (this might take a while)...")

    tempMdl = YOLO(path, task)

    tempMdl.export(format = "engine")

    print("model built and exported, file is stored at: " + nPath)

    return YOLO(nPath,task,False)







    
    




class DetectionPublisher(Node):
    _model              : YOLO
    _path               : str
    _task               : str
    _topic              : str
    _filter             : str
    _cvBridge           : CvBridge
    _frameNumber        : int
    _lastFrameCapture   : DetectionBuffer
    def __init__(self, **kwargs):
        super().__init__('detection_publisher', **kwargs)
        self.declare_parameter("model_path", "ultralyticsplus/yolov8s.pt")
        self.declare_parameter("task", "detect")
        self.declare_parameter("topic","usb_cam_0/image_raw")
        self.declare_parameter("filter", "all")

        self.declare_parameter("detection_service_name","detection_service")


        self._path = self.get_parameter("model_path").get_parameter_value().string_value
        self._task = self.get_parameter("task").get_parameter_value().string_value
        self._topic = self.get_parameter("topic").get_parameter_value().string_value
        self._filter = self.get_parameter("filter").get_parameter_value().string_value


        self._cvBridge = CvBridge()

        self._model = buildmodel(self._path,self._task) 

    
        
        self.publisher_ = self.create_publisher(DetectionBuffer,'DetectionBuffer',1)

        self.subscription_ = self.create_subscription(ros2_img,self._topic,self.publisher_callback,5)

        self._frameNumber = 0

        self._detection_service = self.create_service(DetectionService,self.get_parameter("detection_service_name").get_parameter_value().string_value,self.get_current_detection_buffer)


        cv2.namedWindow("detection_publisher",cv2.WINDOW_KEEPRATIO)
        cv2.resizeWindow("detection_publisher",640,480)

    # def __init__(self, name : str = 'detection_publisher', model_path : str ="ultralyticsplus/yolov8s.pt", image_stream_topic : str = "usb_cam_0/image_raw", task : str = "detect", filter : str = "all"):
    #     super().__init__(name)

    #     self.declare_parameter("detection_service_name","detection_service")


    #     self._path = model_path
    #     self._task = task
    #     self._topic = image_stream_topic
    #     self._filter = filter


    #     self._cvBridge = CvBridge()

    #     self._model = buildmodel(self._path,self._task) 

    
        
    #     self.publisher_ = self.create_publisher(DetectionBuffer,'DetectionBuffer',1)

    #     self.subscription_ = self.create_subscription(ros2_img,self._topic,self.publisher_callback,5)

    #     self._frameNumber = 0

    #     self._detection_service = self.create_service(DetectionService,self.get_parameter("detection_service_name").get_parameter_value().string_value,self.get_current_detection_buffer)


    #     cv2.namedWindow("detection_publisher",cv2.WINDOW_KEEPRATIO)
    #     cv2.resizeWindow("detection_publisher",640,480)



    def get_current_detection_buffer(self, request, response):

        response.detections = self._lastFrameCapture
        self.get_logger().info("Detection_Publisher::detection_service() : returning last frame capture")

        return response

        




    # reads image from camera source 
    def publisher_callback(self, image : ros2_img):

        cv_image = self._cvBridge.imgmsg_to_cv2(image)
        cv_image = cv2.flip(cv_image,0)
        cv_image = cv2.cvtColor(cv_image,cv2.COLOR_BGR2RGB)

        results = self._model(cv_image)


        bboxes = []


        for i in range(len(results)):
            for box in results[i].boxes :
                #print(str(box))
                if(float(box.conf) < 0.75): 
                    continue

               
                xywh = box.xywh
                name = results[i].names[int(box.cls)]

                if(self._filter == "all" or name == self._filter):
                    bbox = BoundingBox()
                    bbox.name       = str(name)
                    bbox.width      = int(xywh[0][2])
                    bbox.height     = int(xywh[0][3])
                    bbox.center_x   = int(xywh[0][0])
                    bbox.center_y   = int(xywh[0][1])
                    bbox.conf       = float(box.conf)
                    bboxes.append(bbox) 


                
                # print(str(xywh))

                p1 = (int(xywh[0][0] - xywh[0][2] * 0.5), int(xywh[0][1] - xywh[0][3] * 0.5))
                p2 = (int(xywh[0][0] + xywh[0][2] * 0.5), int(xywh[0][1] + xywh[0][3] * 0.5))
                cv_image = cv2.rectangle(cv_image,p1,p2,(255,0,0),2)
                cv_image = cv2.putText(cv_image, f"{bbox.name}, conf: {bbox.conf:.2f}\n wxh: {bbox.width}x{bbox.height}",p1,cv2.FONT_HERSHEY_PLAIN,1,(255,0,0),1)
                
                # print("########\n")
            # print("------\n")
        
        out = DetectionBuffer()

        out.detections = bboxes

        self.publisher_.publish(out)

        self._lastFrameCapture = out



        self.get_logger().info("publishing bounding box buffer",)

        cv_image = cv2.putText(cv_image,"frame #" + str(self._frameNumber),(0,12),cv2.FONT_HERSHEY_PLAIN,1.0, (100,0,150),1)

        self._frameNumber += 1

        cv2.imshow("detection_publisher",cv_image)
        cv2.waitKey(1)
            

def main(args=None):
    rclpy.init(args=args)
    detector = DetectionPublisher()
    
    rclpy.spin(detector)

    detector.destroy_node()

    rclpy.shutdown()

if __name__ == '__main__':
    main()
        
        
        



        