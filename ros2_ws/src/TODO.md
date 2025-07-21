# TODO.MD
- 3d navigation 
	- figure out how to work 3d navigation, start at the pool and get the robot to move towards a target, then program more complex actions



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


## 3 OBJECT DETECTION USING REALSENSE CAMERA
### SUMMARY 
Intel provides a pre-built ros2 node that interfaces with the realsense sdk [Repo](https://github.com/IntelRealSense/realsense-ros).
The node can be configured with a bunch of parameters. 

The basic run command goes as follows: 
ros2 run realsense2_camera realsense2_camera_node

To have the depth image be aligned to the color image by setting the parameter "align_depth.enable" to "True" from which a new topic is created called "aligned_depth_to_color/image_raw" which can be subscribed to

To have the imu data be published from one topic, set the parameter unite_imu_method to one of the following:

1 = copy (current gyro state followed by last acceleration state)
2 = linear_interp (current gyro state followed by acceleration that has been linearly interped to the gyro timestamp)

from this a new topic is created camera/imu

all these parameters combined would look something like "ros2 run realsense2_camera realsense2_camera_node --ros-args -p align_depth.enable:=True unite_imu_method:=[1 or 2]

### TODO
1. Find out how to make depth_image gathering asynchronous from the service stuff, or find a way to ensure that depth_image data is gathered before calling the service stuff
	- Possibly make depth_image gatheringh a seperate service, which can then be found in the chain-link style found int DItM_tester.py

### NOTES
The default node publishes imu data as well as color, depth, and infrared images

aligning the depth image to the color image means that they share the same vectorspace, meaning no matrix multiplication is required to translate between the two spaces

Determining distance from a object using this camera can be boiled down into individual steps:
#### Pre-req steps
1. Have Point Streaming Enabled
2. Align depth and color cameras

#### Algorithm
Inputs = Bounding boxes (Detection Buffer), Depth Image (either depth/image_compressed or depth/image_raw)

Outputs = 3d AABB (AABB array) 
1. Detect object in image stream using yolo, and get its screen-space bbox
2. Get depth image, convert it to an array, and get pixels within bbox
3. Convert 2d depth values into 3d points and construct AABB (see book: Real Time Collision Detection)
4. Store AABB in memory as object, update as needed using collision detection 

#### Links / Helpful Resources
1. [OpenCV::rgbd::depthTo3d(image, k, out 3dPoints, optional mask = noArray())](https://docs.opencv.org/4.x/d2/d3a/group__rgbd.html#ga403eeb581b09684f7e24f7c157086dd6)
	- Helpful function found in the contrib module rgbd, takes in the depth image, the camera calibration matrix (found in depth/camera_info.k, and a output array of 3d points, optionally you can specify a mask of points to consider)
2. [Open3D](https://www.open3d.org/docs/0.18.0/getting_started.html)
	- 3d vision library that I used for creating the 3d map



## 4 ROBOT MOVEMENT (NOT NAVIGATION)

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

