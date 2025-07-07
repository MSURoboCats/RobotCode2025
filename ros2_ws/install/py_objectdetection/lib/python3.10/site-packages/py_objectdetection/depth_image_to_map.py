import open3d.visualization
import rclpy
from rclpy.node import Node

import cv2
from cv_bridge import CvBridge

import numpy as np



from custom_interfaces.msg import AABB, WorldMap, BoundingBox, DetectionBuffer 
from custom_interfaces.srv import GenerateWorldMap

from sensor_msgs.msg import Image, CameraInfo
from geometry_msgs.msg import Point32 as ros2_pt32
from geometry_msgs.msg import Vector3 as ros2_v3
from geometry_msgs.msg import Polygon as ros2_poly


class Mesh:
    name   : str
    points : list[ros2_pt32] = list()
    np_points : np.ndarray

    def __init__(self, points : list[ros2_pt32] = list(), name : str = ""):
        self.points = points
        self.name = name
    def to_polygon(self) -> ros2_poly:
        outpoly = ros2_poly()
        outpoly.points = self.points

        return outpoly


class DepthImageToMapNode(Node):
    _camera_info        : CameraInfo
    _detection_buffer   : DetectionBuffer
    _depth_image        : Image
    _cv_bridge          : CvBridge
    _map_cache          : WorldMap

    def __init__(self):
        super().__init__('depth_image_to_map')
        self.declare_parameter('camera_info_topic','camera/camera/aligned_depth_to_color/camera_info')
        self.declare_parameter('depth_image_topic','camera/camera/aligned_depth_to_color/image_raw')
        self.declare_parameter('detection_buffer_topic', 'DetectionBuffer')
        self.declare_parameter('published_topic_name', 'WorldMap')
        self.declare_parameter('publish_rate_seconds',0.5)

        self._camera_info = None
        self._detection_buffer = None
        self._depth_image = None
        self._map_cache = None

        self._info_subscription = self.create_subscription(
            CameraInfo,
            self.get_parameter('camera_info_topic').get_parameter_value().string_value,
            self.camera_info_callback,
            5
        )
        self.depth_image_sub = self.create_subscription(
            Image,
            self.get_parameter('depth_image_topic').get_parameter_value().string_value,
            self.depth_image_callback,
            5,
        )
        self.detection_buffer_sub = self.create_subscription(
            DetectionBuffer,
            self.get_parameter('detection_buffer_topic').get_parameter_value().string_value,
            self.detection_buffer_callback,
            5,
        )


        cv2.namedWindow("depth_image",cv2.WINDOW_AUTOSIZE)
        cv2.namedWindow("mask result",cv2.WINDOW_AUTOSIZE)
        self._info_subscription
        self._cv_bridge = CvBridge()

        self._publisher = self.create_publisher(WorldMap,self.get_parameter('published_topic_name').get_parameter_value().string_value,1)
        self.create_timer(self.get_parameter('publish_rate_seconds').get_parameter_value().double_value,self.map_publisher_callback)
        
        # pyvista initialization
       



    def camera_info_callback(self, msg):
        self._camera_info = msg

    def depth_image_callback(self, msg):
        self._depth_image = msg

    def detection_buffer_callback(self, msg):
        self._detection_buffer = msg
    
    def lacks_required_info(self) -> bool:
        return ((self._camera_info is None) or (self._depth_image is None) or (self._detection_buffer is None)) 

    def map_publisher_callback(self):
        if (self._map_cache is None):
            self.get_logger().info("depth_image_to_map lacks cached instance of WorldMap. Generating new world map...")
            self.generate_new_map()
        else:
            self._publisher.publish(self._map_cache)
            self.get_logger().info("Publishing map info")


    def generate_new_map(self):
        if self.lacks_required_info():
            self.get_logger().warning("Warning : depth_image_to_map::generate_new_map() lacks required map info! Refusing to generate map...")
            return

        # convert depth image to cv image
        depth_image = self._cv_bridge.imgmsg_to_cv2(self._depth_image)

        # validate depth image 
        is_blank = not ((float(depth_image.max()) != 0.0 ) or (float(depth_image.min() != 0.0)))

        if(is_blank):
            self.get_logger().warning("Warning : depth_image_to_map::generate_new_map() : depth image is invalid! Refusing to generate map...")
            return
        
        cv2.imshow("depth_image",depth_image)

        cv2.waitKey(1)

        # begin masking process

        mask = np.zeros(depth_image.shape[:2],dtype=np.uint8)

        d_buffer = self._detection_buffer.detections

        mesh_list : list[Mesh] = list()

        for bounds in d_buffer:
            # add rectangle to mask and store result in new image
            # this preserves the original mask and allows us to seperate point clouds more easily

            p1 = (int(bounds.center_x - (bounds.width / 2)), int(bounds.center_y - (bounds.height / 2)))
            p2 = (int(bounds.center_x + (bounds.width / 2)), int(bounds.center_y + (bounds.height / 2)))
            color = (255,255,255)

            object_mask = cv2.rectangle(mask,p1,p2,color,-1)

            # apply mask to image, store in seperate image, and create a mesh

            image_result = cv2.bitwise_and(depth_image,depth_image,mask=object_mask)
            cv2.imshow("mask result",image_result)
            cv2.waitKey(1)

            mesh_result = self.generate_mesh(image_result,bounds.name)

            if(mesh_result is None):
                self.get_logger().warning("Warning: no mesh produced from depth mask")
                continue
            else:
                mesh_list.append(mesh_result)

        #TODO: Filter meshes for invalid / empty meshes (point_radius smaller than certain threshold)

        poly_list : list[ros2_poly] = list()

        for mesh in mesh_list:
            poly_list.append(mesh.to_polygon())

        self.get_logger().info("Mesh list has been generated, adding meshes to world map...")
        self._map_cache = WorldMap()
        self._map_cache.meshes = poly_list

        cv2.destroyWindow("mask result")
        cv2.destroyWindow("depth_image")
        self.get_logger().info("Map Generated Succesfully!")



        
               

               
    def generate_mesh(self, img, name : str) -> Mesh:
        # print("img og values")
        # print(f"max: {img.max()}, min: {img.min()}, shape: {img.shape}")
        # print(img)

        img = img.astype(np.float32) / 1000.0

        # print("img new values")
        # print(f"max: {img.max()}, min: {img.min()}, shape: {img.shape}")

        # print(img)
        

        # print("Image dtype: ")
        # print(img.dtype)

        k_raw = self._camera_info.k


        # print("raw k matrix:")
        # print(k_raw)
        fx = self._camera_info.k[0]
        cx = self._camera_info.k[2]
        fy = self._camera_info.k[4]
        cy = self._camera_info.k[5]
        np_k_matrix = np.array([[fx, 0, cx],
                                [0, fy, cy], 
                                [0, 0, 1]], dtype=np.float64)

        # print("np_k_matrix")
        # print(np_k_matrix)

        mesh_points = cv2.rgbd.depthTo3d(img,np_k_matrix)
        # print("mesh points:")
        # print(f"max: {mesh_points.max()}, min: {mesh_points.min()}")
        # print(mesh_points)

        outmesh : Mesh = None 

        pt_list : list[ros2_pt32] = list()

        # print(f"array dimension:{mesh_points.shape} ")
        for x in mesh_points:
            for y in x:
                if (y[0] == y[1] and y[0] ==y[2]) and (y[0] == 0 or y[0] == -0):
                    continue
                point = ros2_pt32()
                point.x = float(y[0])
                point.y = float(y[1])
                point.z = float(y[2])

                pt_list.append(point)
        
        
        # print(f"num points: {len(pt_list)}")
        np_points = np.ndarray((len(pt_list),3),np.float64)

        i = 0
        for point in pt_list:
            np_points[i][0] = point.x
            np_points[i][1] = point.y
            np_points[i][2] = point.z
            i += 1 
        outmesh = Mesh(pt_list,name)

        outmesh.np_points = np_points


        return outmesh


   

            
def main():
    rclpy.init()

    node = DepthImageToMapNode()

    rclpy.spin(node)

    rclpy.shutdown()
    

if __name__ == '__main__':
    main()
    

