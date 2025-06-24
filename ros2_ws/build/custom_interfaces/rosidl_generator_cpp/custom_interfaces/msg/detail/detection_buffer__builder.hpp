// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/DetectionBuffer.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__DETECTION_BUFFER__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__DETECTION_BUFFER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/detection_buffer__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_DetectionBuffer_detections
{
public:
  Init_DetectionBuffer_detections()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::msg::DetectionBuffer detections(::custom_interfaces::msg::DetectionBuffer::_detections_type arg)
  {
    msg_.detections = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::DetectionBuffer msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::DetectionBuffer>()
{
  return custom_interfaces::msg::builder::Init_DetectionBuffer_detections();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__DETECTION_BUFFER__BUILDER_HPP_
