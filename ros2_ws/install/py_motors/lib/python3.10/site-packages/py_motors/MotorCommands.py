import time 
import board 
import busio

from enum import Enum
from board import SCL, SDA
from adafruit_motor import motor
from adafruit_pca9685 import PCA9685

### SPEED STUFF

DUTY_CYCLE_STP = int(65535 * 1.6/2.5)
DUTY_CYCLE_FWD_MAX = int(65535 * 1.9/2.5)
DUTY_CYCLE_RVS_MAX = int(65535 * 1.1/2.5)

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

### MOTOR CHANNELS NUMBER 0 - 5 (pwm 1 - 6)



class MotorState(Enum):
    STOPPED = 0
    FORWARD = 1
    REVERSE = 2

class MotorSpeed(Enum):
    SLOW = 0
    MEDIUM = 1
    FAST = 2

def SetMotorState(motorState, speedSetting = MotorSpeed.SLOW, motorChannel = 0):
    match motorState:
        case MotorState.STOPPED:
            InvokeStopCommand(motorChannel)
            return
        case MotorState.FORWARD:
            InvokeForwardCommand(speedSetting, motorChannel)
            return
        case MotorState.REVERSE:
            InvokeReverseCommand(speedSetting,motorChannel)
            return
        

def InvokeForwardCommand(speedSetting, motorChannel):
    spd = FORWARD_SLOW
    if(speedSetting == MotorSpeed.SLOW) : spd = FORWARD_SLOW
    elif(speedSetting == MotorSpeed.MEDIUM) : spd = FORWARD_MED
    elif(speedSetting == MotorSpeed.FAST) : spd = FORWARD_FAST

    motorController.channels[motorChannel].duty_cycle = spd

def InvokeStopCommand(motorChannel):
    motorController.channels[motorChannel].duty_cycle = DUTY_CYCLE_STP

def InvokeReverseCommand(speedSetting, motorChannel):
    spd = REVERSE_SLOW
    if(speedSetting == MotorSpeed.SLOW) : spd = REVERSE_SLOW
    elif(speedSetting == MotorSpeed.MEDIUM) : spd = REVERSE_MED
    elif(speedSetting == MotorSpeed.FAST) : spd = REVERSE_FAST

    motorController.channels[motorChannel].duty_cycle = spd

def CleanupMotor():
    print("Cleaning up motor \n")
    for i in range(6):
        motorController.channels[i].duty_cycle = DUTY_CYCLE_STP

    motorController.deinit()
    i2c.deinit()

def InitMotor():
    motorController.frequency = 400 

    for i in range(6):
        motorController.channels[i].duty_cycle = DUTY_CYCLE_STP


    time.sleep(2)
    print("Motor Initialized...\n")

