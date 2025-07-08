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

class Init_WorldMap_objects
{
public:
  explicit Init_WorldMap_objects(::custom_interfaces::msg::WorldMap & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::msg::WorldMap objects(::custom_interfaces::msg::WorldMap::_objects_type arg)
  {
    msg_.objects = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::WorldMap msg_;
};

class Init_WorldMap_header
{
public:
  Init_WorldMap_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_WorldMap_objects header(::custom_interfaces::msg::WorldMap::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_WorldMap_objects(msg_);
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
  return custom_interfaces::msg::builder::Init_WorldMap_header();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__WORLD_MAP__BUILDER_HPP_
