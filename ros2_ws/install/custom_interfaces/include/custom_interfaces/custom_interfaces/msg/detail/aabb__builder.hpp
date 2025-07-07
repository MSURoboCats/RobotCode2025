// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/AABB.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__AABB__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__AABB__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/aabb__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_AABB_extents
{
public:
  explicit Init_AABB_extents(::custom_interfaces::msg::AABB & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::msg::AABB extents(::custom_interfaces::msg::AABB::_extents_type arg)
  {
    msg_.extents = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::AABB msg_;
};

class Init_AABB_center
{
public:
  Init_AABB_center()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AABB_extents center(::custom_interfaces::msg::AABB::_center_type arg)
  {
    msg_.center = std::move(arg);
    return Init_AABB_extents(msg_);
  }

private:
  ::custom_interfaces::msg::AABB msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::AABB>()
{
  return custom_interfaces::msg::builder::Init_AABB_center();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__AABB__BUILDER_HPP_
