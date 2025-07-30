// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interfaces:msg/VerticalMotorCommands.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__VERTICAL_MOTOR_COMMANDS__STRUCT_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__VERTICAL_MOTOR_COMMANDS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_interfaces__msg__VerticalMotorCommands __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__msg__VerticalMotorCommands __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct VerticalMotorCommands_
{
  using Type = VerticalMotorCommands_<ContainerAllocator>;

  explicit VerticalMotorCommands_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<int16_t, 2>::iterator, int16_t>(this->motor_numbers.begin(), this->motor_numbers.end(), 0);
      std::fill<typename std::array<double, 2>::iterator, double>(this->throttles.begin(), this->throttles.end(), 0.0);
    }
  }

  explicit VerticalMotorCommands_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : motor_numbers(_alloc),
    throttles(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<int16_t, 2>::iterator, int16_t>(this->motor_numbers.begin(), this->motor_numbers.end(), 0);
      std::fill<typename std::array<double, 2>::iterator, double>(this->throttles.begin(), this->throttles.end(), 0.0);
    }
  }

  // field types and members
  using _motor_numbers_type =
    std::array<int16_t, 2>;
  _motor_numbers_type motor_numbers;
  using _throttles_type =
    std::array<double, 2>;
  _throttles_type throttles;

  // setters for named parameter idiom
  Type & set__motor_numbers(
    const std::array<int16_t, 2> & _arg)
  {
    this->motor_numbers = _arg;
    return *this;
  }
  Type & set__throttles(
    const std::array<double, 2> & _arg)
  {
    this->throttles = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::msg::VerticalMotorCommands_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::msg::VerticalMotorCommands_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::msg::VerticalMotorCommands_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::msg::VerticalMotorCommands_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::VerticalMotorCommands_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::VerticalMotorCommands_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::VerticalMotorCommands_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::VerticalMotorCommands_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::msg::VerticalMotorCommands_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::msg::VerticalMotorCommands_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__msg__VerticalMotorCommands
    std::shared_ptr<custom_interfaces::msg::VerticalMotorCommands_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__msg__VerticalMotorCommands
    std::shared_ptr<custom_interfaces::msg::VerticalMotorCommands_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const VerticalMotorCommands_ & other) const
  {
    if (this->motor_numbers != other.motor_numbers) {
      return false;
    }
    if (this->throttles != other.throttles) {
      return false;
    }
    return true;
  }
  bool operator!=(const VerticalMotorCommands_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct VerticalMotorCommands_

// alias to use template instance with default allocator
using VerticalMotorCommands =
  custom_interfaces::msg::VerticalMotorCommands_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__VERTICAL_MOTOR_COMMANDS__STRUCT_HPP_
