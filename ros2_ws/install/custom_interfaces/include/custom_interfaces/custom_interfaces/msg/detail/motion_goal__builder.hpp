// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/MotionGoal.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__MOTION_GOAL__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__MOTION_GOAL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/motion_goal__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_MotionGoal_keep_unmodified_throttles
{
public:
  explicit Init_MotionGoal_keep_unmodified_throttles(::custom_interfaces::msg::MotionGoal & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::msg::MotionGoal keep_unmodified_throttles(::custom_interfaces::msg::MotionGoal::_keep_unmodified_throttles_type arg)
  {
    msg_.keep_unmodified_throttles = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::MotionGoal msg_;
};

class Init_MotionGoal_goal
{
public:
  Init_MotionGoal_goal()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotionGoal_keep_unmodified_throttles goal(::custom_interfaces::msg::MotionGoal::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return Init_MotionGoal_keep_unmodified_throttles(msg_);
  }

private:
  ::custom_interfaces::msg::MotionGoal msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::MotionGoal>()
{
  return custom_interfaces::msg::builder::Init_MotionGoal_goal();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__MOTION_GOAL__BUILDER_HPP_
