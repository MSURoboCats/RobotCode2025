// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_interfaces:srv/GenerateWorldMap.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__GENERATE_WORLD_MAP__TRAITS_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__GENERATE_WORLD_MAP__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_interfaces/srv/detail/generate_world_map__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GenerateWorldMap_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GenerateWorldMap_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GenerateWorldMap_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace custom_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_interfaces::srv::GenerateWorldMap_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::srv::GenerateWorldMap_Request & msg)
{
  return custom_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::srv::GenerateWorldMap_Request>()
{
  return "custom_interfaces::srv::GenerateWorldMap_Request";
}

template<>
inline const char * name<custom_interfaces::srv::GenerateWorldMap_Request>()
{
  return "custom_interfaces/srv/GenerateWorldMap_Request";
}

template<>
struct has_fixed_size<custom_interfaces::srv::GenerateWorldMap_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<custom_interfaces::srv::GenerateWorldMap_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<custom_interfaces::srv::GenerateWorldMap_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'out_map'
#include "custom_interfaces/msg/detail/world_map__traits.hpp"

namespace custom_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GenerateWorldMap_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: out_map
  {
    out << "out_map: ";
    to_flow_style_yaml(msg.out_map, out);
    out << ", ";
  }

  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GenerateWorldMap_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: out_map
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "out_map:\n";
    to_block_style_yaml(msg.out_map, out, indentation + 2);
  }

  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GenerateWorldMap_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace custom_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_interfaces::srv::GenerateWorldMap_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::srv::GenerateWorldMap_Response & msg)
{
  return custom_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::srv::GenerateWorldMap_Response>()
{
  return "custom_interfaces::srv::GenerateWorldMap_Response";
}

template<>
inline const char * name<custom_interfaces::srv::GenerateWorldMap_Response>()
{
  return "custom_interfaces/srv/GenerateWorldMap_Response";
}

template<>
struct has_fixed_size<custom_interfaces::srv::GenerateWorldMap_Response>
  : std::integral_constant<bool, has_fixed_size<custom_interfaces::msg::WorldMap>::value> {};

template<>
struct has_bounded_size<custom_interfaces::srv::GenerateWorldMap_Response>
  : std::integral_constant<bool, has_bounded_size<custom_interfaces::msg::WorldMap>::value> {};

template<>
struct is_message<custom_interfaces::srv::GenerateWorldMap_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_interfaces::srv::GenerateWorldMap>()
{
  return "custom_interfaces::srv::GenerateWorldMap";
}

template<>
inline const char * name<custom_interfaces::srv::GenerateWorldMap>()
{
  return "custom_interfaces/srv/GenerateWorldMap";
}

template<>
struct has_fixed_size<custom_interfaces::srv::GenerateWorldMap>
  : std::integral_constant<
    bool,
    has_fixed_size<custom_interfaces::srv::GenerateWorldMap_Request>::value &&
    has_fixed_size<custom_interfaces::srv::GenerateWorldMap_Response>::value
  >
{
};

template<>
struct has_bounded_size<custom_interfaces::srv::GenerateWorldMap>
  : std::integral_constant<
    bool,
    has_bounded_size<custom_interfaces::srv::GenerateWorldMap_Request>::value &&
    has_bounded_size<custom_interfaces::srv::GenerateWorldMap_Response>::value
  >
{
};

template<>
struct is_service<custom_interfaces::srv::GenerateWorldMap>
  : std::true_type
{
};

template<>
struct is_service_request<custom_interfaces::srv::GenerateWorldMap_Request>
  : std::true_type
{
};

template<>
struct is_service_response<custom_interfaces::srv::GenerateWorldMap_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__GENERATE_WORLD_MAP__TRAITS_HPP_
