from launch import LaunchDescription
from launch_ros.actions import Node 



def generate_launch_description():
    return LaunchDescription([
        Node(
            package='realsense2_camera',
            executable='realsense2_camera_node',
            parameters=[
                {'align_depth.enable' : True},
                {'unite_imu_method' : 1}
            ]
        ),
       

    ])
