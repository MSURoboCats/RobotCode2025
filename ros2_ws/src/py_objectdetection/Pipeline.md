# PIPELINE.MD

## RGBD IMAGE TO 3D OBJECT PIPELINE
1. detection_publisher detects objects in RGB realsense camera and creates detection buffer (bounding box array).
2. depth_image_to_map node takes current depth image and detection buffer, it then creates seperate depth images containing individual detections. 
3. these individual depth images are transformed into meshes / point cloud groups, which are then combined into a mesh buffer
4. this mesh buffer is then used to create a map, with objects placed relative to the initial camera position





<!-- ### Archetecture OLD 

detection_publisher:
    services:
        get_current_frame: DetectionBuffer
    subscriptions:
        rgb_image_source: Image
    publishes:
        Detection_Buffer: DetectionBuffer

depth_image_to_map:
    services:
        Generate_New_Map(DetectionBuffer db, Image depth_image): WorldMap
    subscriptions:
        depth_camera_info: CameraInfo
    publishes:
        map_cache: WorldMap


    




  -->