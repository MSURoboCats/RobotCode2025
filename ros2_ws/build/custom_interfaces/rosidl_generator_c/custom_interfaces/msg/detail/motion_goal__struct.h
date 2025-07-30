// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:msg/MotionGoal.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__MOTION_GOAL__STRUCT_H_
#define CUSTOM_INTERFACES__MSG__DETAIL__MOTION_GOAL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'goal'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/MotionGoal in the package custom_interfaces.
typedef struct custom_interfaces__msg__MotionGoal
{
  rosidl_runtime_c__String goal;
  bool keep_unmodified_throttles;
} custom_interfaces__msg__MotionGoal;

// Struct for a sequence of custom_interfaces__msg__MotionGoal.
typedef struct custom_interfaces__msg__MotionGoal__Sequence
{
  custom_interfaces__msg__MotionGoal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__msg__MotionGoal__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__MOTION_GOAL__STRUCT_H_
