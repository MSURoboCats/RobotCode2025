import rclpy
from rclpy.node import Node
from py_motors.MotorCommands import*


class TorpedoController(Node):
    def __init__(self):
        super().__init__("torpedo_controller")
        