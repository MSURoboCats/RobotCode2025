// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/WorldMap.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__WORLD_MAP__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__WORLD_MAP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/world_map__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_WorldMap_meshes
{
public:
  Init_WorldMap_meshes()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::msg::WorldMap meshes(::custom_interfaces::msg::WorldMap::_meshes_type arg)
  {
    msg_.meshes = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::WorldMap msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::WorldMap>()
{
  return custom_interfaces::msg::builder::Init_WorldMap_meshes();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__WORLD_MAP__BUILDER_HPP_
