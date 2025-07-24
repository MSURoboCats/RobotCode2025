import rclpy

from rclpy.node import Node
from custom_interfaces.msg import MotorCommand
from custom_interfaces.msg import MotionGoal
from custom_interfaces.msg import DepthReport
from std_msgs.msg import Float64

class MotorConductor(Node):
    def __init__(self):
        super().__init__('motor_conductor')
        self._commandSubscription = self.create_subscription(MotionGoal,"MotionGoal",self.command_callback, 5)
        self._altitudeSubscription = self.create_subscription(Float64,"altitude_adjustment",self.altitude_adjustment_callback,5)
        self._publisher = self.create_publisher(MotorCommand, "MotorCommand", 5)
        
    def altitude_adjustment_callback(self, msg):

        power = msg.data

        if(power > 1.0): power = 1.0
        elif(power < -1.0): power = -1.0

        throttles = [0.0,0.0,0.0,0.0,0.0,0.0]

        throttles[1] = -power
        throttles[4] =  power

        out_msg = MotorCommand()

        out_msg.throttles = throttles

        self._publisher.publish(out_msg)
 

    
    ### Callback for receiving "verbal" commands and turning them into motor powers
    def command_callback(self, msg):
        in_msg = msg.goal
        out_msg = MotorCommand()

        throttles = [0.0,0.0,0.0,0.0,0.0,0.0]

        match in_msg:
            ### VERTICAL
            case "u_sl":        ## UP SLOW
                throttles[1] = -0.25
                throttles[4] = 0.25
            
            case "d_sl":        ## DOWN SLOW
                throttles[1] = 0.25
                throttles[4] = -0.25

            case "u_me":        ## UP MEDIUM
                throttles[1] = -0.5
                throttles[4] = 0.5
            
            case "d_me":        ## DOWN MEDIUM
                throttles[1] = 0.5
                throttles[4] = -0.5
            
            case "u_fa":        ## UP FAST
                throttles[1] = -0.75
                throttles[4] = 0.75
            
            case "d_fa":        ## DOWN FAST
                throttles[1] = 0.75
                throttles[4] = -0.75

            ### HORIZONTAL
            case "f_sl":        ## FORWARD SLOW
                throttles[0] = 0.25
                throttles[2] = -0.25     # front and back motors are oriented in opposite dir
                throttles[3] = -0.25
                throttles[5] = 0.25

            case "r_sl":        ## REVERSE SLOW
                throttles[0] = -0.25
                throttles[2] = 0.25
                throttles[3] = 0.25
                throttles[5] = -0.25
            
            case "f_me":        ## FORWARD MEDIUM
                throttles[0] = 0.5
                throttles[2] = -0.5
                throttles[3] = -0.5
                throttles[5] = 0.5
            
            case "r_me":        ## REVERSE MEDIUM
                throttles[0] = -0.5
                throttles[2] = 0.5
                throttles[3] = 0.5
                throttles[5] = -0.5
            
            case "f_fa":        ## FORWARD FAST
                throttles[0] = 0.75
                throttles[2] = -0.75
                throttles[3] = -0.75
                throttles[5] = 0.75
            
            case "r_fa":        ## REVERSE FAST
                throttles[0] = -0.75
                throttles[2] = 0.75
                throttles[3] = 0.75
                throttles[5] = -0.75   
            
            case "y_le":        ## SPIN LEFT
                throttles[0] = 0.25
                throttles[2] = -0.25
                throttles[3] = 0.25
                throttles[5] = -0.25
            
            case 'y_ri':        ## SPIN RIGHT

                throttles[0] = -0.25
                throttles[2] = 0.25
                throttles[3] = -0.25
                throttles[5] = 0.25

            case _: # Possibly change to continuing previous command
                print("Unrecognized command: \"%s\" defaulting to killing all motors\n" % in_msg)             


        out_msg.throttles = throttles       

        self._publisher.publish(out_msg)
        self.get_logger().info("Received motor goal " + in_msg)
        self.get_logger().info("Publishing motor command: %lf, %lf, %lf, %lf, %lf, %lf," % (  out_msg.throttles[0],
                                                                                        out_msg.throttles[1],
                                                                                        out_msg.throttles[2],
                                                                                        out_msg.throttles[3],
                                                                                        out_msg.throttles[4],
                                                                                        out_msg.throttles[5]))

def main(args=None):
    rclpy.init(args=args)

    motor_conductor = MotorConductor()

    rclpy.spin(motor_conductor)

    motor_conductor.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()


