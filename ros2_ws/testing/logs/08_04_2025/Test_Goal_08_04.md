# TESTING GOALS 08/04

## GOALS
1. Tune heading controller to have reasonable values 
2. If time allows, test navigator node


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
- PID might not be the best for heading control, look into alternitives
- The sub tends to overshoot the target as it still has rotational velocity even after reaching the target
- heading needs to be maintained 
- PID control values make sense, it wants the sub to rotate in the correct direction along the unit circle when negated, however, the motor powers should themsemselves be negated as to acheive the correct direction for said powers
(essentially the control value should be equal to non-negated value of the PID output) 