// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:msg/AABB.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__AABB__STRUCT_H_
#define CUSTOM_INTERFACES__MSG__DETAIL__AABB__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'center'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'extents'
#include "geometry_msgs/msg/detail/vector3__struct.h"

/// Struct defined in msg/AABB in the package custom_interfaces.
/**
  * Axis Aligned Bounding Box
 */
typedef struct custom_interfaces__msg__AABB
{
  geometry_msgs__msg__Point center;
  geometry_msgs__msg__Vector3 extents;
} custom_interfaces__msg__AABB;

// Struct for a sequence of custom_interfaces__msg__AABB.
typedef struct custom_interfaces__msg__AABB__Sequence
{
  custom_interfaces__msg__AABB * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__msg__AABB__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__AABB__STRUCT_H_
