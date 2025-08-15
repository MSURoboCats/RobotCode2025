// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:srv/SetHeading.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__SET_HEADING__BUILDER_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__SET_HEADING__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/srv/detail/set_heading__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetHeading_Request_keep_heading_until_override
{
public:
  explicit Init_SetHeading_Request_keep_heading_until_override(::custom_interfaces::srv::SetHeading_Request & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::srv::SetHeading_Request keep_heading_until_override(::custom_interfaces::srv::SetHeading_Request::_keep_heading_until_override_type arg)
  {
    msg_.keep_heading_until_override = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::SetHeading_Request msg_;
};

class Init_SetHeading_Request_heading
{
public:
  Init_SetHeading_Request_heading()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetHeading_Request_keep_heading_until_override heading(::custom_interfaces::srv::SetHeading_Request::_heading_type arg)
  {
    msg_.heading = std::move(arg);
    return Init_SetHeading_Request_keep_heading_until_override(msg_);
  }

private:
  ::custom_interfaces::srv::SetHeading_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::SetHeading_Request>()
{
  return custom_interfaces::srv::builder::Init_SetHeading_Request_heading();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetHeading_Response_success
{
public:
  Init_SetHeading_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::srv::SetHeading_Response success(::custom_interfaces::srv::SetHeading_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::SetHeading_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::SetHeading_Response>()
{
  return custom_interfaces::srv::builder::Init_SetHeading_Response_success();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__SET_HEADING__BUILDER_HPP_
