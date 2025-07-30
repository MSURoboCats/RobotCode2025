// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:msg/VerticalMotorCommands.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__VERTICAL_MOTOR_COMMANDS__STRUCT_H_
#define CUSTOM_INTERFACES__MSG__DETAIL__VERTICAL_MOTOR_COMMANDS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/VerticalMotorCommands in the package custom_interfaces.
typedef struct custom_interfaces__msg__VerticalMotorCommands
{
  int16_t motor_numbers[2];
  double throttles[2];
} custom_interfaces__msg__VerticalMotorCommands;

// Struct for a sequence of custom_interfaces__msg__VerticalMotorCommands.
typedef struct custom_interfaces__msg__VerticalMotorCommands__Sequence
{
  custom_interfaces__msg__VerticalMotorCommands * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__msg__VerticalMotorCommands__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__VERTICAL_MOTOR_COMMANDS__STRUCT_H_
