// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interfaces:msg/DepthReport.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__DEPTH_REPORT__STRUCT_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__DEPTH_REPORT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_interfaces__msg__DepthReport __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__msg__DepthReport __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DepthReport_
{
  using Type = DepthReport_<ContainerAllocator>;

  explicit DepthReport_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->depth = 0.0;
      this->pressure = 0.0;
      this->temperature = 0.0;
    }
  }

  explicit DepthReport_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->depth = 0.0;
      this->pressure = 0.0;
      this->temperature = 0.0;
    }
  }

  // field types and members
  using _depth_type =
    double;
  _depth_type depth;
  using _pressure_type =
    double;
  _pressure_type pressure;
  using _temperature_type =
    double;
  _temperature_type temperature;

  // setters for named parameter idiom
  Type & set__depth(
    const double & _arg)
  {
    this->depth = _arg;
    return *this;
  }
  Type & set__pressure(
    const double & _arg)
  {
    this->pressure = _arg;
    return *this;
  }
  Type & set__temperature(
    const double & _arg)
  {
    this->temperature = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::msg::DepthReport_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::msg::DepthReport_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::msg::DepthReport_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::msg::DepthReport_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::DepthReport_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::DepthReport_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::DepthReport_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::DepthReport_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::msg::DepthReport_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::msg::DepthReport_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__msg__DepthReport
    std::shared_ptr<custom_interfaces::msg::DepthReport_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__msg__DepthReport
    std::shared_ptr<custom_interfaces::msg::DepthReport_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DepthReport_ & other) const
  {
    if (this->depth != other.depth) {
      return false;
    }
    if (this->pressure != other.pressure) {
      return false;
    }
    if (this->temperature != other.temperature) {
      return false;
    }
    return true;
  }
  bool operator!=(const DepthReport_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DepthReport_

// alias to use template instance with default allocator
using DepthReport =
  custom_interfaces::msg::DepthReport_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__DEPTH_REPORT__STRUCT_HPP_
