// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:msg/HeadingResult.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__HEADING_RESULT__STRUCT_H_
#define CUSTOM_INTERFACES__MSG__DETAIL__HEADING_RESULT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'text'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/HeadingResult in the package custom_interfaces.
typedef struct custom_interfaces__msg__HeadingResult
{
  rosidl_runtime_c__String text;
  double average_error;
} custom_interfaces__msg__HeadingResult;

// Struct for a sequence of custom_interfaces__msg__HeadingResult.
typedef struct custom_interfaces__msg__HeadingResult__Sequence
{
  custom_interfaces__msg__HeadingResult * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__msg__HeadingResult__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__HEADING_RESULT__STRUCT_H_
