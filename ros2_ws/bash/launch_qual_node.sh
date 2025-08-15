#!/bin/bash

## needed: launch_pid_tuning, realsense ros camera, launch heading_pid_tuning, imu sensor with remap

# run object detection
#ros2 launch launch/launch_heading_PID_tuning.py & 

sleep 1

gnome-terminal \
    --tab --title="camera" \
        -- bash -c 'cd /home/robocatsorin/Desktop/RobotCode2025/ros2_ws; source install/setup.bash; ros2 run realsense2_camera realsense2_camera_node --ros-args -p align_depth.enable:=True -p unite_imu_method:=1; bash'

gnome-terminal \
    --tab --title="heading_pid" \
        -- bash -c 'cd /home/robocatsorin/Desktop/RobotCode2025/ros2_ws; source install/setup.bash; ros2 launch launch/launch_heading_PID_tuning.py; bash'

sleep 1

gnome-terminal \
    --tab --title="depth_pid" \
        -- bash -c 'cd /home/robocatsorin/Desktop/RobotCode2025/ros2_ws; source install/setup.bash; ros2 launch launch/launch_PID_tuning.py; bash'


sleep 2
gnome-terminal \
    --tab --title="orientation_sensor" \
        -- bash -c 'cd /home/robocatsorin/Desktop/RobotCode2025/ros2_ws; source install/setup.bash; ros2 run py_sensors imu --ros-args -r __ns:=/heading_pid_tuning; bash'


gnome-terminal \
    --tab --title="task_node" \
        -- bash -c 'cd /home/robocatsorin/Desktop/RobotCode2025/ros2_ws; source install/setup.bash; ros2 run py_subcontroller coin_flip; bash'