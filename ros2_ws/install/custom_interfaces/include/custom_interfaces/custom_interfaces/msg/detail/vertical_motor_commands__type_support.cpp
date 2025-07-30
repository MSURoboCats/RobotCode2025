// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from custom_interfaces:msg/VerticalMotorCommands.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "custom_interfaces/msg/detail/vertical_motor_commands__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace custom_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void VerticalMotorCommands_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) custom_interfaces::msg::VerticalMotorCommands(_init);
}

void VerticalMotorCommands_fini_function(void * message_memory)
{
  auto typed_message = static_cast<custom_interfaces::msg::VerticalMotorCommands *>(message_memory);
  typed_message->~VerticalMotorCommands();
}

size_t size_function__VerticalMotorCommands__motor_numbers(const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * get_const_function__VerticalMotorCommands__motor_numbers(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<int16_t, 2> *>(untyped_member);
  return &member[index];
}

void * get_function__VerticalMotorCommands__motor_numbers(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<int16_t, 2> *>(untyped_member);
  return &member[index];
}

void fetch_function__VerticalMotorCommands__motor_numbers(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int16_t *>(
    get_const_function__VerticalMotorCommands__motor_numbers(untyped_member, index));
  auto & value = *reinterpret_cast<int16_t *>(untyped_value);
  value = item;
}

void assign_function__VerticalMotorCommands__motor_numbers(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int16_t *>(
    get_function__VerticalMotorCommands__motor_numbers(untyped_member, index));
  const auto & value = *reinterpret_cast<const int16_t *>(untyped_value);
  item = value;
}

size_t size_function__VerticalMotorCommands__throttles(const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * get_const_function__VerticalMotorCommands__throttles(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 2> *>(untyped_member);
  return &member[index];
}

void * get_function__VerticalMotorCommands__throttles(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 2> *>(untyped_member);
  return &member[index];
}

void fetch_function__VerticalMotorCommands__throttles(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__VerticalMotorCommands__throttles(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__VerticalMotorCommands__throttles(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__VerticalMotorCommands__throttles(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember VerticalMotorCommands_message_member_array[2] = {
  {
    "motor_numbers",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces::msg::VerticalMotorCommands, motor_numbers),  // bytes offset in struct
    nullptr,  // default value
    size_function__VerticalMotorCommands__motor_numbers,  // size() function pointer
    get_const_function__VerticalMotorCommands__motor_numbers,  // get_const(index) function pointer
    get_function__VerticalMotorCommands__motor_numbers,  // get(index) function pointer
    fetch_function__VerticalMotorCommands__motor_numbers,  // fetch(index, &value) function pointer
    assign_function__VerticalMotorCommands__motor_numbers,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "throttles",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces::msg::VerticalMotorCommands, throttles),  // bytes offset in struct
    nullptr,  // default value
    size_function__VerticalMotorCommands__throttles,  // size() function pointer
    get_const_function__VerticalMotorCommands__throttles,  // get_const(index) function pointer
    get_function__VerticalMotorCommands__throttles,  // get(index) function pointer
    fetch_function__VerticalMotorCommands__throttles,  // fetch(index, &value) function pointer
    assign_function__VerticalMotorCommands__throttles,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers VerticalMotorCommands_message_members = {
  "custom_interfaces::msg",  // message namespace
  "VerticalMotorCommands",  // message name
  2,  // number of fields
  sizeof(custom_interfaces::msg::VerticalMotorCommands),
  VerticalMotorCommands_message_member_array,  // message members
  VerticalMotorCommands_init_function,  // function to initialize message memory (memory has to be allocated)
  VerticalMotorCommands_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t VerticalMotorCommands_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &VerticalMotorCommands_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace custom_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<custom_interfaces::msg::VerticalMotorCommands>()
{
  return &::custom_interfaces::msg::rosidl_typesupport_introspection_cpp::VerticalMotorCommands_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, custom_interfaces, msg, VerticalMotorCommands)() {
  return &::custom_interfaces::msg::rosidl_typesupport_introspection_cpp::VerticalMotorCommands_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
