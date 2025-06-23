// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/BoundingBox.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__BOUNDING_BOX__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__BOUNDING_BOX__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/bounding_box__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_BoundingBox_conf
{
public:
  explicit Init_BoundingBox_conf(::custom_interfaces::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::msg::BoundingBox conf(::custom_interfaces::msg::BoundingBox::_conf_type arg)
  {
    msg_.conf = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::BoundingBox msg_;
};

class Init_BoundingBox_center_y
{
public:
  explicit Init_BoundingBox_center_y(::custom_interfaces::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_conf center_y(::custom_interfaces::msg::BoundingBox::_center_y_type arg)
  {
    msg_.center_y = std::move(arg);
    return Init_BoundingBox_conf(msg_);
  }

private:
  ::custom_interfaces::msg::BoundingBox msg_;
};

class Init_BoundingBox_center_x
{
public:
  explicit Init_BoundingBox_center_x(::custom_interfaces::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_center_y center_x(::custom_interfaces::msg::BoundingBox::_center_x_type arg)
  {
    msg_.center_x = std::move(arg);
    return Init_BoundingBox_center_y(msg_);
  }

private:
  ::custom_interfaces::msg::BoundingBox msg_;
};

class Init_BoundingBox_height
{
public:
  explicit Init_BoundingBox_height(::custom_interfaces::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_center_x height(::custom_interfaces::msg::BoundingBox::_height_type arg)
  {
    msg_.height = std::move(arg);
    return Init_BoundingBox_center_x(msg_);
  }

private:
  ::custom_interfaces::msg::BoundingBox msg_;
};

class Init_BoundingBox_width
{
public:
  explicit Init_BoundingBox_width(::custom_interfaces::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_height width(::custom_interfaces::msg::BoundingBox::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_BoundingBox_height(msg_);
  }

private:
  ::custom_interfaces::msg::BoundingBox msg_;
};

class Init_BoundingBox_name
{
public:
  Init_BoundingBox_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BoundingBox_width name(::custom_interfaces::msg::BoundingBox::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_BoundingBox_width(msg_);
  }

private:
  ::custom_interfaces::msg::BoundingBox msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::BoundingBox>()
{
  return custom_interfaces::msg::builder::Init_BoundingBox_name();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__BOUNDING_BOX__BUILDER_HPP_
