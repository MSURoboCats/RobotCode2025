import os

import rclpy
from rclpy.node import Node
from py_motors.MotorCommands import*


from custom_interfaces.msg import MotorCommand, HorizontalMotorCommands, VerticalMotorCommands

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

        configPath = configPath[0:wsIndex] + "ros2_ws/config/motor_config/motorconfig.csv"

        self._motorMap = GetMotorMap(configPath)
        self.get_logger().info(f"created motor map {self._motorMap}")

       

        self.all_motor_subscription = self.create_subscription(MotorCommand, 'MotorCommand',self.listener_callback,5)
        self.vertical_motor_sub = self.create_subscription(VerticalMotorCommands, "VerticalMotorCMDs",self.listener_callback,5)
        self.horizontal_motor_sub = self.create_subscription(HorizontalMotorCommands, "HorizontalMotorCMDs",self.listener_callback,5)




        

    def _match_all_motorcmds(self, throttles, motorNumbers = None):
        if motorNumbers is None  : motorNumber = 0
        
        for i in range(throttles):
            if motorNumbers is None : motorNumber = i
            else : motorNumber = motorNumbers[i]

            SetMotorSpeed(throttles[i], self._motorMap[motorNumber])
            self.get_logger().info("Applied throttle %lf to motor at channel %d\n" % (throttles[i], motorNumber))


    def listener_callback(self, msg):
        outstr :  str = "I heard command "
        motorNumbers = None
        if(msg is MotorCommand):
            outstr = 'I heard  command %lf, %lf, %lf, %lf, %lf, %lf' % (msg.throttles[0],
                                                                        msg.throttles[1],
                                                                        msg.throttles[2],
                                                                        msg.throttles[3],
                                                                        msg.throttles[4],
                                                                        msg.throttles[5])

        else:
            motorNumbers = msg.motor_numbers
            throttles = msg.throttles
            for i in range(len(motorNumbers)):
                outstr += f"{motorNumbers[i]} : {throttles[i]}"

        self.get_logger().info(outstr)

        self._match_all_motorcmds(throttles=msg.throttles,motorNumbers = motorNumbers)
        
        self.get_logger().info("Motor State Set...")



def main(args = None):
    try:
        rclpy.init(args = args)
        motor_controller = MotorController()

        InitMotor()
        rclpy.spin(motor_controller)
        
    except KeyboardInterrupt:
        CleanupMotor()
    finally:
        motor_controller.destroy_node()
        rclpy.shutdown()




if __name__ == '__main__':
    main()