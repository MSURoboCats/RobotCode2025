from launch import LaunchDescription
from launch_ros.actions import Node 


GLOBAL_NAMESPACE = 'heading_pid_tuning'

def generate_launch_description():
    return LaunchDescription([
        
        ## py_motors
        Node(
            package = 'py_motors',
            namespace = GLOBAL_NAMESPACE,
            executable = 'motor_controller'
        ),
        Node(
            package = 'py_motors',
            namespace = GLOBAL_NAMESPACE,
            executable = 'motor_conductor'
        ),
        Node(
            package = 'py_motors',
            namespace = GLOBAL_NAMESPACE,
            executable = 'heading_controller'
        ),
       
        



    ])