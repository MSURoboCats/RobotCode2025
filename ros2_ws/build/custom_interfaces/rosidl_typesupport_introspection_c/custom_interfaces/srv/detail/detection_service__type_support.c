// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from custom_interfaces:srv/DetectionService.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "custom_interfaces/srv/detail/detection_service__rosidl_typesupport_introspection_c.h"
#include "custom_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "custom_interfaces/srv/detail/detection_service__functions.h"
#include "custom_interfaces/srv/detail/detection_service__struct.h"


// Include directives for member types
// Member `depth_image`
#include "sensor_msgs/msg/image.h"
// Member `depth_image`
#include "sensor_msgs/msg/detail/image__rosidl_typesupport_introspection_c.h"
// Member `camera_info`
#include "sensor_msgs/msg/camera_info.h"
// Member `camera_info`
#include "sensor_msgs/msg/detail/camera_info__rosidl_typesupport_introspection_c.h"
// Member `detections`
#include "custom_interfaces/msg/detection_buffer.h"
// Member `detections`
#include "custom_interfaces/msg/detail/detection_buffer__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void custom_interfaces__srv__DetectionService_Request__rosidl_typesupport_introspection_c__DetectionService_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_interfaces__srv__DetectionService_Request__init(message_memory);
}

void custom_interfaces__srv__DetectionService_Request__rosidl_typesupport_introspection_c__DetectionService_Request_fini_function(void * message_memory)
{
  custom_interfaces__srv__DetectionService_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember custom_interfaces__srv__DetectionService_Request__rosidl_typesupport_introspection_c__DetectionService_Request_message_member_array[3] = {
  {
    "depth_image",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces__srv__DetectionService_Request, depth_image),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "camera_info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces__srv__DetectionService_Request, camera_info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "detections",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces__srv__DetectionService_Request, detections),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers custom_interfaces__srv__DetectionService_Request__rosidl_typesupport_introspection_c__DetectionService_Request_message_members = {
  "custom_interfaces__srv",  // message namespace
  "DetectionService_Request",  // message name
  3,  // number of fields
  sizeof(custom_interfaces__srv__DetectionService_Request),
  custom_interfaces__srv__DetectionService_Request__rosidl_typesupport_introspection_c__DetectionService_Request_message_member_array,  // message members
  custom_interfaces__srv__DetectionService_Request__rosidl_typesupport_introspection_c__DetectionService_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  custom_interfaces__srv__DetectionService_Request__rosidl_typesupport_introspection_c__DetectionService_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t custom_interfaces__srv__DetectionService_Request__rosidl_typesupport_introspection_c__DetectionService_Request_message_type_support_handle = {
  0,
  &custom_interfaces__srv__DetectionService_Request__rosidl_typesupport_introspection_c__DetectionService_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_interfaces, srv, DetectionService_Request)() {
  custom_interfaces__srv__DetectionService_Request__rosidl_typesupport_introspection_c__DetectionService_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, Image)();
  custom_interfaces__srv__DetectionService_Request__rosidl_typesupport_introspection_c__DetectionService_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, CameraInfo)();
  custom_interfaces__srv__DetectionService_Request__rosidl_typesupport_introspection_c__DetectionService_Request_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_interfaces, msg, DetectionBuffer)();
  if (!custom_interfaces__srv__DetectionService_Request__rosidl_typesupport_introspection_c__DetectionService_Request_message_type_support_handle.typesupport_identifier) {
    custom_interfaces__srv__DetectionService_Request__rosidl_typesupport_introspection_c__DetectionService_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &custom_interfaces__srv__DetectionService_Request__rosidl_typesupport_introspection_c__DetectionService_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "custom_interfaces/srv/detail/detection_service__rosidl_typesupport_introspection_c.h"
// already included above
// #include "custom_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "custom_interfaces/srv/detail/detection_service__functions.h"
// already included above
// #include "custom_interfaces/srv/detail/detection_service__struct.h"


// Include directives for member types
// Member `meshes`
#include "geometry_msgs/msg/polygon.h"
// Member `meshes`
#include "geometry_msgs/msg/detail/polygon__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void custom_interfaces__srv__DetectionService_Response__rosidl_typesupport_introspection_c__DetectionService_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_interfaces__srv__DetectionService_Response__init(message_memory);
}

void custom_interfaces__srv__DetectionService_Response__rosidl_typesupport_introspection_c__DetectionService_Response_fini_function(void * message_memory)
{
  custom_interfaces__srv__DetectionService_Response__fini(message_memory);
}

