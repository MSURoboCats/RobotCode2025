import rclpy

from rclpy.node import Node
from custom_interfaces.msg import MotorCommand
from custom_interfaces.msg import MotionGoal


class MotorConductor(Node):
    def __init__(self):
        super().__init__('motor_conductor')
        self._subscription = self.create_subscription(MotionGoal,"MotionGoal",self.publisher_callback, 5)
        self._publisher = self.create_publisher(MotorCommand, "MotorCommand", 5)
    
    def publisher_callback(self, msg):
        in_msg = msg.goal
        out_msg = MotorCommand()

        cmds = [0,0,0,0,0,0]

        match in_msg:
            ### VERTICAL
            case "u_sl":        ## UP SLOW
                cmds[1] = 2
                cmds[4] = 1
            
            case "d_sl":        ## DOWN SLOW
                cmds[1] = 1
                cmds[4] = 2

            case "u_me":        ## UP MEDIUM
                cmds[1] = 4
                cmds[4] = 3
            
            case "d_me":        ## DOWN MEDIUM
                cmds[1] = 3
                cmds[4] = 4
            
            case "u_fa":        ## UP FAST
                cmds[1] = 6
                cmds[4] = 5
            
            case "d_fa":        ## DOWN FAST
                cmds[1] = 5
                cmds[4] = 6

            ### HORIZONTAL
            case "f_sl":        ## FORWARD SLOW
                cmds[0] = 1
                cmds[2] = 2     # front and back motors are oriented in opposite dir
                cmds[3] = 2
                cmds[5] = 1

            case "r_sl":        ## REVERSE SLOW
                cmds[0] = 2
                cmds[2] = 1
                cmds[3] = 1
                cmds[5] = 2
            
            case "f_me":        ## FORWARD MEDIUM
                cmds[0] = 3
                cmds[2] = 4
                cmds[3] = 4
                cmds[5] = 3
            
            case "r_me":        ## REVERSE MEDIUM
                cmds[0] = 4
                cmds[2] = 3
                cmds[3] = 3
                cmds[5] = 4
            
            case "f_fa":        ## FORWARD FAST
                cmds[0] = 5
                cmds[2] = 6
                cmds[3] = 6
                cmds[5] = 5
            
            case "r_fa":        ## REVERSE FAST
                cmds[0] = 6
                cmds[2] = 5
                cmds[3] = 5
                cmds[5] = 6    

            case _: # Possibly change to continuing previous command
                print("Unrecognized command: \"%s\" defaulting to killing all motors\n" % in_msg)             


        out_msg.motor_cmds = cmds       

        self._publisher.publish(out_msg)
        self.get_logger().info("Received motor goal " + in_msg)
        self.get_logger().info("Publishing motor command: %d, %d, %d, %d, %d, %d," % (  out_msg.motor_cmds[0],
                                                                                        out_msg.motor_cmds[1],
                                                                                        out_msg.motor_cmds[2],
                                                                                        out_msg.motor_cmds[3],
                                                                                        out_msg.motor_cmds[4],
                                                                                        out_msg.motor_cmds[5]))

def main(args=None):
    rclpy.init(args=args)

    motor_conductor = MotorConductor()

    rclpy.spin(motor_conductor)

    motor_conductor.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()


