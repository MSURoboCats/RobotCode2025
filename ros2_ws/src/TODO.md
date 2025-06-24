# TODO.MD


## 1 PY_SENSORS
1. IMU data [DONE]
2. Depth data [DONE]
3. Launch File [DONE]
4. Cameras [DONE | SEE: usb_cam]


## 2 DRIVE MOTORS
### MOTOR NOTES:
The current motor command pipeline goes as follows:
		
	1. Motion_Director publishes a MotionGoal, this could be anything from killing all motors to running full speed ahead.
	2. Motor_Conductor receives these commands and turns them into individual motor commands (eg. stop thrust, forward thrust, reverse thrust).
	3. These motor commands are received by Motor_Controller, which turns these commands into individual duty cycles for the motors.

This works, but isnt the best implimentation as it doesnt allow for fine-tuned control over the robot's speed. 
A better implimentation would be to map the duty cycle as a range from -1 to 1, with -1 being full reverse and 1 being full forward

The function for such a relation would be:
> f(x) = delta_duty_cycle * x + duty_cycle_stop

## 3 ROBOT MOVEMENT (NOT NAVIGATION)

### SUMMARY
As outlined in [Notes.md](Notes.md), the only reliable method we have of transversal is through old-timey nautical navigation (aka Heuristics). 
I need to adjust the navigation to rely on vision instead of dead reckoning.

1. OBJECT DETECTION [DONE]
2. DISTANCE CALCUATION

<!-- This only works if we have a better accelerometer -->
<!-- ### SUMMARY: 
As outlined in Notes.md, the goal is to have the robot move from coordinate to coordinate like verticies in a graph.

This is all well and good, but how do we move from vertex to vertex in a safe and efficient fashion? 

We need a controller that can somehow calculate the required duty cycle to bring us to a certain position. 

[TODO]: Look into PID Controllers
https://gamzeyilan1.medium.com/pid-controller-for-absolute-beginners-4a49c58c8098  -->


## ADDITIONAL PROBLEMS

### THE SINGLE VIEWPOINT PROBLEM

Problem: How do we calculate the distance to the camera from a single viewpoint?

Possible solution: calculate distance using known properties. 
- https://www.reddit.com/r/computervision/comments/1ciot5j/is_it_possible_to_calculate_the_distance_of_an/

