// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:action/NavigationGoal.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__ACTION__DETAIL__NAVIGATION_GOAL__STRUCT_H_
#define CUSTOM_INTERFACES__ACTION__DETAIL__NAVIGATION_GOAL__STRUCT_H_

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

/// Struct defined in action/NavigationGoal in the package custom_interfaces.
typedef struct custom_interfaces__action__NavigationGoal_Goal
{
  rosidl_runtime_c__String goal;
} custom_interfaces__action__NavigationGoal_Goal;

// Struct for a sequence of custom_interfaces__action__NavigationGoal_Goal.
typedef struct custom_interfaces__action__NavigationGoal_Goal__Sequence
{
  custom_interfaces__action__NavigationGoal_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__action__NavigationGoal_Goal__Sequence;


// Constants defined in the message

/// Struct defined in action/NavigationGoal in the package custom_interfaces.
typedef struct custom_interfaces__action__NavigationGoal_Result
{
  bool success;
} custom_interfaces__action__NavigationGoal_Result;

// Struct for a sequence of custom_interfaces__action__NavigationGoal_Result.
typedef struct custom_interfaces__action__NavigationGoal_Result__Sequence
{
  custom_interfaces__action__NavigationGoal_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__action__NavigationGoal_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'status'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/NavigationGoal in the package custom_interfaces.
typedef struct custom_interfaces__action__NavigationGoal_Feedback
{
  rosidl_runtime_c__String status;
} custom_interfaces__action__NavigationGoal_Feedback;

// Struct for a sequence of custom_interfaces__action__NavigationGoal_Feedback.
typedef struct custom_interfaces__action__NavigationGoal_Feedback__Sequence
{
  custom_interfaces__action__NavigationGoal_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__action__NavigationGoal_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "custom_interfaces/action/detail/navigation_goal__struct.h"

/// Struct defined in action/NavigationGoal in the package custom_interfaces.
typedef struct custom_interfaces__action__NavigationGoal_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  custom_interfaces__action__NavigationGoal_Goal goal;
} custom_interfaces__action__NavigationGoal_SendGoal_Request;

// Struct for a sequence of custom_interfaces__action__NavigationGoal_SendGoal_Request.
typedef struct custom_interfaces__action__NavigationGoal_SendGoal_Request__Sequence
{
  custom_interfaces__action__NavigationGoal_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__action__NavigationGoal_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/NavigationGoal in the package custom_interfaces.
typedef struct custom_interfaces__action__NavigationGoal_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} custom_interfaces__action__NavigationGoal_SendGoal_Response;

// Struct for a sequence of custom_interfaces__action__NavigationGoal_SendGoal_Response.
typedef struct custom_interfaces__action__NavigationGoal_SendGoal_Response__Sequence
{
  custom_interfaces__action__NavigationGoal_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__action__NavigationGoal_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/NavigationGoal in the package custom_interfaces.
typedef struct custom_interfaces__action__NavigationGoal_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} custom_interfaces__action__NavigationGoal_GetResult_Request;

// Struct for a sequence of custom_interfaces__action__NavigationGoal_GetResult_Request.
typedef struct custom_interfaces__action__NavigationGoal_GetResult_Request__Sequence
{
  custom_interfaces__action__NavigationGoal_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__action__NavigationGoal_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "custom_interfaces/action/detail/navigation_goal__struct.h"

/// Struct defined in action/NavigationGoal in the package custom_interfaces.
typedef struct custom_interfaces__action__NavigationGoal_GetResult_Response
{
  int8_t status;
  custom_interfaces__action__NavigationGoal_Result result;
} custom_interfaces__action__NavigationGoal_GetResult_Response;

// Struct for a sequence of custom_interfaces__action__NavigationGoal_GetResult_Response.
typedef struct custom_interfaces__action__NavigationGoal_GetResult_Response__Sequence
{
  custom_interfaces__action__NavigationGoal_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__action__NavigationGoal_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "custom_interfaces/action/detail/navigation_goal__struct.h"

/// Struct defined in action/NavigationGoal in the package custom_interfaces.
typedef struct custom_interfaces__action__NavigationGoal_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  custom_interfaces__action__NavigationGoal_Feedback feedback;
} custom_interfaces__action__NavigationGoal_FeedbackMessage;

// Struct for a sequence of custom_interfaces__action__NavigationGoal_FeedbackMessage.
typedef struct custom_interfaces__action__NavigationGoal_FeedbackMessage__Sequence
{
  custom_interfaces__action__NavigationGoal_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__action__NavigationGoal_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__ACTION__DETAIL__NAVIGATION_GOAL__STRUCT_H_
