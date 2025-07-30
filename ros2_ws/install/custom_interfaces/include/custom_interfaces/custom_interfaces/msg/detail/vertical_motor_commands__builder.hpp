// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/VerticalMotorCommands.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__VERTICAL_MOTOR_COMMANDS__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__VERTICAL_MOTOR_COMMANDS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/vertical_motor_commands__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_VerticalMotorCommands_throttles
{
public:
  explicit Init_VerticalMotorCommands_throttles(::custom_interfaces::msg::VerticalMotorCommands & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::msg::VerticalMotorCommands throttles(::custom_interfaces::msg::VerticalMotorCommands::_throttles_type arg)
  {
    msg_.throttles = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::VerticalMotorCommands msg_;
};

class Init_VerticalMotorCommands_motor_numbers
{
public:
  Init_VerticalMotorCommands_motor_numbers()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VerticalMotorCommands_throttles motor_numbers(::custom_interfaces::msg::VerticalMotorCommands::_motor_numbers_type arg)
  {
    msg_.motor_numbers = std::move(arg);
    return Init_VerticalMotorCommands_throttles(msg_);
  }

private:
  ::custom_interfaces::msg::VerticalMotorCommands msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::VerticalMotorCommands>()
{
  return custom_interfaces::msg::builder::Init_VerticalMotorCommands_motor_numbers();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__VERTICAL_MOTOR_COMMANDS__BUILDER_HPP_
