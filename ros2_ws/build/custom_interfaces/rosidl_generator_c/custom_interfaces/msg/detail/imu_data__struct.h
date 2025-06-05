// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:msg/ImuData.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__IMU_DATA__STRUCT_H_
#define CUSTOM_INTERFACES__MSG__DETAIL__IMU_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'orientation'
#include "geometry_msgs/msg/detail/quaternion__struct.h"
// Member 'angular_velocity'
// Member 'linear_acceleration'
#include "geometry_msgs/msg/detail/vector3__struct.h"

/// Struct defined in msg/ImuData in the package custom_interfaces.
/**
  * Current time in relation to the Unix/POSIX epoch
 */
typedef struct custom_interfaces__msg__ImuData
{
  double global_time_seconds;
  /// Gyro orientation as a Quaternion (rad)
  geometry_msgs__msg__Quaternion orientation;
  /// Angular Velocity (rad/s)
  geometry_msgs__msg__Vector3 angular_velocity;
  /// Linear Acceleration (m/s^2)
  geometry_msgs__msg__Vector3 linear_acceleration;
} custom_interfaces__msg__ImuData;

// Struct for a sequence of custom_interfaces__msg__ImuData.
typedef struct custom_interfaces__msg__ImuData__Sequence
{
  custom_interfaces__msg__ImuData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__msg__ImuData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__IMU_DATA__STRUCT_H_
