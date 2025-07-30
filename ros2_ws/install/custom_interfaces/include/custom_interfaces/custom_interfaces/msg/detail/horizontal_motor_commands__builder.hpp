// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/HorizontalMotorCommands.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__HORIZONTAL_MOTOR_COMMANDS__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__HORIZONTAL_MOTOR_COMMANDS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/horizontal_motor_commands__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_HorizontalMotorCommands_throttles
{
public:
  explicit Init_HorizontalMotorCommands_throttles(::custom_interfaces::msg::HorizontalMotorCommands & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::msg::HorizontalMotorCommands throttles(::custom_interfaces::msg::HorizontalMotorCommands::_throttles_type arg)
  {
    msg_.throttles = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::HorizontalMotorCommands msg_;
};

class Init_HorizontalMotorCommands_motor_numbers
{
public:
  Init_HorizontalMotorCommands_motor_numbers()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HorizontalMotorCommands_throttles motor_numbers(::custom_interfaces::msg::HorizontalMotorCommands::_motor_numbers_type arg)
  {
    msg_.motor_numbers = std::move(arg);
    return Init_HorizontalMotorCommands_throttles(msg_);
  }

private:
  ::custom_interfaces::msg::HorizontalMotorCommands msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::HorizontalMotorCommands>()
{
  return custom_interfaces::msg::builder::Init_HorizontalMotorCommands_motor_numbers();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__HORIZONTAL_MOTOR_COMMANDS__BUILDER_HPP_
