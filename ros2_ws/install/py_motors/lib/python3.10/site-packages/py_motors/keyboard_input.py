import rclpy
from rclpy.node import Node

from custom_interfaces.msg import MotorCommand

from sshkeyboard import listen_keyboard


throttle = 0.5

class KeyboardMotorController(Node):
    _currentMsg = MotorCommand()
    
    def __init__(self):
        super().__init__('keyboard_controller')
        self._publisher = self.create_publisher(MotorCommand,'MotorCommand',10)


    def onPressCallback(self, key):
        throttles = [0.0,0.0,0.0,0.0,0.0,0.0]

        match key:
            ### VERTICAL
            case "q":        ## UP MEDIUM
                throttles[1] = -throttle
                throttles[4] = throttle
            
            case "e":        ## DOWN MEDIUM
                throttles[1] = throttle
                throttles[4] = -throttle
            
            case "w":        ## FORWARD MEDIUM
                throttles[0] = throttle
                throttles[2] = -throttle
                throttles[3] = -throttle
                throttles[5] = throttle
            
            case "s":        ## REVERSE MEDIUM
                throttles[0] = -throttle
                throttles[2] = throttle
                throttles[3] = throttle
                throttles[5] = -throttle
        self._currentMsg.throttles = throttles
        self._publisher.publish(self._currentMsg)
    
    def onReleaseCallback(self, key):
        self._currentMsg.throttles = [0.0,0.0,0.0,0.0,0.0,0.0]
        self._publisher.publish(self._currentMsg)

    def listen(self):
        ### publish release callback first to initialize motors
        self.onReleaseCallback(None)
        
        self.get_logger().info("Initializing keyboard control")
        listen_keyboard(on_press=self.onPressCallback,on_release=self.onReleaseCallback)

        self.get_logger().info("Keyboard control relenquished, cleaning stopping motors")

        self.onReleaseCallback(None)

def main():
    rclpy.init()

    node = KeyboardMotorController()

    node.listen()

    rclpy.shutdown()

if __name__ == '__main__':
    main()



        