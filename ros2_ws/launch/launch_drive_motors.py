from launch import LaunchDescription
from launch_ros.actions import Node 



def generate_launch_description():
    return LaunchDescription([
        Node(
            package='py_motors',
            namespace='motors',
            executable='motor_controller'
        ),
        Node(
            package='py_motors',
            namespace='motors',
            executable='motor_conductor'
        )

    ])
