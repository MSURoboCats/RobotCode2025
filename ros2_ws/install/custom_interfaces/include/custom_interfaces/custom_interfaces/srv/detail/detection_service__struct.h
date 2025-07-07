// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:srv/DetectionService.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__DETECTION_SERVICE__STRUCT_H_
#define CUSTOM_INTERFACES__SRV__DETAIL__DETECTION_SERVICE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/DetectionService in the package custom_interfaces.
typedef struct custom_interfaces__srv__DetectionService_Request
{
  uint8_t structure_needs_at_least_one_member;
} custom_interfaces__srv__DetectionService_Request;

// Struct for a sequence of custom_interfaces__srv__DetectionService_Request.
typedef struct custom_interfaces__srv__DetectionService_Request__Sequence
{
  custom_interfaces__srv__DetectionService_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__srv__DetectionService_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'detections'
#include "custom_interfaces/msg/detail/detection_buffer__struct.h"

/// Struct defined in srv/DetectionService in the package custom_interfaces.
typedef struct custom_interfaces__srv__DetectionService_Response
{
  custom_interfaces__msg__DetectionBuffer detections;
} custom_interfaces__srv__DetectionService_Response;

// Struct for a sequence of custom_interfaces__srv__DetectionService_Response.
typedef struct custom_interfaces__srv__DetectionService_Response__Sequence
{
  custom_interfaces__srv__DetectionService_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__srv__DetectionService_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__DETECTION_SERVICE__STRUCT_H_
