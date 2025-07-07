// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:srv/GenerateWorldMap.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__GENERATE_WORLD_MAP__BUILDER_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__GENERATE_WORLD_MAP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/srv/detail/generate_world_map__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::GenerateWorldMap_Request>()
{
  return ::custom_interfaces::srv::GenerateWorldMap_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_GenerateWorldMap_Response_success
{
public:
  explicit Init_GenerateWorldMap_Response_success(::custom_interfaces::srv::GenerateWorldMap_Response & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::srv::GenerateWorldMap_Response success(::custom_interfaces::srv::GenerateWorldMap_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::GenerateWorldMap_Response msg_;
};

class Init_GenerateWorldMap_Response_out_map
{
public:
  Init_GenerateWorldMap_Response_out_map()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GenerateWorldMap_Response_success out_map(::custom_interfaces::srv::GenerateWorldMap_Response::_out_map_type arg)
  {
    msg_.out_map = std::move(arg);
    return Init_GenerateWorldMap_Response_success(msg_);
  }

private:
  ::custom_interfaces::srv::GenerateWorldMap_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::GenerateWorldMap_Response>()
{
  return custom_interfaces::srv::builder::Init_GenerateWorldMap_Response_out_map();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__GENERATE_WORLD_MAP__BUILDER_HPP_
