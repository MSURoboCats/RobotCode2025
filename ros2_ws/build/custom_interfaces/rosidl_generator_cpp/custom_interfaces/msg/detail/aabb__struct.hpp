// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interfaces:msg/AABB.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__AABB__STRUCT_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__AABB__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'center'
#include "geometry_msgs/msg/detail/point__struct.hpp"
// Member 'extents'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_interfaces__msg__AABB __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__msg__AABB __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AABB_
{
  using Type = AABB_<ContainerAllocator>;

  explicit AABB_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : center(_init),
    extents(_init)
  {
    (void)_init;
  }

  explicit AABB_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : center(_alloc, _init),
    extents(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _center_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _center_type center;
  using _extents_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _extents_type extents;

  // setters for named parameter idiom
  Type & set__center(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->center = _arg;
    return *this;
  }
  Type & set__extents(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->extents = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::msg::AABB_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::msg::AABB_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::msg::AABB_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::msg::AABB_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::AABB_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::AABB_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::AABB_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::AABB_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::msg::AABB_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::msg::AABB_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__msg__AABB
    std::shared_ptr<custom_interfaces::msg::AABB_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__msg__AABB
    std::shared_ptr<custom_interfaces::msg::AABB_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AABB_ & other) const
  {
    if (this->center != other.center) {
      return false;
    }
    if (this->extents != other.extents) {
      return false;
    }
    return true;
  }
  bool operator!=(const AABB_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AABB_

// alias to use template instance with default allocator
using AABB =
  custom_interfaces::msg::AABB_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__AABB__STRUCT_HPP_
