import os
import time

import matplotlib.pyplot as plt

import rclpy
from rclpy.node import Node

from py_sensors.depth_publisher import DepthPublisher

from std_msgs.msg import String, Float64

from custom_interfaces.srv import SetDepth

from custom_interfaces.msg import DepthReport



## adapted from: https://www.wescottdesign.com/articles/pid/pidWithoutAPhd.pdf 
## and https://www.digikey.com/en/maker/tutorials/2024/implementing-a-pid-controller-algorithm-in-python 


__SENSOR_ERROR = 0.2

__ROLLING_AVERAGE = 5

class DepthController(Node):

    KP              : float = 0.6
    KI              : float = 0.1
    KD              : float = 0.2

    SAMPLE_RATE     : float = DepthPublisher.TIMER_PERIOD

    MAX_OUTPUT      : float = 0.75

    MIN_OUTPUT       : float = -0.75

    DEPTH_TOLERANCE : float = 0.07


    desired_depth   : float


    sum_of_errors   : float = 0.0

    last_depth      : float = 0.0

    hasTargetDepth  : bool

    control_values : list[float] = list()
    



    def __init__(self, **kwargs):
        super().__init__("depth_controller", **kwargs)

        self.declare_parameter("depth_topic","bar02")
        self.declare_parameter("goal_reached_topic", "depth_status")
        self.declare_parameter("motor_control_topic","altitude_adjustment")

        self.hasTargetDepth = False

        self.desired_depth = 0.0

        self.set_depth_service = self.create_service(SetDepth,'set_depth',self.SetTargetDepthCallback)

        self.goal_reached_publisher = self.create_publisher(
            String,
            self.get_parameter("goal_reached_topic").get_parameter_value().string_value,
            5    
        )

        self.depth_subscription = self.create_subscription(
            DepthReport,
            self.get_parameter("depth_topic").get_parameter_value().string_value,
            self.DepthSubscriptionCallback,
            5
        )

        self.motor_publisher = self.create_publisher(
            Float64,
            self.get_parameter("motor_control_topic").get_parameter_value().string_value,
            5    
        )



    def DepthSubscriptionCallback(self, msg):
        current_depth = msg.depth 

        if((current_depth == msg.pressure) and (current_depth == msg.temperature) and (current_depth == -1)): # check for invalid reading
            return
        
        if(self.hasTargetDepth):

            error = self.desired_depth - current_depth

            if(abs(error)  <  self.DEPTH_TOLERANCE):
                outmsg = String()
                outmsg.data = f"Depth Goal {self.desired_depth:.3f} reached! ({current_depth:.3f})"
                self.goal_reached_publisher.publish(outmsg)
                powers = Float64()
                powers.data = 0.0

                self.get_logger().info(outmsg.data)

                self.motor_publisher.publish(powers)

                #self.hasTargetDepth = False ## stops the PID loop from continuing once it reaches the target depth 
                return

            control = -self.PIDController(error,current_depth)

            control_actual = control

            self.control_values.append(control_actual)

            if control > self.MAX_OUTPUT : control = self.MAX_OUTPUT
            elif control < self.MIN_OUTPUT : control = self.MIN_OUTPUT

            motor_power_msg = Float64()

            motor_power_msg.data = control

            self.motor_publisher.publish(motor_power_msg)



            self.get_logger().info(f"PID Stats:\n kp,ki,kd = {self.KP}, {self.KI}, {self.KD}\nCurrent: {current_depth}\nTarget: {self.desired_depth}\nControl (Clamped): {control}\nControl (Real Value): {control_actual}")
        

    

    def SetTargetDepthCallback(self, request, response):
        self.desired_depth = request.depth

        self.sum_of_errors = 0

        self.hasTargetDepth = True

        response.success = True

        return response
        





    def PIDController(self, error, currentDepth):
        pTerm = self.KP * error

        self.sum_of_errors += error

        iTerm = self.KI * self.sum_of_errors * self.SAMPLE_RATE

        dTerm = self.KD * ((error - self.last_depth) / self.SAMPLE_RATE)

        self.last_depth = error

        return pTerm + iTerm + dTerm
    


def write_pid_info_to_file(pid_info):
    path = os.getcwd()

    control_values = pid_info[3]

    wsIndex = path.find("ros2_ws")

    master_path = path[0:wsIndex]

    path = master_path  + "ros2_ws/testing/logs/depth_controller_log.txt"

    with open(path, "w") as file:
        text = f"Test Date: {time.asctime()}\nKD: {pid_info[0]}, KI: {pid_info[1]}, KP: {pid_info[2]}, Target Depth: {pid_info[4]}"
        file.write(text)

    plt.plot(range(len(control_values)),control_values)

    plt.title(text)

    plt.savefig(master_path + "ros2_ws/testing/logs/pid_graph.png")

    print(f"noise data written to {path}")



def main(args = None):
    try:
        rclpy.init(args = args)

        depthControllerNode = DepthController()

        rclpy.spin(depthControllerNode)

        
    except KeyboardInterrupt:
      
        pid_info = (depthControllerNode.KD, depthControllerNode.KI, depthControllerNode.KP, depthControllerNode.control_values, depthControllerNode.desired_depth)

        write_pid_info_to_file(pid_info)
    finally:
        rclpy.shutdown()

if __name__ == '__main__':
    main()