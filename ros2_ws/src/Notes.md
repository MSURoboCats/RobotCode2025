# NOTES.md


## ROBOT ARCHETECTURE
At a high level, the main robot director, a theoretical action client node, sends a action goal to the robot state machine (e.g. find_gate, do_gate_task,etc).

the state machine internalizes this goal and fires off a series of commands to relevant subsystem nodes (eg navigator)

### Navigator Node
The navigator node is responsible for moving the robot for both inter and intra-task navigation. Implimentation wise, this is a state machine that runs different motor commands depending on the scenario.

ROS-wise, this could be implimented as an action, where the navigation node is a action server, and overall robot state machine a client

<!-- This goal is internalized and acted upon. If the task requires movement, the navigator node can take the destination point and plot a course to that point. This can be done a variety of ways, one of the most promising methods is to create a 3d map of the course, overlay a graph onto this map, and prune any verticies that collide with obsticals on the map. Transversing this map could then be done via A*, Dijkstra's or other graph transversal algorithms. -->

<!-- This method doesnt really work as the only method we have of determining absolute positon is IMU data from the BNO055, unfortunatly, this data is very innacurate for linear acceleration, and so we might have to instead rely on heuristics . -->

    

## THE DISTANCE PROBLEM

### Overview

In order to determine the distance to a "known object" we must first be able to: 
1. Get image from camera with object
2. Detect said object
3. Get the pixel width of said object
4. Perform the distance calclation fn 




## NAVIGATION 

### Notes From Testing
From testing, using lidar at a distance underwater leads to large amounts noise. As such, we must rely on object recognition via machine learning (ML) to detect targets at a distance The sub rotates until the target is found, then approaches the target until it takes up a good portion of the FOV, then the sub switches to lidar-based detection.

With lidar, we can create accurate headings based on the position of other objects.


### What we can determine from heuristics (Vision & gyro)
1. Distance to "known objects" (objects with known dimensions) [Reddit Post](https://www.reddit.com/r/computervision/comments/1ciot5j/is_it_possible_to_calculate_the_distance_of_an/)
2. Orientation
3. Heading (avg acceleration values over a short period)
4. Depth
- For navigation, we can rely on the techniques that sailors used before gps 
- [Task Handbook](https://robonation.gitbook.io/robosub-resources/section-3-autonomy-challenge/3.2-task-descriptions)

### Inter-Task Navigation
For inter-task navigation we can use [1] to determine our distance from a specific task, and then drive to that task while keeping in mind our distance, orientation, and heading [2,3].

### Intra-Task Navigation
For intra-trask navigation, we will rely more on [2] and [3] but still use [1]. Thankfully all tasks have known objects that we can use to navigate within them.

### TASKS

#### [Coin Flip](https://robonation.gitbook.io/robosub-resources/section-3-autonomy-challenge/3.2-task-descriptions#id-3.2.1-heading-out-coin-flip)

- Always take the coin flip, we can submerge to whatever depth we desire and then rotate CCW turn until we see the gate.

#### [Gate](https://robonation.gitbook.io/robosub-resources/section-3-autonomy-challenge/3.2-task-descriptions#id-3.2.2-task-1-collecting-data-gate)

- The gate task is by far the simplest, we can use the x-y distance from the center bar and one of the side bars to determine the heading needed to traverse under one of the sides.

#### [Slalom](https://robonation.gitbook.io/robosub-resources/section-3-autonomy-challenge/3.2-task-descriptions#id-3.2.3-task-2-navigate-the-channel-slalom)

- A good model for this task would be [boids](https://en.wikipedia.org/wiki/Boids). While we cant know the exact position of each slalom pair, we can still aim for the center of pairs we can see using vision. 
- Also, the sub in this case would act much like a boid, possesing a constant forward velocity and having to adjust its heading to avoid obstacles
- We'd have to align ourselves first, making sure the red pole is between two white poles relative to the sub

#### [Bin](https://robonation.gitbook.io/robosub-resources/section-3-autonomy-challenge/3.2-task-descriptions#id-3.2.4-task-3-drop-a-bruvs-bin)

- The bin is one of the more difficult tasks. First you must identify the bin, swim over the bin until the bottom camera identifies it, the orient the dropper so the markers land on the right side. 

#### [Torpedos](https://robonation.gitbook.io/robosub-resources/section-3-autonomy-challenge/3.2-task-descriptions#id-3.2.5-task-4-tagging-torpedoes)

- For the torpedos, we must identify which opening is closest to the animal we chose, then fire through it.
- Alternitively, we can just focus on firing through the holes without caring about fish orientation


#### [Octagon](https://robonation.gitbook.io/robosub-resources/section-3-autonomy-challenge/3.2-task-descriptions#id-3.2.6-task-5-ocean-cleanup-octagon)

- TBD


#### [Return](https://robonation.gitbook.io/robosub-resources/section-3-autonomy-challenge/3.2-task-descriptions#id-3.2.7-task-6-return-home)

- TBD





