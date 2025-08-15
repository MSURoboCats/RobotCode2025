# TESTING GOALS 08/05

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
- Testing was a success, heading controller works acceptably for most angles, but struggles in a few edge cases. The most major of these edge cases being caused by the gyro counting angles in a unit circle that goes from 0 to 2pi rads.
    - Due to the non-static nature of the pool, the sub is prone to oscilating around 0pi radians, which can cause the orientation sensor to flip from ~0 to ~2pi radians very rapidly.
    - This confuses the PID, which has no way of knowing that going from 0pi radians to 29pi/15 radians is a very small jump relative to the unit circle, causing huge errors that freak the sub out
    - Theoretically, this would only happen around 0 degrees, meaning that a possible fix would just be to check if the robot is in the first quadrant of the unit circle and the angle it wants to rotate to is within the 4th quadrant. If so, treat the current angle as if it were 2pi + the current angle
