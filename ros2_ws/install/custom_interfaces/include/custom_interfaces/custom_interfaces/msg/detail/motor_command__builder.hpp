// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/MotorCommand.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/motor_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_MotorCommand_motor_cmds
{
public:
  Init_MotorCommand_motor_cmds()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::msg::MotorCommand motor_cmds(::custom_interfaces::msg::MotorCommand::_motor_cmds_type arg)
  {
    msg_.motor_cmds = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::MotorCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::MotorCommand>()
{
  return custom_interfaces::msg::builder::Init_MotorCommand_motor_cmds();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__BUILDER_HPP_