size_t custom_interfaces__srv__DetectionService_Response__rosidl_typesupport_introspection_c__size_function__DetectionService_Response__meshes(
  const void * untyped_member)
{
  const geometry_msgs__msg__Polygon__Sequence * member =
    (const geometry_msgs__msg__Polygon__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_interfaces__srv__DetectionService_Response__rosidl_typesupport_introspection_c__get_const_function__DetectionService_Response__meshes(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Polygon__Sequence * member =
    (const geometry_msgs__msg__Polygon__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_interfaces__srv__DetectionService_Response__rosidl_typesupport_introspection_c__get_function__DetectionService_Response__meshes(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Polygon__Sequence * member =
    (geometry_msgs__msg__Polygon__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_interfaces__srv__DetectionService_Response__rosidl_typesupport_introspection_c__fetch_function__DetectionService_Response__meshes(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Polygon * item =
    ((const geometry_msgs__msg__Polygon *)
    custom_interfaces__srv__DetectionService_Response__rosidl_typesupport_introspection_c__get_const_function__DetectionService_Response__meshes(untyped_member, index));
  geometry_msgs__msg__Polygon * value =
    (geometry_msgs__msg__Polygon *)(untyped_value);
  *value = *item;
}

void custom_interfaces__srv__DetectionService_Response__rosidl_typesupport_introspection_c__assign_function__DetectionService_Response__meshes(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Polygon * item =
    ((geometry_msgs__msg__Polygon *)
    custom_interfaces__srv__DetectionService_Response__rosidl_typesupport_introspection_c__get_function__DetectionService_Response__meshes(untyped_member, index));
  const geometry_msgs__msg__Polygon * value =
    (const geometry_msgs__msg__Polygon *)(untyped_value);
  *item = *value;
}

bool custom_interfaces__srv__DetectionService_Response__rosidl_typesupport_introspection_c__resize_function__DetectionService_Response__meshes(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Polygon__Sequence * member =
    (geometry_msgs__msg__Polygon__Sequence *)(untyped_member);
  geometry_msgs__msg__Polygon__Sequence__fini(member);
  return geometry_msgs__msg__Polygon__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember custom_interfaces__srv__DetectionService_Response__rosidl_typesupport_introspection_c__DetectionService_Response_message_member_array[1] = {
  {
    "meshes",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces__srv__DetectionService_Response, meshes),  // bytes offset in struct
    NULL,  // default value
    custom_interfaces__srv__DetectionService_Response__rosidl_typesupport_introspection_c__size_function__DetectionService_Response__meshes,  // size() function pointer
    custom_interfaces__srv__DetectionService_Response__rosidl_typesupport_introspection_c__get_const_function__DetectionService_Response__meshes,  // get_const(index) function pointer
    custom_interfaces__srv__DetectionService_Response__rosidl_typesupport_introspection_c__get_function__DetectionService_Response__meshes,  // get(index) function pointer
    custom_interfaces__srv__DetectionService_Response__rosidl_typesupport_introspection_c__fetch_function__DetectionService_Response__meshes,  // fetch(index, &value) function pointer
    custom_interfaces__srv__DetectionService_Response__rosidl_typesupport_introspection_c__assign_function__DetectionService_Response__meshes,  // assign(index, value) function pointer
    custom_interfaces__srv__DetectionService_Response__rosidl_typesupport_introspection_c__resize_function__DetectionService_Response__meshes  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers custom_interfaces__srv__DetectionService_Response__rosidl_typesupport_introspection_c__DetectionService_Response_message_members = {
  "custom_interfaces__srv",  // message namespace
  "DetectionService_Response",  // message name
  1,  // number of fields
  sizeof(custom_interfaces__srv__DetectionService_Response),
  custom_interfaces__srv__DetectionService_Response__rosidl_typesupport_introspection_c__DetectionService_Response_message_member_array,  // message members
  custom_interfaces__srv__DetectionService_Response__rosidl_typesupport_introspection_c__DetectionService_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  custom_interfaces__srv__DetectionService_Response__rosidl_typesupport_introspection_c__DetectionService_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t custom_interfaces__srv__DetectionService_Response__rosidl_typesupport_introspection_c__DetectionService_Response_message_type_support_handle = {
  0,
  &custom_interfaces__srv__DetectionService_Response__rosidl_typesupport_introspection_c__DetectionService_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_interfaces, srv, DetectionService_Response)() {
  custom_interfaces__srv__DetectionService_Response__rosidl_typesupport_introspection_c__DetectionService_Response_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Polygon)();
  if (!custom_interfaces__srv__DetectionService_Response__rosidl_typesupport_introspection_c__DetectionService_Response_message_type_support_handle.typesupport_identifier) {
    custom_interfaces__srv__DetectionService_Response__rosidl_typesupport_introspection_c__DetectionService_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &custom_interfaces__srv__DetectionService_Response__rosidl_typesupport_introspection_c__DetectionService_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "custom_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "custom_interfaces/srv/detail/detection_service__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers custom_interfaces__srv__detail__detection_service__rosidl_typesupport_introspection_c__DetectionService_service_members = {
  "custom_interfaces__srv",  // service namespace
  "DetectionService",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // custom_interfaces__srv__detail__detection_service__rosidl_typesupport_introspection_c__DetectionService_Request_message_type_support_handle,
  NULL  // response message
  // custom_interfaces__srv__detail__detection_service__rosidl_typesupport_introspection_c__DetectionService_Response_message_type_support_handle
};

static rosidl_service_type_support_t custom_interfaces__srv__detail__detection_service__rosidl_typesupport_introspection_c__DetectionService_service_type_support_handle = {
  0,
  &custom_interfaces__srv__detail__detection_service__rosidl_typesupport_introspection_c__DetectionService_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_interfaces, srv, DetectionService_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_interfaces, srv, DetectionService_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_interfaces, srv, DetectionService)() {
  if (!custom_interfaces__srv__detail__detection_service__rosidl_typesupport_introspection_c__DetectionService_service_type_support_handle.typesupport_identifier) {
    custom_interfaces__srv__detail__detection_service__rosidl_typesupport_introspection_c__DetectionService_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)custom_interfaces__srv__detail__detection_service__rosidl_typesupport_introspection_c__DetectionService_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_interfaces, srv, DetectionService_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_interfaces, srv, DetectionService_Response)()->data;
  }

  return &custom_interfaces__srv__detail__detection_service__rosidl_typesupport_introspection_c__DetectionService_service_type_support_handle;
}
