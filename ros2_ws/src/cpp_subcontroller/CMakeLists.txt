cmake_minimum_required(VERSION 3.8)
project(cpp_subcontroller)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

find_package(rclcpp REQUIRED)
find_package(custom_interfaces REQUIRED)

add_executable(motion_director src/MotionDirector.cpp)

ament_target_dependencies(motion_director rclcpp custom_interfaces)

install(TARGETS
  motion_director
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
