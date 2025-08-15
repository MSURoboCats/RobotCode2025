import rclpy
import numpy
import quaternion
import time
import copy
import open3d as o3d
import os
from open3d.visualization import Visualizer

from py_sensors.BNO import *
from rclpy.node import Node
from custom_interfaces.msg import ImuData
from geometry_msgs.msg import Quaternion as Q_MSG
from geometry_msgs.msg import Vector3 as V3_MSG
class IMUPublisher(Node):
    saved_data : str
    PUBLISH_RATE = 0.1
    def __init__(self):
        super().__init__('imu_publisher')
        self.publisher_ = self.create_publisher(ImuData,'imu',5)
        timer_period = self.PUBLISH_RATE
        saved_data = ""

        # self._mesh : o3d.geometry.TriangleMesh = o3d.geometry.TriangleMesh.create_coordinate_frame()

        # self._meshCopy = copy.deepcopy(self._mesh)

        # self._vis = Visualizer()

        # self._vis.create_window("rotation visualization")

        # self._vis.add_geometry(self._meshCopy)

        self.timer = self.create_timer(timer_period,self.publisher_callback)


    def publisher_callback(self):
        msg = ImuData()
        
        data = GetFusionData()
        
        v_linearAccel = data[0]

        q_rotation = data[1]
        
        e_rotation = data[2]

        v_angularAccel = data[3]

        q_rotation = (numpy.quaternion(q_rotation[0], q_rotation[1], q_rotation[2], q_rotation[3]))

        # copyPtr = self._meshCopy

        # self._meshCopy = copy.deepcopy(self._mesh)

        # self._meshCopy.rotate(quaternion.as_rotation_matrix(q_rotation), center = self._mesh.get_center())

        #self._mesh.rotate(quaternion.as_rotation_matrix(q_rotation),center=(0,0,0))

        q_msg = Q_MSG()
        q_msg.w = q_rotation.w
        q_msg.x = q_rotation.x
        q_msg.y = q_rotation.y
        q_msg.z = q_rotation.z

        li_msg = V3_MSG()
        li_msg.x = v_linearAccel[0]
        li_msg.y = v_linearAccel[1]
        li_msg.z = v_linearAccel[2]

        an_msg = V3_MSG()
        an_msg.x = v_angularAccel[0]
        an_msg.y = v_angularAccel[1]
        an_msg.z = v_angularAccel[2]

        eu_msg = V3_MSG()
        eu_msg.x = e_rotation[0]
        eu_msg.y = e_rotation[1]
        eu_msg.z = e_rotation[2]

        timestamp = time.time()

        msg.orientation = q_msg
        msg.euler_angles = eu_msg
        msg.angular_velocity = an_msg
        msg.linear_acceleration = li_msg
        msg.global_time_seconds = timestamp

        angle = math.acos(q_rotation.w)

        axis = (0.0,0.0,0.0)

        if(math.sin(angle) != 0):
            axis = (q_msg.x / math.sin(angle), q_msg.y / math.sin(angle), q_msg.z / math.sin(angle))



        self.publisher_.publish(msg)
        log = f"""Published IMU Data: 
                Timestamp: {timestamp:.3f}
                Rotation (W,X,Y,Z): {q_rotation.w:.3f}, {q_rotation.x:.3f}, {q_rotation.y:.3f}, {q_rotation.z:.3f}
                Rotation (Angle, Axis-of-Rotation (x,y,z)): {angle * 180/(2*math.pi):.3f}, ({axis[0]:.3f}, {axis[1]:.3f}, {axis[2]:.3f})
                Rotation (Euler XYZ): {eu_msg.x:.3f}, {eu_msg.y:.3f}, {eu_msg.z:.3f}
                Linear Acceleration (X,Y,Z):  {li_msg.x:.3f}, {li_msg.y:.3f}, {li_msg.z:.3f}
                Angular Acceleration (X,Y,Z): {an_msg.x:.3f}, {an_msg.y:.3f}, {an_msg.z:.3f}"""
        

        self.get_logger().info(log)
        # self._vis.remove_geometry(copyPtr)
        # self._vis.add_geometry(self._meshCopy)
        # self._vis.poll_events()
        # self._vis.update_renderer()
def write_info_to_file(text):
    path = os.getcwd()

    wsIndex = path.find("ros2_ws")

    master_path = path[0:wsIndex]

    path = master_path  + "ros2_ws/testing/logs/depth_log.txt"

    with open(path, "w") as file:
        file.write(text)


def main(args = None):
    rclpy.init(args = args)

    imu_pub = IMUPublisher()

    rclpy.spin(imu_pub)

    #imu_pub._vis.destroy_window()

    imu_pub.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
    



        


        
