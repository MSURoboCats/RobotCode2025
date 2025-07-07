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


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::DetectionService_Request>()
{
  return ::custom_interfaces::srv::DetectionService_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_DetectionService_Response_detections
{
public:
  Init_DetectionService_Response_detections()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::srv::DetectionService_Response detections(::custom_interfaces::srv::DetectionService_Response::_detections_type arg)
  {
    msg_.detections = std::move(arg);
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
  return custom_interfaces::srv::builder::Init_DetectionService_Response_detections();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__DETECTION_SERVICE__BUILDER_HPP_
