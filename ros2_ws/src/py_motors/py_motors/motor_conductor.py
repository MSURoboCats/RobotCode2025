import rclpy

from rclpy.node import Node
from custom_interfaces.msg import MotorCommand, HorizontalMotorCommands, VerticalMotorCommands
from custom_interfaces.msg import MotionGoal
from custom_interfaces.msg import DepthReport
from std_msgs.msg import Float64


class MotorConductor(Node):
    V_THROTTLES = [1, 4]
    H_THROTTLES = [0, 2, 3, 5]

    def __init__(self, **kwargs):
        super().__init__('motor_conductor', **kwargs)
        self._commandSubscription = self.create_subscription(MotionGoal,"MotionGoal",self.command_callback, 5)
        self._altitudeSubscription = self.create_subscription(Float64,"altitude_adjustment",self.altitude_adjustment_callback,5)
        self._headingSubscription = self.create_subscription(Float64, "heading_adjustment", self.heading_adjustment_callback,5)

        self._all_motor_publisher = self.create_publisher(MotorCommand, "MotorCommand", 5)
        self._vertical_motor_publisher = self.create_publisher(VerticalMotorCommands, "VerticalMotorCMDs",5)
        self._horizontal_motor_publisher = self.create_publisher(HorizontalMotorCommands, "HorizontalMotorCMDs",5)
        
    
    def altitude_adjustment_callback(self, msg):

        power = msg.data

        if(power > 1.0): power = 1.0
        elif(power < -1.0): power = -1.0

        motorNumbers = [1, 4]
        throttles = [-power, power]

        out_msg = VerticalMotorCommands()

        out_msg.throttles = throttles

        out_msg.motor_numbers = motorNumbers

        self._vertical_motor_publisher.publish(out_msg)
 

    def heading_adjustment_callback(self, msg):
        power = msg.data 

        if(power > 1.0) : power = 1.0 
        elif(power < -1.0) : power = -1.0

        motor_numbers = [0,2,3,5]

        throttles = [power, -power, power, -power]

        out_msg = HorizontalMotorCommands()

        out_msg.motor_numbers = motor_numbers
        out_msg.throttles = throttles

        self._horizontal_motor_publisher.publish(out_msg)

    ### Callback for receiving "verbal" commands and turning them into motor powers
    def command_callback(self, msg):
        in_msg = msg.goal

        # Motion Direction, 0 = vertical, 1 = horiztonal, -1 = all
        motionDirection = -1

        throttles = [0.0,0.0,0.0,0.0,0.0,0.0]

        match in_msg:
            ### VERTICAL
            case "u_sl":        ## UP SLOW
                throttles[1] = -0.25
                throttles[4] = 0.25
                motionDirection = 0
            
            case "d_sl":        ## DOWN SLOW
                throttles[1] = 0.25
                throttles[4] = -0.25
                motionDirection = 0

            case "u_me":        ## UP MEDIUM
                throttles[1] = -0.5
                throttles[4] = 0.5
                motionDirection = 0
            
            case "d_me":        ## DOWN MEDIUM
                throttles[1] = 0.5
                throttles[4] = -0.5
                motionDirection = 0
            
            case "u_fa":        ## UP FAST
                throttles[1] = -0.75
                throttles[4] = 0.75
                motionDirection = 0
            
            case "d_fa":        ## DOWN FAST
                throttles[1] = 0.75
                throttles[4] = -0.75
                motionDirection = 0

            ### HORIZONTAL
            case "f_sl":        ## FORWARD SLOW
                throttles[0] = 0.1
                throttles[2] = -0.1     # front and back motors are oriented in opposite dir
                throttles[3] = -0.1
                throttles[5] = 0.1
                motionDirection = 1

            case "r_sl":        ## REVERSE SLOW
                throttles[0] = -0.1
                throttles[2] = 0.1
                throttles[3] = 0.1
                throttles[5] = -0.1
                motionDirection = 1

            
            case "f_me":        ## FORWARD MEDIUM
                throttles[0] = 0.5
                throttles[2] = -0.5
                throttles[3] = -0.5
                throttles[5] = 0.5
                motionDirection = 1
            
            case "r_me":        ## REVERSE MEDIUM
                throttles[0] = -0.5
                throttles[2] = 0.5
                throttles[3] = 0.5
                throttles[5] = -0.5
                motionDirection = 1
            
            case "f_fa":        ## FORWARD FAST
                throttles[0] = 0.75
                throttles[2] = -0.75
                throttles[3] = -0.75
                throttles[5] = 0.75
                motionDirection = 1
            
            case "r_fa":        ## REVERSE FAST
                throttles[0] = -0.75
                throttles[2] = 0.75
                throttles[3] = 0.75
                throttles[5] = -0.75 
                motionDirection = 1  
            
            case "y_le":        ## SPIN LEFT
                throttles[0] = 0.1
                throttles[2] = -0.1
                throttles[3] = 0.1
                throttles[5] = -0.1
                motionDirection = 1
            
            case 'y_ri':        ## SPIN RIGHT

                throttles[0] = -0.1
                throttles[2] = 0.1
                throttles[3] = -0.1
                throttles[5] = 0.1
                motionDirection = 1

            case _: # Possibly change to continuing previous command
                print("Unrecognized command: \"%s\" defaulting to killing all motors\n" % in_msg)    
                motionDirection = -1
                         
        out_msg = None

        if not msg.keep_unmodified_throttles or motionDirection == -1: 

            out_msg = MotorCommand()

            out_msg.throttles = throttles       

            self._all_motor_publisher.publish(out_msg)

        elif motionDirection == 0:
            out_msg = VerticalMotorCommands()

            out_throttles : list[float] = list()

            for motorNumber in self.V_THROTTLES:
                out_throttles.append(throttles[motorNumber])
            
            out_msg.motor_numbers = self.V_THROTTLES
            out_msg.throttles = out_throttles
            self._vertical_motor_publisher.publish(out_msg)
        elif motionDirection == 1:
            out_msg = HorizontalMotorCommands()

            out_throttles : list[float] = list()

            for motorNumber in self.H_THROTTLES:
                out_throttles.append(throttles[motorNumber])
            
            out_msg.motor_numbers = self.H_THROTTLES
            out_msg.throttles = out_throttles         
            self._horizontal_motor_publisher.publish(out_msg)   




        self.get_logger().info(f"Received motor goal \"{in_msg}\" with direction {motionDirection}")
        
        if isinstance(out_msg,MotorCommand):
            self.get_logger().info("Publishing motor command: 0: %lf, 1: %lf, 2: %lf, 3: %lf, 4: %lf, 5: %lf," % (  out_msg.throttles[0],
                                                                                                                    out_msg.throttles[1],
                                                                                                                    out_msg.throttles[2],
                                                                                                                    out_msg.throttles[3],
                                                                                                                    out_msg.throttles[4],
                                                                                                                    out_msg.throttles[5]))
        elif not (out_msg is None):
            motor_cmd_str : str = "Publishing motor command: "

            for i in range(len(out_msg.motor_numbers)): 
                motor_cmd_str += f" {out_msg.motor_numbers[i]}: {out_msg.throttles[i]}"

            self.get_logger().info(motor_cmd_str)


        
       
def main(args=None):
    rclpy.init(args=args)

    motor_conductor = MotorConductor()

    rclpy.spin(motor_conductor)

    motor_conductor.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()


