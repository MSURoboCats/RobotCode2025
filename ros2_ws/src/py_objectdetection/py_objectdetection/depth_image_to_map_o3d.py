import time
import rclpy
from rclpy.node import Node
import cv2
from cv_bridge import CvBridge

import numpy as np
import open3d as o3d
import math

from custom_interfaces.msg import AABB, WorldMap, BoundingBox, DetectionBuffer, MapObject 
from custom_interfaces.srv import GenerateWorldMap

from std_msgs.msg import Header
from sensor_msgs.msg import Image, CameraInfo
from geometry_msgs.msg import Point32 as ros2_pt32
from geometry_msgs.msg import Vector3 as ros2_v3
from geometry_msgs.msg import Polygon as ros2_poly

# class Mesh:
#     name   : str
#     points : list[ros2_pt32] = list()
#     np_points : np.ndarray

#     def __init__(self, points : list[ros2_pt32] = list(), name : str = ""):
#         self.points = points
#         self.name = name
#     def to_polygon(self) -> ros2_poly:
#         outpoly = ros2_poly()
#         outpoly.points = self.points

#         return outpoly

#cropBox = o3d.geometry.AxisAlignedBoundingBox([])

class DepthImageToMapNode(Node):
    _camera_info        : CameraInfo
    _detection_buffer   : DetectionBuffer
    _depth_image        : Image
    _cv_bridge          : CvBridge
    _map_cache          : WorldMap
    _map_id             : int
    _o3d_obj_list       : list
    


    def __init__(self, **kwargs):
        super().__init__("depth_image_to_map", **kwargs)
        self.declare_parameter('camera_info_topic','camera/camera/aligned_depth_to_color/camera_info')
        self.declare_parameter('depth_image_topic','camera/camera/aligned_depth_to_color/image_raw')
        self.declare_parameter('extrinsics_topic','camera/camera/extrinsics/depth_to_color')
        self.declare_parameter('detection_buffer_topic', 'DetectionBuffer')
        self.declare_parameter('published_topic_name', 'WorldMap')
        self.declare_parameter('publish_rate_seconds',0.25) # rate at which the map is updated and published
        self.declare_parameter('debug_enabled', False)
        
        self._camera_info = None
        self._detection_buffer = None
        self._depth_image = None
        self._map_cache = None
        self._map_id = 0
        self._o3d_obj_list = list()

        self._cv_bridge = CvBridge()

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
        self._publisher = self.create_publisher(WorldMap,self.get_parameter('published_topic_name').get_parameter_value().string_value,1)
        self._publisher_timer = self.create_timer(self.get_parameter('publish_rate_seconds').get_parameter_value().double_value,self.map_publisher_callback)
        if (self.get_parameter('debug_enabled').get_parameter_value().bool_value == True): self.create_timer(0.125,self.draw_map_callback)

    def draw_map_callback(self):
        if(self._o3d_obj_list.__len__() <= 0): return
        else:
            o3d.visualization.draw(self._o3d_obj_list, "Generated Map")


    def camera_info_callback(self, msg):
        self._camera_info = msg

    def depth_image_callback(self, msg):
        self._depth_image = msg

    def detection_buffer_callback(self, msg):
        self._detection_buffer = msg
    
    def lacks_required_info(self) -> bool:
        return ((self._camera_info is None) or (self._depth_image is None) or (self._detection_buffer is None)) 


    def map_publisher_callback(self):
        #  if (self._map_cache is None):
        #     self.get_logger().info("depth_image_to_map lacks cached instance of WorldMap. Generating new world map...")
           
        # else:
        #     self._publisher.publish(self._map_cache)
        #     self.get_logger().info("Publishing map info")

        self.generate_new_map()

        if(self._map_cache is None):
            self.get_logger().info("depth_image_to_map lacks cached instance of WorldMap! Waiting for instance to be generated...")
            return
        self._publisher.publish(self._map_cache)
        self.get_logger().info("Publishing map info")

    def generate_new_map(self):
        if self.lacks_required_info():
            self.get_logger().warning("Warning : depth_image_to_map::generate_new_map() lacks required map info! Refusing to generate map...")
            return

        # convert depth image to cv image
        depth_image = self._cv_bridge.imgmsg_to_cv2(self._depth_image)

        # flip image as camera is upside down
        depth_image = cv2.flip(depth_image,0)

        # validate depth image 
        is_blank = not ((float(depth_image.max()) != 0.0 ) or (float(depth_image.min() != 0.0)))

        if(is_blank):
            self.get_logger().warning("Warning : depth_image_to_map::generate_new_map() : depth image is invalid! Refusing to generate map...")
            return
        
        #cv2.imshow("depth_image",depth_image)

        #cv2.waitKey(1)

        # begin masking process

        mask = np.zeros(depth_image.shape[:2],dtype=np.uint8)

        d_buffer = self._detection_buffer.detections

        object_list : list[MapObject] = list()

        self._o3d_obj_list = list()

        for bounds in d_buffer:
            # add rectangle to mask and store result in new image
            # this preserves the original mask and allows us to seperate point clouds more easily

            p1 = (int(bounds.center_x - (bounds.width / 2)), int(bounds.center_y - (bounds.height / 2)))
            p2 = (int(bounds.center_x + (bounds.width / 2)), int(bounds.center_y + (bounds.height / 2)))
            color = (255,255,255)

            object_mask = cv2.rectangle(mask,p1,p2,color,-1)

            # apply mask to image, store in seperate image, and create a mesh

            image_result = cv2.bitwise_and(depth_image,depth_image,mask=object_mask)

            # filter depth image 


            #cv2.imshow("mask result",image_result)
            #cv2.waitKey(1)

            mesh_result = self.generate_map_object(image_result,bounds.name)

            if(mesh_result is None):
                self.get_logger().warning("Warning: no object produced from depth mask")
                continue
            else:
                object_list.append(mesh_result)

        #TODO: Filter meshes for invalid / empty meshes (point_radius smaller than certain threshold)

       
        self.get_logger().info("Object list has been generated, adding objects to world map...")
        
        self._map_id += 1
        self._map_cache = WorldMap()
        self._map_cache.objects = object_list

        c_time = time.time()

        self._map_cache.header.stamp.sec = int(c_time)
        self._map_cache.header.stamp.nanosec = int((c_time - int(c_time)) *1e+9 )

        self._map_cache.header._frame_id = f"{self._map_id}"


        # cv2.destroyWindow("mask result")
        # cv2.destroyWindow("depth_image")
        self.get_logger().info("Map Generated Succesfully!")

    
    def generate_map_object(self, img : np.ndarray, name : str) -> MapObject:
        #1 convert opencv image to open3D image

        img = cv2.flip(img,0)
        o3d_image = o3d.geometry.Image(img)

        k = self._camera_info.k

        i_width = int(self._depth_image.width)
        i_height = int(self._depth_image.height)

        fx = float(k[0])
        fy = float(k[4])
        cx = float(k[2])
        cy = float(k[5])

        intrinsics = o3d.camera.PinholeCameraIntrinsic()

        intrinsics.set_intrinsics(i_width,i_height,fx,fy,cx,cy)

        point_cloud = o3d.geometry.PointCloud.create_from_depth_image(o3d_image,intrinsics)
        point_cloud = point_cloud.voxel_down_sample(0.04)

        rs2_point_list : list[ros2_pt32] = list()

        tmp_point_cloud = o3d.geometry.PointCloud()

        # center_pt = point_cloud.get_center()

        # center_dist_sqr = float(center_pt[0] * center_pt[0] + center_pt[1] * center_pt[1] + center_pt[2] * center_pt[2])

        points = point_cloud.points

        for point in points:
            
            # dist = float(point[0] * point[0] + point[1] * point[1] + point[2] * point[2])

            # if(dist >= center_dist_sqr): continue #if the distance is greater than the distance to the center of the previous point cloud, skip that point

            c_point : ros2_pt32 = ros2_pt32()
            c_point.x = float(point[0])
            c_point.y = float(point[1])
            c_point.z = float(point[2])

            #print(f"{c_point.x}, {c_point.y}, {c_point.z}")

            # tmp_point_cloud.points.extend([point])

            rs2_point_list.append(c_point)

        # point_cloud = tmp_point_cloud

        aabb : o3d.geometry.AxisAlignedBoundingBox = point_cloud.get_axis_aligned_bounding_box()

        self._o3d_obj_list.append(point_cloud)
        self._o3d_obj_list.append(aabb)

        dist = math.sqrt(aabb.min_bound[0] * aabb.min_bound[0] + aabb.min_bound[1] * aabb.min_bound[1] + aabb.min_bound[2] * aabb.min_bound[2])

        self.get_logger().info(f"Generated Bounding Box:\nName = {name}\nMin = {aabb.min_bound}\nMax = {aabb.max_bound}\nMinimum Distance = {dist}\n")

        out_object : MapObject = MapObject()
        out_mesh : ros2_poly = ros2_poly()


        aabb_center = aabb.get_center()
        aabb_extents = aabb.get_extent()

        out_object.aabb.center.x = float(aabb_center[0])
        out_object.aabb.center.y = float(aabb_center[1])
        out_object.aabb.center.z = float(aabb_center[2])

        out_object.aabb.extents.x = float(aabb_extents[0])
        out_object.aabb.extents.y = float(aabb_extents[1])
        out_object.aabb.extents.z = float(aabb_extents[2])


        out_mesh.points = rs2_point_list

        out_object.mesh = out_mesh

        return out_object
        


def main():
    rclpy.init()

    node = DepthImageToMapNode()

    rclpy.spin(node)

    rclpy.shutdown()
    

if __name__ == '__main__':
    main()