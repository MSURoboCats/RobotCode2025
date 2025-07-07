// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:action/DetectionAction.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__ACTION__DETAIL__DETECTION_ACTION__STRUCT_H_
#define CUSTOM_INTERFACES__ACTION__DETAIL__DETECTION_ACTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'depth_image'
#include "sensor_msgs/msg/detail/image__struct.h"
// Member 'camera_info'
#include "sensor_msgs/msg/detail/camera_info__struct.h"
// Member 'detections'
#include "custom_interfaces/msg/detail/detection_buffer__struct.h"

/// Struct defined in action/DetectionAction in the package custom_interfaces.
typedef struct custom_interfaces__action__DetectionAction_Goal
{
  sensor_msgs__msg__Image depth_image;
  sensor_msgs__msg__CameraInfo camera_info;
  custom_interfaces__msg__DetectionBuffer detections;
} custom_interfaces__action__DetectionAction_Goal;

// Struct for a sequence of custom_interfaces__action__DetectionAction_Goal.
typedef struct custom_interfaces__action__DetectionAction_Goal__Sequence
{
  custom_interfaces__action__DetectionAction_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__action__DetectionAction_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'points'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in action/DetectionAction in the package custom_interfaces.
typedef struct custom_interfaces__action__DetectionAction_Result
{
  geometry_msgs__msg__Point__Sequence points;
} custom_interfaces__action__DetectionAction_Result;

// Struct for a sequence of custom_interfaces__action__DetectionAction_Result.
typedef struct custom_interfaces__action__DetectionAction_Result__Sequence
{
  custom_interfaces__action__DetectionAction_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__action__DetectionAction_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'mask'
// already included above
// #include "sensor_msgs/msg/detail/image__struct.h"

/// Struct defined in action/DetectionAction in the package custom_interfaces.
typedef struct custom_interfaces__action__DetectionAction_Feedback
{
  sensor_msgs__msg__Image mask;
} custom_interfaces__action__DetectionAction_Feedback;

// Struct for a sequence of custom_interfaces__action__DetectionAction_Feedback.
typedef struct custom_interfaces__action__DetectionAction_Feedback__Sequence
{
  custom_interfaces__action__DetectionAction_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__action__DetectionAction_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "custom_interfaces/action/detail/detection_action__struct.h"

/// Struct defined in action/DetectionAction in the package custom_interfaces.
typedef struct custom_interfaces__action__DetectionAction_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  custom_interfaces__action__DetectionAction_Goal goal;
} custom_interfaces__action__DetectionAction_SendGoal_Request;

// Struct for a sequence of custom_interfaces__action__DetectionAction_SendGoal_Request.
typedef struct custom_interfaces__action__DetectionAction_SendGoal_Request__Sequence
{
  custom_interfaces__action__DetectionAction_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__action__DetectionAction_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/DetectionAction in the package custom_interfaces.
typedef struct custom_interfaces__action__DetectionAction_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} custom_interfaces__action__DetectionAction_SendGoal_Response;

// Struct for a sequence of custom_interfaces__action__DetectionAction_SendGoal_Response.
typedef struct custom_interfaces__action__DetectionAction_SendGoal_Response__Sequence
{
  custom_interfaces__action__DetectionAction_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__action__DetectionAction_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/DetectionAction in the package custom_interfaces.
typedef struct custom_interfaces__action__DetectionAction_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} custom_interfaces__action__DetectionAction_GetResult_Request;

// Struct for a sequence of custom_interfaces__action__DetectionAction_GetResult_Request.
typedef struct custom_interfaces__action__DetectionAction_GetResult_Request__Sequence
{
  custom_interfaces__action__DetectionAction_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__action__DetectionAction_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "custom_interfaces/action/detail/detection_action__struct.h"

/// Struct defined in action/DetectionAction in the package custom_interfaces.
typedef struct custom_interfaces__action__DetectionAction_GetResult_Response
{
  int8_t status;
  custom_interfaces__action__DetectionAction_Result result;
} custom_interfaces__action__DetectionAction_GetResult_Response;

// Struct for a sequence of custom_interfaces__action__DetectionAction_GetResult_Response.
typedef struct custom_interfaces__action__DetectionAction_GetResult_Response__Sequence
{
  custom_interfaces__action__DetectionAction_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__action__DetectionAction_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "custom_interfaces/action/detail/detection_action__struct.h"

/// Struct defined in action/DetectionAction in the package custom_interfaces.
typedef struct custom_interfaces__action__DetectionAction_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  custom_interfaces__action__DetectionAction_Feedback feedback;
} custom_interfaces__action__DetectionAction_FeedbackMessage;

// Struct for a sequence of custom_interfaces__action__DetectionAction_FeedbackMessage.
typedef struct custom_interfaces__action__DetectionAction_FeedbackMessage__Sequence
{
  custom_interfaces__action__DetectionAction_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__action__DetectionAction_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__ACTION__DETAIL__DETECTION_ACTION__STRUCT_H_
