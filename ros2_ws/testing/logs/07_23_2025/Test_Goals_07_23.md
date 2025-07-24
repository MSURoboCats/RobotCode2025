# TESTING GOALS: 07/23

## TODO
- Create Launch File for PID Testing (include motor stuff, depth_controller, and depth_publisher)


## GOALS
1. Tune Depth PID Loop to be within motor values (-1.0 to 1.0)
    - Determine depth sensor noise values for pool

2. if time allows, test navigator buoy node


### Testing procedure: PID Depth tuning
1. Place sub in water, use keyboard control node or partner to move sub to a few feet below the water
2. launch depth publisher node and record data for stationary sub for ~ 30 seconds, close the node so results are stored in log file
3. re-launch depth publisher node and launch depth controller node.
4. Using manual PID tuning method [https://en.wikipedia.org/wiki/Proportional%E2%80%93integral%E2%80%93derivative_controller#Manual_tuning] test different k values until desireable outputs (ranging from -1 to 1) are acheived


### Testing Notes / Addendum: 

Try calibrating depth sensor, gives wonkey readings (-1.5 at surface)

PID Depth control works, but instead of having it shutdown once the target depth is reached, it might be better to have it maintain the target depth by keeping it constantly running. The only issue I see with this is the integral term causing the sub to drift from the target depth. However, if you look at the [chart](./logs/pid_graph.png) it seems that the sub slows down as it approaches the target (motor powers approach 0) so this might not be too big an issue.