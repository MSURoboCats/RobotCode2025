// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:srv/DetectionService.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__DETECTION_SERVICE__BUILDER_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__DETECTION_SERVICE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/srv/detail/detection_service__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_DetectionService_Request_detections
{
public:
  explicit Init_DetectionService_Request_detections(::custom_interfaces::srv::DetectionService_Request & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::srv::DetectionService_Request detections(::custom_interfaces::srv::DetectionService_Request::_detections_type arg)
  {
    msg_.detections = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::DetectionService_Request msg_;
};

class Init_DetectionService_Request_camera_info
{
public:
  explicit Init_DetectionService_Request_camera_info(::custom_interfaces::srv::DetectionService_Request & msg)
  : msg_(msg)
  {}
  Init_DetectionService_Request_detections camera_info(::custom_interfaces::srv::DetectionService_Request::_camera_info_type arg)
  {
    msg_.camera_info = std::move(arg);
    return Init_DetectionService_Request_detections(msg_);
  }

private:
  ::custom_interfaces::srv::DetectionService_Request msg_;
};

class Init_DetectionService_Request_depth_image
{
public:
  Init_DetectionService_Request_depth_image()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DetectionService_Request_camera_info depth_image(::custom_interfaces::srv::DetectionService_Request::_depth_image_type arg)
  {
    msg_.depth_image = std::move(arg);
    return Init_DetectionService_Request_camera_info(msg_);
  }

private:
  ::custom_interfaces::srv::DetectionService_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::DetectionService_Request>()
{
  return custom_interfaces::srv::builder::Init_DetectionService_Request_depth_image();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_DetectionService_Response_meshes
{
public:
  Init_DetectionService_Response_meshes()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::srv::DetectionService_Response meshes(::custom_interfaces::srv::DetectionService_Response::_meshes_type arg)
  {
    msg_.meshes = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::DetectionService_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::DetectionService_Response>()
{
  return custom_interfaces::srv::builder::Init_DetectionService_Response_meshes();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__DETECTION_SERVICE__BUILDER_HPP_
