// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interfaces:msg/WorldMap.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__WORLD_MAP__STRUCT_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__WORLD_MAP__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'meshes'
#include "geometry_msgs/msg/detail/polygon__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_interfaces__msg__WorldMap __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__msg__WorldMap __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct WorldMap_
{
  using Type = WorldMap_<ContainerAllocator>;

  explicit WorldMap_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit WorldMap_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _meshes_type =
    std::vector<geometry_msgs::msg::Polygon_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Polygon_<ContainerAllocator>>>;
  _meshes_type meshes;

  // setters for named parameter idiom
  Type & set__meshes(
    const std::vector<geometry_msgs::msg::Polygon_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Polygon_<ContainerAllocator>>> & _arg)
  {
    this->meshes = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::msg::WorldMap_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::msg::WorldMap_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::msg::WorldMap_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::msg::WorldMap_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::WorldMap_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::WorldMap_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::WorldMap_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::WorldMap_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::msg::WorldMap_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::msg::WorldMap_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__msg__WorldMap
    std::shared_ptr<custom_interfaces::msg::WorldMap_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__msg__WorldMap
    std::shared_ptr<custom_interfaces::msg::WorldMap_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const WorldMap_ & other) const
  {
    if (this->meshes != other.meshes) {
      return false;
    }
    return true;
  }
  bool operator!=(const WorldMap_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct WorldMap_

// alias to use template instance with default allocator
using WorldMap =
  custom_interfaces::msg::WorldMap_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__WORLD_MAP__STRUCT_HPP_
