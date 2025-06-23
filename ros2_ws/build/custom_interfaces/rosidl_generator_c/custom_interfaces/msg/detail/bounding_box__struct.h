// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:msg/BoundingBox.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__BOUNDING_BOX__STRUCT_H_
#define CUSTOM_INTERFACES__MSG__DETAIL__BOUNDING_BOX__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/BoundingBox in the package custom_interfaces.
/**
  * bounding box parameters in pixels (width, height, center X, center Y)
 */
typedef struct custom_interfaces__msg__BoundingBox
{
  rosidl_runtime_c__String name;
  int32_t width;
  int32_t height;
  int32_t center_x;
  int32_t center_y;
  /// Yolov8 confidence value for this bbox
  float conf;
} custom_interfaces__msg__BoundingBox;

// Struct for a sequence of custom_interfaces__msg__BoundingBox.
typedef struct custom_interfaces__msg__BoundingBox__Sequence
{
  custom_interfaces__msg__BoundingBox * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__msg__BoundingBox__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__BOUNDING_BOX__STRUCT_H_
