import adafruit_bno055
import busio
import board
import math

import time


MODE_SWITCH_TIME_SECONDS = 0.019 + 0.01 #0.019 is the time it takes to switch from any mode to config mode

i2c = busio.I2C(board.SCL, board.SDA)


bno = adafruit_bno055.BNO055_I2C(i2c)

# returns the fused linear acceleration (m/s^2),orientation (rad) ,and angular acceleration (rad/s) as a tuple (accel., orient., angular.)
def GetFusionData():
    if(bno.mode != adafruit_bno055.NDOF_MODE):
        bno.mode = adafruit_bno055.NDOF_MODE
        time.sleep(MODE_SWITCH_TIME_SECONDS)
    
    v_acceleration = bno.linear_acceleration
    v_rotation = (math.radians(bno.euler[0]),math.radians(bno.euler[1]),math.radians(bno.euler[2]))

    v_angular_acceleration = bno.gyro

    data = (v_acceleration,v_rotation,v_angular_acceleration)
    return data 

#returns the raw acceleration (m/s) and gyro (rad/s) data (both length 3 tuples) as a tuple (accel, gyro)
def GetRawData():

    v_accel = bno.acceleration
    v_rot = bno.gyro

    data = (v_accel, v_rot)
    return data


