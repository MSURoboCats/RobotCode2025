// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:msg/MapObject.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__MAP_OBJECT__STRUCT_H_
#define CUSTOM_INTERFACES__MSG__DETAIL__MAP_OBJECT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'mesh'
#include "geometry_msgs/msg/detail/polygon__struct.h"
// Member 'aabb'
#include "custom_interfaces/msg/detail/aabb__struct.h"

/// Struct defined in msg/MapObject in the package custom_interfaces.
typedef struct custom_interfaces__msg__MapObject
{
  geometry_msgs__msg__Polygon mesh;
  custom_interfaces__msg__AABB aabb;
} custom_interfaces__msg__MapObject;

// Struct for a sequence of custom_interfaces__msg__MapObject.
typedef struct custom_interfaces__msg__MapObject__Sequence
{
  custom_interfaces__msg__MapObject * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__msg__MapObject__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__MAP_OBJECT__STRUCT_H_
