# TESTING GOALS 08/08

## GOALS
1. Test heading controller over new edge cases
2. Test navigator node


### Testing procedure: 
1. Place sub in water, move it a safe distance (~3 feet) away from any walls or obstructions
2. For safety, ensure that the heading controller node has a reasonable maximum / minimum allowed motor power (0.25 is the limit)
3. Launch the nodes needed to run the heading controller using the launch_heading_PID_tuning.py launch file.
    - Launch imu sensor manually AFTER running the launch file, otherwise there will be i2c errors.
    - use the command "ros2 run py_sensors imu --ros-args -r __ns:=/heading_pid_tuning"
4. Call heading service manually, set the desired heading to be within 30 / -30 degrees of the original heading.
    - use command "ros2 service call /heading_pid_tuning/set_heading custom_interfaces/srv/SetHeading "{heading: [x, y, z], keep_heading_until_override: True/False}""
5. Shutdown all launched nodes and consult log files for heading controller, tune PID loop as needed 
6. Repeat steps 4-5, until PID loop acceptable.
7. Repeat steps 4-6, increasing the absolute angle difference by 30 degrees. 


### Testing Notes / Addendum: 
 
