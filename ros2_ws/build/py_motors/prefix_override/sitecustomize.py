import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/robocats/Desktop/RobotCode2025/ros2_ws/install/py_motors'
