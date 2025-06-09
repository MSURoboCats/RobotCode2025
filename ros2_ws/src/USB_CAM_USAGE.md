# USB_CAM_USAGE.MD

## USB_CAM INTEGRATION

usb_cam integration works by reading data from the "image_raw" topic published by the "usb_cam_node_exe" node in the usb_cam package.

By default, the camera reads from the camera located "/dev/video0". However, this can be modified by specifying a different camera in params.yaml and running the command 
"ros2 run usb_cam usb_cam_node_exe --ros-args --params-file <path_to_colcon_ws>/src/usb_cam/config/params.yaml"

You can view the image output of the cameras by using rqt_image_view:
"ros2 run rqt_image_view rqt_image_view"

### MULTIPLE CAMERAS

You can launch multiple camera nodes by remapping the namespace, the following commands launch nodes that read from seperate cameras:

ros2 run usb_cam usb_cam_node_exe --ros-args --remap __ns:=/usb_cam_0 --params-file <path_to_colcon_ws>/src/usb_cam/config/params_forward_camera.yaml
ros2 run usb_cam usb_cam_node_exe --ros-args --remap __ns:=/usb_cam_1 --params-file <path_to_colcon_ws>/src/usb_cam/config/params_bottom_camera.yaml

remapping the nodes like this changes the topics that they output to (image_raw is split into usb_cam_0/image_raw & usb_cam_1/image_raw)


## CAMERA LOCATIONS 

/dev/video0 - Down Facing Camera
/dev/video4 - Front Facing Camera (upside down due to installation)



## LINKS:
1. https://github.com/ros-drivers/usb_cam/blob/main/README.md [USB CAM GIT REPO]
2. https://docs.ros.org/en/noetic/api/sensor_msgs/html/msg/Image.html [IMAGE MESSAGE INTERFACE]
