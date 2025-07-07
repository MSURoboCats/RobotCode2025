// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:msg/WorldMap.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__WORLD_MAP__STRUCT_H_
#define CUSTOM_INTERFACES__MSG__DETAIL__WORLD_MAP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'meshes'
#include "geometry_msgs/msg/detail/polygon__struct.h"

/// Struct defined in msg/WorldMap in the package custom_interfaces.
typedef struct custom_interfaces__msg__WorldMap
{
  geometry_msgs__msg__Polygon__Sequence meshes;
} custom_interfaces__msg__WorldMap;

// Struct for a sequence of custom_interfaces__msg__WorldMap.
typedef struct custom_interfaces__msg__WorldMap__Sequence
{
  custom_interfaces__msg__WorldMap * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__msg__WorldMap__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__WORLD_MAP__STRUCT_H_
