// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interfaces:srv/GenerateWorldMap.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__GENERATE_WORLD_MAP__STRUCT_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__GENERATE_WORLD_MAP__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_interfaces__srv__GenerateWorldMap_Request __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__srv__GenerateWorldMap_Request __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GenerateWorldMap_Request_
{
  using Type = GenerateWorldMap_Request_<ContainerAllocator>;

  explicit GenerateWorldMap_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit GenerateWorldMap_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::srv::GenerateWorldMap_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::srv::GenerateWorldMap_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::srv::GenerateWorldMap_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::srv::GenerateWorldMap_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::GenerateWorldMap_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::GenerateWorldMap_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::GenerateWorldMap_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::GenerateWorldMap_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::srv::GenerateWorldMap_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::srv::GenerateWorldMap_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__srv__GenerateWorldMap_Request
    std::shared_ptr<custom_interfaces::srv::GenerateWorldMap_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__srv__GenerateWorldMap_Request
    std::shared_ptr<custom_interfaces::srv::GenerateWorldMap_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GenerateWorldMap_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const GenerateWorldMap_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GenerateWorldMap_Request_

// alias to use template instance with default allocator
using GenerateWorldMap_Request =
  custom_interfaces::srv::GenerateWorldMap_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace custom_interfaces


// Include directives for member types
// Member 'out_map'
#include "custom_interfaces/msg/detail/world_map__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_interfaces__srv__GenerateWorldMap_Response __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__srv__GenerateWorldMap_Response __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GenerateWorldMap_Response_
{
  using Type = GenerateWorldMap_Response_<ContainerAllocator>;

  explicit GenerateWorldMap_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : out_map(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit GenerateWorldMap_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : out_map(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _out_map_type =
    custom_interfaces::msg::WorldMap_<ContainerAllocator>;
  _out_map_type out_map;
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__out_map(
    const custom_interfaces::msg::WorldMap_<ContainerAllocator> & _arg)
  {
    this->out_map = _arg;
    return *this;
  }
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::srv::GenerateWorldMap_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::srv::GenerateWorldMap_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::srv::GenerateWorldMap_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::srv::GenerateWorldMap_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::GenerateWorldMap_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::GenerateWorldMap_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::GenerateWorldMap_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::GenerateWorldMap_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::srv::GenerateWorldMap_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::srv::GenerateWorldMap_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__srv__GenerateWorldMap_Response
    std::shared_ptr<custom_interfaces::srv::GenerateWorldMap_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__srv__GenerateWorldMap_Response
    std::shared_ptr<custom_interfaces::srv::GenerateWorldMap_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GenerateWorldMap_Response_ & other) const
  {
    if (this->out_map != other.out_map) {
      return false;
    }
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const GenerateWorldMap_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GenerateWorldMap_Response_

// alias to use template instance with default allocator
using GenerateWorldMap_Response =
  custom_interfaces::srv::GenerateWorldMap_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace custom_interfaces

namespace custom_interfaces
{

namespace srv
{

struct GenerateWorldMap
{
  using Request = custom_interfaces::srv::GenerateWorldMap_Request;
  using Response = custom_interfaces::srv::GenerateWorldMap_Response;
};

}  // namespace srv

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__GENERATE_WORLD_MAP__STRUCT_HPP_
