// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/MapObject.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__MAP_OBJECT__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__MAP_OBJECT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/map_object__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_MapObject_aabb
{
public:
  explicit Init_MapObject_aabb(::custom_interfaces::msg::MapObject & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::msg::MapObject aabb(::custom_interfaces::msg::MapObject::_aabb_type arg)
  {
    msg_.aabb = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::MapObject msg_;
};

class Init_MapObject_mesh
{
public:
  Init_MapObject_mesh()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MapObject_aabb mesh(::custom_interfaces::msg::MapObject::_mesh_type arg)
  {
    msg_.mesh = std::move(arg);
    return Init_MapObject_aabb(msg_);
  }

private:
  ::custom_interfaces::msg::MapObject msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::MapObject>()
{
  return custom_interfaces::msg::builder::Init_MapObject_mesh();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__MAP_OBJECT__BUILDER_HPP_
