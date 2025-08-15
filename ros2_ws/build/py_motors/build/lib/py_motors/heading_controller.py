import time
import sys
import math
import os
import matplotlib.pyplot as plt

from std_msgs.msg import String, Header, Float64
from geometry_msgs.msg import Quaternion, Vector3

from custom_interfaces.srv import SetHeading
from custom_interfaces.msg import ImuData, HeadingResult

import rclpy
from rclpy.node import Node

from py_sensors.imu_publisher import IMUPublisher




class HeadingController(Node):
    KP : float = 1.0
    KI : float = 0.3
    KD : float = 2

    MAX_OUT : float = 0.125
    
    HEADING_TOLERANCE : float = 0.05 # ~ pi/15

    SAMPLE_RATE = IMUPublisher.PUBLISH_RATE

    desired_heading     : list[float] = list()

    sum_of_errors       : float

    last_error          : float

    control_values      : list[float] = list()

    list_of_errors      : list[float] = list()

    list_of_orientaitons : list[float] = list()

    has_target_heading  : bool

    keep_target         : bool

    arrived             : bool

    allow_error_accum   : bool = True






    def __init__(self, **kwargs):
        super().__init__("heading_controller", **kwargs)

        self.declare_parameter("imu_topic","imu")
        self.declare_parameter("goal_reached_topic", "heading_goal_status")
        self.declare_parameter("motor_control_topic", "heading_adjustment")
        self.declare_parameter("error_average_topic", "error_average")
        
        self.set_heading_service = self.create_service(SetHeading,"set_heading",self.SetTargetHeadingCallback)

        self._sub_imu = self.create_subscription(
            ImuData,
            self.get_parameter("imu_topic").get_parameter_value().string_value,
            self.OrientationSubscriptionCallback,
            5
        )  
        self._goal_reached_publisher = self.create_publisher(
            HeadingResult,
            self.get_parameter("goal_reached_topic").get_parameter_value().string_value,
            5       
        )
        


        self._motor_publisher = self.create_publisher(
            Float64,
            self.get_parameter("motor_control_topic").get_parameter_value().string_value,
            5
        )


        
        self.sum_of_errors = 0.0
        self.last_error = 0.0
        self.has_target_heading = False
        self.keep_target = False
        self.arrived = False

    def OrientationSubscriptionCallback(self, msg : ImuData):
        #self.get_logger().info(f"received IMU Data:\nLin_Accel = {msg.linear_acceleration}\nGyro = {msg.euler_angles}\nang. vel = {msg.angular_velocity}")
        if(not self.has_target_heading) : return
        

        # We can get away with using euler angles as the sub only rotates along one axis, meaning there is no gimbal lock

        current_heading = [msg.euler_angles.x, msg.euler_angles.y, msg.euler_angles.z]


        cAngle = current_heading[0]

        dAngle = self.desired_heading[0]

        if(dAngle < 0.0): dAngle = (2.0 * math.pi) - dAngle

        error : float


        ## UNIT CIRCLE EDGE CASES 
        #  If the current heading is within the first quadrant and the desired heading is in the second, add 2pi to the current heading before 
        #  calculating error.

        if((cAngle >= 0.0 and cAngle < (math.pi / 2.0)) and (dAngle >= (3.0 * math.pi / 2.0) and dAngle < 2.0 * math.pi)):
            error = dAngle - (cAngle + 2.0*math.pi)
        # If the current heading is in the second quad and desired heading is in the first, add 2pi to the desired heading before 
        # calculating error.

        elif (cAngle >= (3.0 * math.pi / 2.0) and cAngle < 2.0 * math.pi) and (dAngle >= 0.0 and dAngle < (math.pi / 2.0)):
            error = (dAngle + 2.0*math.pi) - cAngle
        # otherwise, just calculate the raw error

        else: error = dAngle - cAngle

        self.list_of_orientaitons.append(msg.euler_angles.x)

        self.list_of_errors.append(error)

        

        if(abs(error) < self.HEADING_TOLERANCE):
            out_msg = HeadingResult()
            txt = f"Depth Goal {self.desired_heading} reached! (current heading = {current_heading}, error = {error})"
            averages = self.GetAverageError()
            
            out_msg.text = txt

            out_msg.average_error = averages
            self._goal_reached_publisher.publish(out_msg)
            powers = Float64()
            powers.data = 0.0

            self.get_logger().info(txt)
            self._motor_publisher.publish(powers)

            self.has_target_heading = False or self.keep_target

            # if(not self.arrived):
            #     self.sum_of_errors = 0

            #     self.arrived = True

           

            return

        control = -self.Controller(error)

        control_actual = control

        self.control_values.append(control_actual)

        if control > self.MAX_OUT : control = self.MAX_OUT
        elif control < -self.MAX_OUT : control = -self.MAX_OUT

        if(abs(control) == self.MAX_OUT): self.allow_error_accum = False 
        else: self.allow_error_accum = True

        motor_power_msg = Float64()
        motor_power_msg.data = control
        self._motor_publisher.publish(motor_power_msg)

        self.get_logger().info(f"PID Stats:\n kp,ki,kd = {self.KP}, {self.KI}, {self.KD}\nCurrent: {current_heading}\nTarget: {self.desired_heading}\nControl (Clamped): {control}\nControl (Real Value): {control_actual}")


    def SetTargetHeadingCallback(self, request, response):
        self.desired_heading = request.heading

        

        self.sum_of_errors = 0

        self.has_target_heading = True
        self.keep_target = request.keep_heading_until_override
        self.arrived = False
        response.success = True

        return response




    def GetAverageError(self, window_size = 5) -> float:

        if(len(self.list_of_errors) <= window_size): return sys.float_info.max

        error_sum = 0

        error_window = self.list_of_errors[(len(self.list_of_errors) - 1) - (window_size) : len(self.list_of_errors) - 1]

        for error in error_window: 
            error_sum += error

        return float(error_sum / len(error_window))

        

    def Controller(self, error):
        pTerm = self.KP * error

        if(self.allow_error_accum): self.sum_of_errors += error

        iTerm = self.KI * self.sum_of_errors * self.SAMPLE_RATE

        # see about making the dTerm based on angular acceleration
        dTerm = self.KD * ((error - self.last_error) / self.SAMPLE_RATE)

        self.last_error = error
        
        return pTerm + iTerm + dTerm


