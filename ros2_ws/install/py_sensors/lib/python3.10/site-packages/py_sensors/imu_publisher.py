import rclpy
import numpy
import quaternion
import time

from py_sensors.BNO import *
from rclpy.node import Node
from custom_interfaces.msg import ImuData
from geometry_msgs.msg import Quaternion as Q_MSG
from geometry_msgs.msg import Vector3 as V3_MSG
class IMUPublisher(Node):

    def __init__(self):
        super().__init__('imu_publisher')
        self.publisher_ = self.create_publisher(ImuData,'imu',5)
        timer_period = 0.1
        self.timer = self.create_timer(timer_period,self.publisher_callback)

    def publisher_callback(self):
        msg = ImuData()
        
        data = GetFusionData()
        
        v_linearAccel = data[0]

        v_rotation = data[1]
        
        v_angularAccel = data[2]

        q_rotation = quaternion.as_float_array(quaternion.from_euler_angles(v_rotation))

        q_msg = Q_MSG()
        q_msg.w = q_rotation[0]
        q_msg.x = q_rotation[1]
        q_msg.y = q_rotation[2]
        q_msg.z = q_rotation[3]

        li_msg = V3_MSG()
        li_msg.x = v_linearAccel[0]
        li_msg.y = v_linearAccel[1]
        li_msg.z = v_linearAccel[2]

        an_msg = V3_MSG()
        an_msg.x = v_angularAccel[0]
        an_msg.y = v_angularAccel[1]
        an_msg.z = v_angularAccel[2]

        timestamp = time.time()

        msg.orientation = q_msg
        msg.angular_velocity = an_msg
        msg.linear_acceleration = li_msg
        msg.global_time_seconds = timestamp

        self.publisher_.publish(msg)
        log = """Published IMU Data: 
                 Timestamp: {0:.3f}
                 Rotation (X,Y,Z,W): {1:.3f}, {2:.3f}, {3:.3f}, {4:.3f}
                 Linear Acceleration (X,Y,Z):  {5:.3f}, {6:.3f}, {7:.3f}
                 Angular Acceleration (X,Y,Z): {8:.3f}, {9:.3f}, {10:.3f}"""
        log = log.format(timestamp,
                         q_msg.x,q_msg.y,q_msg.z,q_msg.w,
                         li_msg.x,li_msg.y,li_msg.z,
                         an_msg.x,an_msg.y,an_msg.z)

        self.get_logger().info(log)
def main(args = None):
    rclpy.init(args = args)

    imu_pub = IMUPublisher()

    rclpy.spin(imu_pub)

    imu_pub.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
    



        


        
