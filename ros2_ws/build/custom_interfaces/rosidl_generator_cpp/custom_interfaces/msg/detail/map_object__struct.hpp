// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interfaces:msg/MapObject.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__MAP_OBJECT__STRUCT_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__MAP_OBJECT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'mesh'
#include "geometry_msgs/msg/detail/polygon__struct.hpp"
// Member 'aabb'
#include "custom_interfaces/msg/detail/aabb__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_interfaces__msg__MapObject __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__msg__MapObject __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MapObject_
{
  using Type = MapObject_<ContainerAllocator>;

  explicit MapObject_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : mesh(_init),
    aabb(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
    }
  }

  explicit MapObject_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : mesh(_alloc, _init),
    aabb(_alloc, _init),
    name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
    }
  }

  // field types and members
  using _mesh_type =
    geometry_msgs::msg::Polygon_<ContainerAllocator>;
  _mesh_type mesh;
  using _aabb_type =
    custom_interfaces::msg::AABB_<ContainerAllocator>;
  _aabb_type aabb;
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;

  // setters for named parameter idiom
  Type & set__mesh(
    const geometry_msgs::msg::Polygon_<ContainerAllocator> & _arg)
  {
    this->mesh = _arg;
    return *this;
  }
  Type & set__aabb(
    const custom_interfaces::msg::AABB_<ContainerAllocator> & _arg)
  {
    this->aabb = _arg;
    return *this;
  }
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::msg::MapObject_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::msg::MapObject_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::msg::MapObject_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::msg::MapObject_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::MapObject_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::MapObject_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::MapObject_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::MapObject_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::msg::MapObject_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::msg::MapObject_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__msg__MapObject
    std::shared_ptr<custom_interfaces::msg::MapObject_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__msg__MapObject
    std::shared_ptr<custom_interfaces::msg::MapObject_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MapObject_ & other) const
  {
    if (this->mesh != other.mesh) {
      return false;
    }
    if (this->aabb != other.aabb) {
      return false;
    }
    if (this->name != other.name) {
      return false;
    }
    return true;
  }
  bool operator!=(const MapObject_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MapObject_

// alias to use template instance with default allocator
using MapObject =
  custom_interfaces::msg::MapObject_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__MAP_OBJECT__STRUCT_HPP_
