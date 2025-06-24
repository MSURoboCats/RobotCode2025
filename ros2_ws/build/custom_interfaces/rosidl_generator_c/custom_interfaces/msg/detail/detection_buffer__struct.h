// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:msg/DetectionBuffer.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__DETECTION_BUFFER__STRUCT_H_
#define CUSTOM_INTERFACES__MSG__DETAIL__DETECTION_BUFFER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'detections'
#include "custom_interfaces/msg/detail/bounding_box__struct.h"

/// Struct defined in msg/DetectionBuffer in the package custom_interfaces.
typedef struct custom_interfaces__msg__DetectionBuffer
{
  custom_interfaces__msg__BoundingBox__Sequence detections;
} custom_interfaces__msg__DetectionBuffer;

// Struct for a sequence of custom_interfaces__msg__DetectionBuffer.
typedef struct custom_interfaces__msg__DetectionBuffer__Sequence
{
  custom_interfaces__msg__DetectionBuffer * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__msg__DetectionBuffer__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__DETECTION_BUFFER__STRUCT_H_
