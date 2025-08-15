// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/ImuData.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__IMU_DATA__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__IMU_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/imu_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_ImuData_linear_acceleration
{
public:
  explicit Init_ImuData_linear_acceleration(::custom_interfaces::msg::ImuData & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::msg::ImuData linear_acceleration(::custom_interfaces::msg::ImuData::_linear_acceleration_type arg)
  {
    msg_.linear_acceleration = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::ImuData msg_;
};

class Init_ImuData_angular_velocity
{
public:
  explicit Init_ImuData_angular_velocity(::custom_interfaces::msg::ImuData & msg)
  : msg_(msg)
  {}
  Init_ImuData_linear_acceleration angular_velocity(::custom_interfaces::msg::ImuData::_angular_velocity_type arg)
  {
    msg_.angular_velocity = std::move(arg);
    return Init_ImuData_linear_acceleration(msg_);
  }

private:
  ::custom_interfaces::msg::ImuData msg_;
};

class Init_ImuData_euler_angles
{
public:
  explicit Init_ImuData_euler_angles(::custom_interfaces::msg::ImuData & msg)
  : msg_(msg)
  {}
  Init_ImuData_angular_velocity euler_angles(::custom_interfaces::msg::ImuData::_euler_angles_type arg)
  {
    msg_.euler_angles = std::move(arg);
    return Init_ImuData_angular_velocity(msg_);
  }

private:
  ::custom_interfaces::msg::ImuData msg_;
};

class Init_ImuData_orientation
{
public:
  explicit Init_ImuData_orientation(::custom_interfaces::msg::ImuData & msg)
  : msg_(msg)
  {}
  Init_ImuData_euler_angles orientation(::custom_interfaces::msg::ImuData::_orientation_type arg)
  {
    msg_.orientation = std::move(arg);
    return Init_ImuData_euler_angles(msg_);
  }

private:
  ::custom_interfaces::msg::ImuData msg_;
};

class Init_ImuData_global_time_seconds
{
public:
  Init_ImuData_global_time_seconds()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ImuData_orientation global_time_seconds(::custom_interfaces::msg::ImuData::_global_time_seconds_type arg)
  {
    msg_.global_time_seconds = std::move(arg);
    return Init_ImuData_orientation(msg_);
  }

private:
  ::custom_interfaces::msg::ImuData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::ImuData>()
{
  return custom_interfaces::msg::builder::Init_ImuData_global_time_seconds();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__IMU_DATA__BUILDER_HPP_
