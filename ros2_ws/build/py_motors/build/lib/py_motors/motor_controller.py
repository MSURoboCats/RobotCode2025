import os

import rclpy
from rclpy.node import Node
from py_motors.MotorCommands import*


from custom_interfaces.msg import MotorCommand

# fn that generates a map between the motor number and the i2c channel based on a previous config 
def GetMotorMap(filePath : str):
    outMap = dict()

    with open(filePath, 'r') as file:
        
        for line in file:

            split = line.split(',')

            invalidNumberOfItems = len(split) > 2 or len(split) < 2

            if(invalidNumberOfItems):
                print("not enough items on line: \"" + line + "\" skipping line")
                continue
            
            itemsTooLong = len(split[0]) > 1 or len(split[1]) > 2

            if(itemsTooLong): 
                print(f"Items too long! {len(split[0])}, {len(split[1])}")

            canCastToInt : bool = False

            motorNumber : int = -1
            i2cChannel : int = -1

            try:
                motorNumber = int(split[0])
                i2cChannel = int(split[1])
            except Exception as e :
                print("could not cast line: \"" + line + "\"\nError = " + e)
                canCastToInt = False
            else:
                canCastToInt = True
            
            if not (itemsTooLong) and canCastToInt:
                outMap[motorNumber] = i2cChannel
    
    return outMap








class MotorController(Node):

    _motorMap : dict


    def __init__(self):
        super().__init__('motor_controller')

        configPath = os.getcwd()

        wsIndex = configPath.find("ros2_ws")

        configPath = configPath[0:wsIndex] + "ros2_ws/motor_config/motorconfig.csv"

        self._motorMap = GetMotorMap(configPath)
        self.get_logger().info(f"created motor map {self._motorMap}")

       

        self.subscription = self.create_subscription(MotorCommand, 'MotorCommand',self.listener_callback,5)



        

    def _match_all_motorcmds(self, throttles):
        motorNumber = 0
        
        for throttle in throttles:
            SetMotorSpeed(throttle, self._motorMap[motorNumber])
            self.get_logger().info("Applied throttle %lf to motor at channel %d\n" % (throttle, motorNumber))
            motorNumber += 1


    def listener_callback(self, msg):
        self.get_logger().info('I heard  command %lf, %lf, %lf, %lf, %lf, %lf' % (msg.throttles[0],
                                                                            msg.throttles[1],
                                                                            msg.throttles[2],
                                                                            msg.throttles[3],
                                                                            msg.throttles[4],
                                                                            msg.throttles[5]))

        self._match_all_motorcmds(throttles=msg.throttles)
        
        self.get_logger().info("Motor State Set...")

    # old motor commands function that used the -1 thru 6 implimentation
    # def _match_all_motorcmds(self, motor_cmds):
    #     m_channel = 0
    #     m_state = MotorState.STOPPED
    #     m_speed = MotorSpeed.SLOW
    #     for motor_cmd in motor_cmds:
    #         match motor_cmd:
    #             case 0:
    #                 m_state = MotorState.STOPPED
    #                 m_speed = MotorSpeed.SLOW
    #             case 1:
    #                 m_state = MotorState.FORWARD
    #                 m_speed = MotorSpeed.SLOW
    #             case 2:
    #                 m_state = MotorState.REVERSE
    #                 m_speed = MotorSpeed.SLOW
    #             case 3:
    #                 m_state = MotorState.FORWARD
    #                 m_speed = MotorSpeed.MEDIUM
    #             case 4:
    #                 m_state = MotorState.REVERSE
    #                 m_speed = MotorSpeed.MEDIUM
    #             case 5:
    #                 m_state = MotorState.FORWARD
    #                 m_speed = MotorSpeed.FAST
    #             case 6:
    #                 m_state = MotorState.REVERSE
    #                 m_speed = MotorSpeed.FAST
    #             case _:
    #                 m_channel += 1
    #                 continue
    #         SetMotorState(m_state,m_speed,m_channel)
    #         self.get_logger().info('Published motor command (%s : %s) to motor %d' % (m_state.name, m_speed.name,m_channel))
    #         m_channel += 1


                



def main(args = None):
    rclpy.init(args = args)
    motor_controller = MotorController()

    InitMotor()
    rclpy.spin(motor_controller)
    CleanupMotor()
    motor_controller.destroy_node()
    rclpy.shutdown()




if __name__ == '__main__':
    main()