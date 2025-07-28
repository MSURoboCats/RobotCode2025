import rclpy
import sys
import os
import time

import matplotlib.pyplot as plt

from py_sensors.BAR02 import *
from rclpy.node import Node

from custom_interfaces.msg import DepthReport

class DepthPublisher(Node):
    last_depth_measurement  : float

    total_noise             : float

    avg_noise               : float

    noise_max               : float 

    noise_min               : float

    total_depth             : float

    num_measurements        : int

    first_measurement       : bool

    DEPTH_OFFSET            : float = 0.0

    depth_measurements      : list[float] = list()






    TIMER_PERIOD = 0.1
    def __init__(self):
        super().__init__('depth_publisher')
        self.declare_parameter('i2c_bus',7)
        if not InitSensor(i2cbus = self.get_parameter('i2c_bus').get_parameter_value().integer_value):
            self.error_msg = "FAILED TO INIT SENSOR"
            self.timer = self.create_timer(self.TIMER_PERIOD,self.error_callback)
        else:
            self.publisher_ = self.create_publisher(DepthReport,'bar02',5)

            SetFluidDensity(ms5837.DENSITY_FRESHWATER)

            self.first_measurement = True
            
            self.total_noise = 0.0

            self.num_measurements = 0
            
            self.last_depth_measurement = 0.0
            
            self.total_depth = 0.0

            self.noise_min = sys.float_info.max
            self.noise_max = sys.float_info.min
            
            self.timer = self.create_timer(self.TIMER_PERIOD,self.publisher_callback)
    
    def error_callback(self):
        self.get_logger().error(self.error_msg + ", REFUSING TO PUBLISH DATA")
    
    def publisher_callback(self):
        msg = DepthReport() 
        data = ReadSensor()

        current_pressure = data[0]

        current_depth = data[1] + self.DEPTH_OFFSET

        current_temp = data[2]

        self.depth_measurements.append(current_depth)

        msg.pressure = current_depth
        msg.depth = current_pressure
        msg.temperature = current_temp

        self.publisher_.publish(msg)
        self.get_logger().info("Published depth sensor values\nPressure:%0.3f\nDepth: %0.3f\nTemperature: %0.3f\n" % data)

        valid_data =  (data[0] != data[1] and data[0] != data[2] and data[0] != -1)

        if(self.first_measurement and valid_data):
            self.first_measurement = False
            self.last_depth_measurement = current_depth

            self.total_depth = current_depth
            self.num_measurements += 1
        elif( (not self.first_measurement) and valid_data):
            self.num_measurements += 1
            noise = self.last_depth_measurement - current_depth

            self.total_depth += current_depth

            self.total_noise += noise

            if(noise > self.noise_max) : self.noise_max = noise
            elif (noise < self.noise_min) : self.noise_min = noise

            avg_noise = self.total_noise / (self.num_measurements - 1)   

            self.avg_noise = avg_noise 

            avg_depth = self.total_depth / self.num_measurements         

            self.last_depth_measurement = current_depth

            self.get_logger().info(f"Average noise: {avg_noise}\nMax Noise: {self.noise_max}\nMin Noise: {self.noise_min}\nAverage Depth: {avg_depth}")





def write_noise_info_to_file(noise_info):
    path = os.getcwd()

    wsIndex = path.find("ros2_ws")

    masterPath = path[0:wsIndex]

    path = masterPath + "ros2_ws/testing/logs/depth_sensor_noise_log.txt"

    with open(path, "a") as file:
        text = f"[{time.asctime()}][{noise_info[3]:.3f} secs] Average Noise: {noise_info[0]}, Max Noise: {noise_info[1]}, Min Noise: {noise_info[2]}\n"
        file.write(text)

    print(f"noise data written to {path}")

    plt.plot(range(noise_info[4]),noise_info[4])
    plt.title(f"[{time.asctime()}][{noise_info[3]:.3f} secs] Depth Values Over Time")
    plt.savefig(masterPath + "ros2_ws/testing/logs/depth_over_time.png")

def main(args = None):
    try:
        rclpy.init(args=args)
    
        d_pub = DepthPublisher()

        start_time = time.time()
        rclpy.spin(d_pub)

       
    except KeyboardInterrupt:
        end_time = time.time()

        session_time = end_time - start_time
        noise_info = (d_pub.avg_noise,d_pub.noise_max, d_pub.noise_min, session_time,d_pub.depth_measurements)

        write_noise_info_to_file(noise_info)



    finally:
        d_pub.destroy_node()

        rclpy.shutdown()




if __name__ == '__main__':
    main()



