// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/DepthReport.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__DEPTH_REPORT__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__DEPTH_REPORT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/depth_report__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_DepthReport_temperature
{
public:
  explicit Init_DepthReport_temperature(::custom_interfaces::msg::DepthReport & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::msg::DepthReport temperature(::custom_interfaces::msg::DepthReport::_temperature_type arg)
  {
    msg_.temperature = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::DepthReport msg_;
};

class Init_DepthReport_pressure
{
public:
  explicit Init_DepthReport_pressure(::custom_interfaces::msg::DepthReport & msg)
  : msg_(msg)
  {}
  Init_DepthReport_temperature pressure(::custom_interfaces::msg::DepthReport::_pressure_type arg)
  {
    msg_.pressure = std::move(arg);
    return Init_DepthReport_temperature(msg_);
  }

private:
  ::custom_interfaces::msg::DepthReport msg_;
};

class Init_DepthReport_depth
{
public:
  Init_DepthReport_depth()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DepthReport_pressure depth(::custom_interfaces::msg::DepthReport::_depth_type arg)
  {
    msg_.depth = std::move(arg);
    return Init_DepthReport_pressure(msg_);
  }

private:
  ::custom_interfaces::msg::DepthReport msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::DepthReport>()
{
  return custom_interfaces::msg::builder::Init_DepthReport_depth();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__DEPTH_REPORT__BUILDER_HPP_
