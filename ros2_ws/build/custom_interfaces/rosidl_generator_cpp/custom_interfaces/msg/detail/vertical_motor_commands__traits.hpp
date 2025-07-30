// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_interfaces:msg/VerticalMotorCommands.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__VERTICAL_MOTOR_COMMANDS__TRAITS_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__VERTICAL_MOTOR_COMMANDS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_interfaces/msg/detail/vertical_motor_commands__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const VerticalMotorCommands & msg,
  std::ostream & out)
{
  out << "{";
  // member: motor_numbers
  {
    if (msg.motor_numbers.size() == 0) {
      out << "motor_numbers: []";
    } else {
      out << "motor_numbers: [";
      size_t pending_items = msg.motor_numbers.size();
      for (auto item : msg.motor_numbers) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: throttles
  {
    if (msg.throttles.size() == 0) {
      out << "throttles: []";
    } else {
      out << "throttles: [";
      size_t pending_items = msg.throttles.size();
      for (auto item : msg.throttles) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const VerticalMotorCommands & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: motor_numbers
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.motor_numbers.size() == 0) {
      out << "motor_numbers: []\n";
    } else {
      out << "motor_numbers:\n";
      for (auto item : msg.motor_numbers) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: throttles
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.throttles.size() == 0) {
      out << "throttles: []\n";
    } else {
      out << "throttles:\n";
      for (auto item : msg.throttles) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const VerticalMotorCommands & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace custom_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_interfaces::msg::VerticalMotorCommands & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::msg::VerticalMotorCommands & msg)
{
  return custom_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::msg::VerticalMotorCommands>()
{
  return "custom_interfaces::msg::VerticalMotorCommands";
}

template<>
inline const char * name<custom_interfaces::msg::VerticalMotorCommands>()
{
  return "custom_interfaces/msg/VerticalMotorCommands";
}

template<>
struct has_fixed_size<custom_interfaces::msg::VerticalMotorCommands>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<custom_interfaces::msg::VerticalMotorCommands>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<custom_interfaces::msg::VerticalMotorCommands>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__VERTICAL_MOTOR_COMMANDS__TRAITS_HPP_
