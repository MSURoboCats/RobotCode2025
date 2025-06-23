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
// Member 'obj_type'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/DetectionAction in the package custom_interfaces.
typedef struct custom_interfaces__action__DetectionAction_Goal
{
  rosidl_runtime_c__String obj_type;
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
// Member 'bboxes'
#include "custom_interfaces/msg/detail/bounding_box__struct.h"

/// Struct defined in action/DetectionAction in the package custom_interfaces.
typedef struct custom_interfaces__action__DetectionAction_Result
{
  custom_interfaces__msg__BoundingBox__Sequence bboxes;
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
// Member 'current_detection'
// already included above
// #include "custom_interfaces/msg/detail/bounding_box__struct.h"

/// Struct defined in action/DetectionAction in the package custom_interfaces.
typedef struct custom_interfaces__action__DetectionAction_Feedback
{
  bool bbox_exists;
  custom_interfaces__msg__BoundingBox current_detection;
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
