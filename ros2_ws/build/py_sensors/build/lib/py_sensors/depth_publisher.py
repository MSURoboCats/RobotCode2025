import rclpy


from py_sensors.BAR02 import *
from rclpy.node import Node

from custom_interfaces.msg import DepthReport

class DepthPublisher(Node):
    def __init__(self):
        super().__init__('depth_publisher')
        self.declare_parameter('i2c_bus',7)
        timer_period = 0.1
        if not InitSensor(i2cbus = self.get_parameter('i2c_bus').get_parameter_value().integer_value):
            self.error_msg = "FAILED TO INIT SENSOR"
            self.timer = self.create_timer(timer_period,self.error_callback)
        else:
            self.publisher_ = self.create_publisher(DepthReport,'bar02',5)
            self.timer = self.create_timer(timer_period,self.publisher_callback)
    
    def error_callback(self):
        self.get_logger().error(self.error_msg + ", REFUSING TO PUBLISH DATA")
    
    def publisher_callback(self):
        msg = DepthReport() 
        data = ReadSensor()

        msg.pressure = data[0]
        msg.depth = data[1]
        msg.temperature = data[2]

        self.publisher_.publish(msg)
        self.get_logger().info("Published depth sensor values\nPressure:%0.3f\nDepth: %0.3f\nTemperature: %0.3f\n" % data)

def main(args = None):
    rclpy.init(args=args)
    
    d_pub = DepthPublisher()

    rclpy.spin(d_pub)

    d_pub.destroy_node()

    rclpy.shutdown()


if __name__ == '__main__':
    main()



