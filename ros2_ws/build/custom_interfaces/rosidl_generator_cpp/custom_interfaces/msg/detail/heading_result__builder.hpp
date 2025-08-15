// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/HeadingResult.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__HEADING_RESULT__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__HEADING_RESULT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/heading_result__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_HeadingResult_average_error
{
public:
  explicit Init_HeadingResult_average_error(::custom_interfaces::msg::HeadingResult & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::msg::HeadingResult average_error(::custom_interfaces::msg::HeadingResult::_average_error_type arg)
  {
    msg_.average_error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::HeadingResult msg_;
};

class Init_HeadingResult_text
{
public:
  Init_HeadingResult_text()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HeadingResult_average_error text(::custom_interfaces::msg::HeadingResult::_text_type arg)
  {
    msg_.text = std::move(arg);
    return Init_HeadingResult_average_error(msg_);
  }

private:
  ::custom_interfaces::msg::HeadingResult msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::HeadingResult>()
{
  return custom_interfaces::msg::builder::Init_HeadingResult_text();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__HEADING_RESULT__BUILDER_HPP_
