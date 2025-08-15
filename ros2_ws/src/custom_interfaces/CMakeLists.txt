cmake_minimum_required(VERSION 3.8)
project(custom_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)

find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
	"msg/ImuData.msg"
	"msg/DepthReport.msg"
	"msg/MotionGoal.msg"
	"msg/MotorCommand.msg"
	"msg/HorizontalMotorCommands.msg"
	"msg/VerticalMotorCommands.msg"
	"msg/BoundingBox.msg"
	"msg/DetectionBuffer.msg"
	"msg/AABB.msg"
	"msg/WorldMap.msg"
	"msg/MapObject.msg"
	"msg/HeadingResult.msg"
	"srv/GenerateWorldMap.srv"
	"srv/DetectionService.srv"
	"srv/SetDepth.srv"
	"srv/SetHeading.srv"
	"action/DetectionAction.action"
	"action/NavigationGoal.action"
	
	DEPENDENCIES geometry_msgs sensor_msgs std_msgs
)


ament_package()
