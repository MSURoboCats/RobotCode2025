# TESTING GOALS 07/29

## GOALS

1. Tune Depth Sensor to give reasonable values 
2. Test Depth control for holding a certain depth
3. (If time allows) test navigator buoy test node

### Testing procedure: 
1. Place sub in water, let it float on the top of the water 
2. record depth value at top of water, add offset to depth sensor node, repeat steps 1-2 until depth sensor gives off reasonable readings 
3. Launch PID Testing nodes using the launch_PID_tuning.py launch file
4. manually call the PID depth service using the command found in section 5 of Todo.md 
5. see if sub will automatically stabilize at depth, if not edit PID Loop, starting with the KI values 



### Testing Notes / Addendum: 
Motor commands should be seperated into vertical and horizontal commands 

Heading controller should be made for controlling orientation of the sub
 
