import adafruit_bno055
import busio
import board
import math

import time


MODE_SWITCH_TIME_SECONDS = 0.019 + 0.01 #0.019 is the time it takes to switch from any mode to config mode

# i2c = busio.I2C(board.SCL, board.SDA)

# print(f"i2c addr are: SCL = {board.SCL} SDA = {board.SDA}")


# bno = adafruit_bno055.BNO055_I2C(i2c)


# bno.mode = adafruit_bno055.NDOF_MODE

# time.sleep(MODE_SWITCH_TIME_SECONDS)

i2c = busio.I2C(board.SCL, board.SDA)
bno = adafruit_bno055.BNO055_I2C(i2c)


print(f"BNO i2c addr is {bno.i2c_device.device_address}")




# returns the fused linear acceleration (m/s^2),orientation  (quaternion) (rad), euler angles (vec3) (rad) ,and angular acceleration (rad/s) as a tuple (accel., orient., euler, angular.)
def GetFusionData():
    
    
    v_acceleration = bno.linear_acceleration

    #print(f"Quat (w,x,y,z) {bno.quaternion[0]} {bno.quaternion[1]} {bno.quaternion[2]} {bno.quaternion[3]}")

    q_rotation = bno.quaternion 

    #print(f"Euler Angles (x,y,z) (deg):  {bno.euler[0]}, {bno.euler[1]}, {bno.euler[2]}")

    e_rotation : tuple[float, float,float]

    if(bno.euler[0] is None):
        e_rotation = (-1.0,-1.0,-1.0)

    else: e_rotation = (math.radians(bno.euler[0]), math.radians(bno.euler[1]), math.radians(bno.euler[2]))

    v_angular_acceleration = bno.gyro

    data = (v_acceleration,q_rotation,e_rotation,v_angular_acceleration)
    return data 

#returns the raw acceleration (m/s) and gyro (rad/s) data (both length 3 tuples) as a tuple (accel, gyro)
def GetRawData():

    v_accel = bno.acceleration
    v_rot = bno.gyro

    data = (v_accel, v_rot)
    return data