def write_pid_info_to_file(pid_info):
    path = os.getcwd()

    control_values = pid_info[3]

    wsIndex = path.find("ros2_ws")

    master_path = path[0:wsIndex]

    path = master_path  + "ros2_ws/testing/logs/heading_controller_log.txt"

    desired_heading = pid_info[4]

    error_values = pid_info[5]

    orientations = pid_info[6]

    with open(path, "w") as file:
        text = f"Test Date: {time.asctime()}\nKD: {pid_info[0]}, KI: {pid_info[1]}, KP: {pid_info[2]}, Target Heading: {desired_heading[0], desired_heading[1], desired_heading[2]}"
        file.write(text)

    plt.plot(range(len(control_values)),control_values)

    plt.title(text)

    plt.savefig(master_path + "ros2_ws/testing/logs/heading_pid_graph.png")

    plt.clf()

    plt.plot(range(len(error_values)),error_values)

    plt.title(text)

    plt.savefig(master_path + "ros2_ws/testing/logs/heading_error_graph.png")

    plt.clf()

    plt.plot(range(len(orientations)),orientations)

    plt.title(text)

    plt.savefig(master_path + "ros2_ws/testing/logs/heading_orientation_graph.png")

    plt.close()



    print(f"noise data written to {path}")


     


def main(args = None):
    try:
        rclpy.init(args = args)

        headingControllerNode = HeadingController()

        rclpy.spin(headingControllerNode)

        
    except KeyboardInterrupt:
        pid_info = (headingControllerNode.KD, headingControllerNode.KI, headingControllerNode.KP, headingControllerNode.control_values, headingControllerNode.desired_heading,headingControllerNode.list_of_errors, headingControllerNode.list_of_orientaitons)

        write_pid_info_to_file(pid_info)
    finally:
        rclpy.shutdown()

if __name__ == '__main__':
    main()