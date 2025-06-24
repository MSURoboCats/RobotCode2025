// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from custom_interfaces:msg/DetectionBuffer.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "custom_interfaces/msg/detail/detection_buffer__rosidl_typesupport_introspection_c.h"
#include "custom_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "custom_interfaces/msg/detail/detection_buffer__functions.h"
#include "custom_interfaces/msg/detail/detection_buffer__struct.h"


// Include directives for member types
// Member `detections`
#include "custom_interfaces/msg/bounding_box.h"
// Member `detections`
#include "custom_interfaces/msg/detail/bounding_box__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void custom_interfaces__msg__DetectionBuffer__rosidl_typesupport_introspection_c__DetectionBuffer_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_interfaces__msg__DetectionBuffer__init(message_memory);
}

void custom_interfaces__msg__DetectionBuffer__rosidl_typesupport_introspection_c__DetectionBuffer_fini_function(void * message_memory)
{
  custom_interfaces__msg__DetectionBuffer__fini(message_memory);
}

size_t custom_interfaces__msg__DetectionBuffer__rosidl_typesupport_introspection_c__size_function__DetectionBuffer__detections(
  const void * untyped_member)
{
  const custom_interfaces__msg__BoundingBox__Sequence * member =
    (const custom_interfaces__msg__BoundingBox__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_interfaces__msg__DetectionBuffer__rosidl_typesupport_introspection_c__get_const_function__DetectionBuffer__detections(
  const void * untyped_member, size_t index)
{
  const custom_interfaces__msg__BoundingBox__Sequence * member =
    (const custom_interfaces__msg__BoundingBox__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_interfaces__msg__DetectionBuffer__rosidl_typesupport_introspection_c__get_function__DetectionBuffer__detections(
  void * untyped_member, size_t index)
{
  custom_interfaces__msg__BoundingBox__Sequence * member =
    (custom_interfaces__msg__BoundingBox__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_interfaces__msg__DetectionBuffer__rosidl_typesupport_introspection_c__fetch_function__DetectionBuffer__detections(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const custom_interfaces__msg__BoundingBox * item =
    ((const custom_interfaces__msg__BoundingBox *)
    custom_interfaces__msg__DetectionBuffer__rosidl_typesupport_introspection_c__get_const_function__DetectionBuffer__detections(untyped_member, index));
  custom_interfaces__msg__BoundingBox * value =
    (custom_interfaces__msg__BoundingBox *)(untyped_value);
  *value = *item;
}

void custom_interfaces__msg__DetectionBuffer__rosidl_typesupport_introspection_c__assign_function__DetectionBuffer__detections(
  void * untyped_member, size_t index, const void * untyped_value)
{
  custom_interfaces__msg__BoundingBox * item =
    ((custom_interfaces__msg__BoundingBox *)
    custom_interfaces__msg__DetectionBuffer__rosidl_typesupport_introspection_c__get_function__DetectionBuffer__detections(untyped_member, index));
  const custom_interfaces__msg__BoundingBox * value =
    (const custom_interfaces__msg__BoundingBox *)(untyped_value);
  *item = *value;
}

bool custom_interfaces__msg__DetectionBuffer__rosidl_typesupport_introspection_c__resize_function__DetectionBuffer__detections(
  void * untyped_member, size_t size)
{
  custom_interfaces__msg__BoundingBox__Sequence * member =
    (custom_interfaces__msg__BoundingBox__Sequence *)(untyped_member);
  custom_interfaces__msg__BoundingBox__Sequence__fini(member);
  return custom_interfaces__msg__BoundingBox__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember custom_interfaces__msg__DetectionBuffer__rosidl_typesupport_introspection_c__DetectionBuffer_message_member_array[1] = {
  {
    "detections",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces__msg__DetectionBuffer, detections),  // bytes offset in struct
    NULL,  // default value
    custom_interfaces__msg__DetectionBuffer__rosidl_typesupport_introspection_c__size_function__DetectionBuffer__detections,  // size() function pointer
    custom_interfaces__msg__DetectionBuffer__rosidl_typesupport_introspection_c__get_const_function__DetectionBuffer__detections,  // get_const(index) function pointer
    custom_interfaces__msg__DetectionBuffer__rosidl_typesupport_introspection_c__get_function__DetectionBuffer__detections,  // get(index) function pointer
    custom_interfaces__msg__DetectionBuffer__rosidl_typesupport_introspection_c__fetch_function__DetectionBuffer__detections,  // fetch(index, &value) function pointer
    custom_interfaces__msg__DetectionBuffer__rosidl_typesupport_introspection_c__assign_function__DetectionBuffer__detections,  // assign(index, value) function pointer
    custom_interfaces__msg__DetectionBuffer__rosidl_typesupport_introspection_c__resize_function__DetectionBuffer__detections  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers custom_interfaces__msg__DetectionBuffer__rosidl_typesupport_introspection_c__DetectionBuffer_message_members = {
  "custom_interfaces__msg",  // message namespace
  "DetectionBuffer",  // message name
  1,  // number of fields
  sizeof(custom_interfaces__msg__DetectionBuffer),
  custom_interfaces__msg__DetectionBuffer__rosidl_typesupport_introspection_c__DetectionBuffer_message_member_array,  // message members
  custom_interfaces__msg__DetectionBuffer__rosidl_typesupport_introspection_c__DetectionBuffer_init_function,  // function to initialize message memory (memory has to be allocated)
  custom_interfaces__msg__DetectionBuffer__rosidl_typesupport_introspection_c__DetectionBuffer_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t custom_interfaces__msg__DetectionBuffer__rosidl_typesupport_introspection_c__DetectionBuffer_message_type_support_handle = {
  0,
  &custom_interfaces__msg__DetectionBuffer__rosidl_typesupport_introspection_c__DetectionBuffer_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_interfaces, msg, DetectionBuffer)() {
  custom_interfaces__msg__DetectionBuffer__rosidl_typesupport_introspection_c__DetectionBuffer_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_interfaces, msg, BoundingBox)();
  if (!custom_interfaces__msg__DetectionBuffer__rosidl_typesupport_introspection_c__DetectionBuffer_message_type_support_handle.typesupport_identifier) {
    custom_interfaces__msg__DetectionBuffer__rosidl_typesupport_introspection_c__DetectionBuffer_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &custom_interfaces__msg__DetectionBuffer__rosidl_typesupport_introspection_c__DetectionBuffer_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
