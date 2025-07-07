from launch import LaunchDescription
from launch_ros.actions import Node 



def generate_launch_description():
    return LaunchDescription([
        Node(
            package='realsense2_camera',
            namespace='object_detection',
            executable='realsense2_camera_node',
            parameters=[
                {'align_depth.enable' : True}
            ]
        ),
    	Node(	
            package='py_objectdetection',
            namespace='object_detection',
            executable='detector',
            parameters=[
                {'topic' : 'camera/color/image_raw'},
                {'model_path' : 'ultralyticsplus/yolov8s.pt'},
                {'task' : 'detect'},
                {'filter' : 'all'}
            ]
    	),
        Node(
            package='py_objectdetection',
            namespace='object_detection',
            executable='mapper',
            parameters=[
                {'camera_info_topic' : 'camera/aligned_depth_to_color/camera_info'},
                {'depth_image_topic' : 'camera/aligned_depth_to_color/image_raw'},
                {'detection_buffer_topic' : 'DetectionBuffer'},
                {'published_topic_name' : 'WorldMap'},
                {'publish_rate_seconds' : 0.5}
            ]
        ),
       

    ])
