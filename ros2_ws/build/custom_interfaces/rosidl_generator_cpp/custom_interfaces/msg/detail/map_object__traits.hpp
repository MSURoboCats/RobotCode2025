// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_interfaces:msg/MapObject.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__MAP_OBJECT__TRAITS_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__MAP_OBJECT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_interfaces/msg/detail/map_object__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'mesh'
#include "geometry_msgs/msg/detail/polygon__traits.hpp"
// Member 'aabb'
#include "custom_interfaces/msg/detail/aabb__traits.hpp"

namespace custom_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const MapObject & msg,
  std::ostream & out)
{
  out << "{";
  // member: mesh
  {
    out << "mesh: ";
    to_flow_style_yaml(msg.mesh, out);
    out << ", ";
  }

  // member: aabb
  {
    out << "aabb: ";
    to_flow_style_yaml(msg.aabb, out);
    out << ", ";
  }

  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MapObject & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: mesh
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mesh:\n";
    to_block_style_yaml(msg.mesh, out, indentation + 2);
  }

  // member: aabb
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "aabb:\n";
    to_block_style_yaml(msg.aabb, out, indentation + 2);
  }

  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MapObject & msg, bool use_flow_style = false)
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
  const custom_interfaces::msg::MapObject & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::msg::MapObject & msg)
{
  return custom_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::msg::MapObject>()
{
  return "custom_interfaces::msg::MapObject";
}

template<>
inline const char * name<custom_interfaces::msg::MapObject>()
{
  return "custom_interfaces/msg/MapObject";
}

template<>
struct has_fixed_size<custom_interfaces::msg::MapObject>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_interfaces::msg::MapObject>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_interfaces::msg::MapObject>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__MAP_OBJECT__TRAITS_HPP_
