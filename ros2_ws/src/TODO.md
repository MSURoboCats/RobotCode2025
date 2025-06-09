# TODO.MD


## 1 PY_SENSORS
1. IMU data [DONE]
2. Depth data [DONE]
3. Launch File [DONE]
4. Cameras [IN PROGRESS]
	- Publish camera data using ros2 opencv pipeline
	- see: https://www.geeksforgeeks.org/opencv-python-tutorial/#1-getting-started for more info


## 2 DRIVE MOTORS
### MOTOR NOTES:
The current motor command pipeline goes as follows:
	- Motion_Director publishes a MotionGoal, this could be anything from killing all motors to running full speed ahead
	- Motor_Conductor receives these commands and turns them into individual motor commands (eg. stop thrust, forward thrust, reverse thrust)
	- These motor commands are received by Motor_Controller, which turns these commands into individual duty cycles for the motors

What I would like to do is to extend (or supercede) motion_director with a "command stream" 

Essentially I want to be able to have a list of commands and have them be fed to the drive motor pipeline 

One way to acheive this is through actions. 




CAMERA NOTES:

Problem: How do we calculate the distance to the camera from a single viewpoint 


https://www.reddit.com/r/computervision/comments/1ciot5j/is_it_possible_to_calculate_the_distance_of_an/

