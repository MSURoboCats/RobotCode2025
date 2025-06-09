from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    return LaunchDescription([
        Node( ## launch imu (BNO055)
            package='py_sensors',
            namespace='sensors',
            executable='imu'
        ),
        Node( ## launch bar02
            package='py_sensors',
            namespace='sensors',
            executable='bar02'
        ),
        Node(
            package='usb_cam',
            namespace='sensors/usb0',
            executable='usb_cam_node_exe',
            name='usb_cam_0',
            parameters=[PathJoinSubstitution([
                FindPackageShare('usb_cam'), 'config', 'params_forward_camera.yaml'])
            ]
        ),
        Node(
            package='usb_cam',
            namespace='sensors/usb1',
            executable='usb_cam_node_exe',
            name='usb_cam_1',
            parameters=[PathJoinSubstitution([
                FindPackageShare('usb_cam'), 'config', 'params_bottom_camera.yaml'])
            ]
        )

    ])
