// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:srv/SetDepth.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__SET_DEPTH__STRUCT_H_
#define CUSTOM_INTERFACES__SRV__DETAIL__SET_DEPTH__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/SetDepth in the package custom_interfaces.
typedef struct custom_interfaces__srv__SetDepth_Request
{
  double depth;
} custom_interfaces__srv__SetDepth_Request;

// Struct for a sequence of custom_interfaces__srv__SetDepth_Request.
typedef struct custom_interfaces__srv__SetDepth_Request__Sequence
{
  custom_interfaces__srv__SetDepth_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__srv__SetDepth_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/SetDepth in the package custom_interfaces.
typedef struct custom_interfaces__srv__SetDepth_Response
{
  bool success;
} custom_interfaces__srv__SetDepth_Response;

// Struct for a sequence of custom_interfaces__srv__SetDepth_Response.
typedef struct custom_interfaces__srv__SetDepth_Response__Sequence
{
  custom_interfaces__srv__SetDepth_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__srv__SetDepth_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__SET_DEPTH__STRUCT_H_
