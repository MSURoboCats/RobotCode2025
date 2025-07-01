// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_interfaces:srv/DetectionService.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__DETECTION_SERVICE__TRAITS_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__DETECTION_SERVICE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_interfaces/srv/detail/detection_service__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'depth_image'
#include "sensor_msgs/msg/detail/image__traits.hpp"
// Member 'camera_info'
#include "sensor_msgs/msg/detail/camera_info__traits.hpp"
// Member 'detections'
#include "custom_interfaces/msg/detail/detection_buffer__traits.hpp"

namespace custom_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const DetectionService_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: depth_image
  {
    out << "depth_image: ";
    to_flow_style_yaml(msg.depth_image, out);
    out << ", ";
  }

  // member: camera_info
  {
    out << "camera_info: ";
    to_flow_style_yaml(msg.camera_info, out);
    out << ", ";
  }

  // member: detections
  {
    out << "detections: ";
    to_flow_style_yaml(msg.detections, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DetectionService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: depth_image
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "depth_image:\n";
    to_block_style_yaml(msg.depth_image, out, indentation + 2);
  }

  // member: camera_info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "camera_info:\n";
    to_block_style_yaml(msg.camera_info, out, indentation + 2);
  }

  // member: detections
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "detections:\n";
    to_block_style_yaml(msg.detections, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DetectionService_Request & msg, bool use_flow_style = false)
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
  const custom_interfaces::srv::DetectionService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::srv::DetectionService_Request & msg)
{
  return custom_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::srv::DetectionService_Request>()
{
  return "custom_interfaces::srv::DetectionService_Request";
}

template<>
inline const char * name<custom_interfaces::srv::DetectionService_Request>()
{
  return "custom_interfaces/srv/DetectionService_Request";
}

template<>
struct has_fixed_size<custom_interfaces::srv::DetectionService_Request>
  : std::integral_constant<bool, has_fixed_size<custom_interfaces::msg::DetectionBuffer>::value && has_fixed_size<sensor_msgs::msg::CameraInfo>::value && has_fixed_size<sensor_msgs::msg::Image>::value> {};

template<>
struct has_bounded_size<custom_interfaces::srv::DetectionService_Request>
  : std::integral_constant<bool, has_bounded_size<custom_interfaces::msg::DetectionBuffer>::value && has_bounded_size<sensor_msgs::msg::CameraInfo>::value && has_bounded_size<sensor_msgs::msg::Image>::value> {};

template<>
struct is_message<custom_interfaces::srv::DetectionService_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'meshes'
#include "geometry_msgs/msg/detail/polygon__traits.hpp"

namespace custom_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const DetectionService_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: meshes
  {
    if (msg.meshes.size() == 0) {
      out << "meshes: []";
    } else {
      out << "meshes: [";
      size_t pending_items = msg.meshes.size();
      for (auto item : msg.meshes) {
        to_flow_style_yaml(item, out);
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
  const DetectionService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: meshes
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.meshes.size() == 0) {
      out << "meshes: []\n";
    } else {
      out << "meshes:\n";
      for (auto item : msg.meshes) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DetectionService_Response & msg, bool use_flow_style = false)
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
  const custom_interfaces::srv::DetectionService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::srv::DetectionService_Response & msg)
{
  return custom_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::srv::DetectionService_Response>()
{
  return "custom_interfaces::srv::DetectionService_Response";
}

template<>
inline const char * name<custom_interfaces::srv::DetectionService_Response>()
{
  return "custom_interfaces/srv/DetectionService_Response";
}

template<>
struct has_fixed_size<custom_interfaces::srv::DetectionService_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_interfaces::srv::DetectionService_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_interfaces::srv::DetectionService_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_interfaces::srv::DetectionService>()
{
  return "custom_interfaces::srv::DetectionService";
}

template<>
inline const char * name<custom_interfaces::srv::DetectionService>()
{
  return "custom_interfaces/srv/DetectionService";
}

template<>
struct has_fixed_size<custom_interfaces::srv::DetectionService>
  : std::integral_constant<
    bool,
    has_fixed_size<custom_interfaces::srv::DetectionService_Request>::value &&
    has_fixed_size<custom_interfaces::srv::DetectionService_Response>::value
  >
{
};

template<>
struct has_bounded_size<custom_interfaces::srv::DetectionService>
  : std::integral_constant<
    bool,
    has_bounded_size<custom_interfaces::srv::DetectionService_Request>::value &&
    has_bounded_size<custom_interfaces::srv::DetectionService_Response>::value
  >
{
};

template<>
struct is_service<custom_interfaces::srv::DetectionService>
  : std::true_type
{
};

template<>
struct is_service_request<custom_interfaces::srv::DetectionService_Request>
  : std::true_type
{
};

template<>
struct is_service_response<custom_interfaces::srv::DetectionService_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__DETECTION_SERVICE__TRAITS_HPP_
