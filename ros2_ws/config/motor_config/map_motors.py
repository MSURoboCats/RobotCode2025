import time
import board
import busio
import os

from enum import Enum
from board import SCL, SDA
from adafruit_motor import motor
from adafruit_pca9685 import PCA9685

DUTY_CYCLE_STP = int(65535 * 1.6/2.5)
DUTY_CYCLE_FWD_MAX = int(65535 * 2.0/2.5)
DUTY_CYCLE_RVS_MAX = int(65535 * 1.2/2.5)

DELTA_FORWARD = abs(DUTY_CYCLE_FWD_MAX - DUTY_CYCLE_STP)
DELTA_REVERSE = abs(DUTY_CYCLE_RVS_MAX - DUTY_CYCLE_STP)

FORWARD_SLOW = DUTY_CYCLE_FWD_MAX - int(DELTA_FORWARD * 0.8)
FORWARD_MED = DUTY_CYCLE_FWD_MAX - int(DELTA_FORWARD * 0.5)
FORWARD_FAST = DUTY_CYCLE_FWD_MAX - int(DELTA_FORWARD * 0.2)

REVERSE_SLOW = DUTY_CYCLE_RVS_MAX + int(DELTA_REVERSE * 0.8) 
REVERSE_MED = DUTY_CYCLE_RVS_MAX + int(DELTA_REVERSE * 0.5) 
REVERSE_FAST = DUTY_CYCLE_RVS_MAX + int(DELTA_REVERSE * 0.2) 


i2c = busio.I2C(SCL, SDA)
motorController = PCA9685(i2c)
motorController.frequency = 400

availableI2C = [0,1,2,3,4,5]

mappedI2C = [-1, -1, -1, -1, -1, -1]


def __speedFn(x : float) -> int:
    return int(DELTA_FORWARD * x + DUTY_CYCLE_STP)


def SetMotorSpeed(motorSpeedMagnitude : float, motorChannel: int = 0):
    duty_cycle = __speedFn(motorSpeedMagnitude)
    motorController.channels[motorChannel].duty_cycle = duty_cycle

def PrintMotorMap():
    output = "motor number : i2c channel\n"
    output += "LEFT  |///FRONT///| RIGHT\n"
    output += f"5 : {mappedI2C[5]} |///////////| 0 : {mappedI2C[0]}\n"
    output += f"4 : {mappedI2C[4]} |///////////| 1 : {mappedI2C[1]}\n"
    output += f"3 : {mappedI2C[3]} |///////////| 2 : {mappedI2C[2]}\n"

    print(output)


def WriteMapToFile():
    configPath = os.getcwd()

    wsIndex = configPath.find("ros2_ws")

    configPath = configPath[0:wsIndex] + "ros2_ws/config/motor_config/motorconfig.csv"

    with open(configPath,"w") as outputFile:
        outputStr = ""

        motorNumber = 0
        for i2cChannel in mappedI2C:
            outputStr += f"{motorNumber},{i2cChannel}\n"
            motorNumber += 1
        
        outputFile.write(outputStr)
    
    print(f"motor configuration written to \"{configPath}\"")



def main():
    for i in range(6):
        SetMotorSpeed(0.0, i)

    for i in range (6):
        print("current motor map:\n")
        PrintMotorMap()
        print(f"motor to map to: {i}")

        correctChannel = -1

        for channel in availableI2C:
            SetMotorSpeed(0.0,channel)
            time.sleep(0.5)
            SetMotorSpeed(0.5,channel)
            response = ""

            while not (response == "y" or response == "n"):
                response = input(f"running channel {channel}, does this run the correct motor {i}? [y/n]: ").lower()
            
            if(response == "y"):
                print(f"mapping motor {i} to i2c channel {channel}")
                correctChannel = channel
                mappedI2C[i] = channel
                SetMotorSpeed(0.0,channel)

                break
            else:
                print("running next available channel")
                SetMotorSpeed(0.0,channel)
        if(correctChannel == -1):
            print(f"error, no channel found for motor {i}, make sure all the motors are connected and try again\nReturning...")
            return
        else:
            availableI2C.remove(correctChannel)
    print("all channels mapped")

    PrintMotorMap()

    motorController.deinit()
    i2c.deinit()

    WriteMapToFile()





if __name__ == '__main__':
    main()

            



        





