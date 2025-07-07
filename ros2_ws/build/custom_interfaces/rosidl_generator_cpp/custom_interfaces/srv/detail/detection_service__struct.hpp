// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interfaces:srv/DetectionService.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__DETECTION_SERVICE__STRUCT_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__DETECTION_SERVICE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_interfaces__srv__DetectionService_Request __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__srv__DetectionService_Request __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DetectionService_Request_
{
  using Type = DetectionService_Request_<ContainerAllocator>;

  explicit DetectionService_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit DetectionService_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    custom_interfaces::srv::DetectionService_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::srv::DetectionService_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::srv::DetectionService_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::srv::DetectionService_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::DetectionService_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::DetectionService_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::DetectionService_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::DetectionService_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::srv::DetectionService_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::srv::DetectionService_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__srv__DetectionService_Request
    std::shared_ptr<custom_interfaces::srv::DetectionService_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__srv__DetectionService_Request
    std::shared_ptr<custom_interfaces::srv::DetectionService_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DetectionService_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const DetectionService_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DetectionService_Request_

// alias to use template instance with default allocator
using DetectionService_Request =
  custom_interfaces::srv::DetectionService_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace custom_interfaces


// Include directives for member types
// Member 'detections'
#include "custom_interfaces/msg/detail/detection_buffer__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_interfaces__srv__DetectionService_Response __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__srv__DetectionService_Response __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DetectionService_Response_
{
  using Type = DetectionService_Response_<ContainerAllocator>;

  explicit DetectionService_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : detections(_init)
  {
    (void)_init;
  }

  explicit DetectionService_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : detections(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _detections_type =
    custom_interfaces::msg::DetectionBuffer_<ContainerAllocator>;
  _detections_type detections;

  // setters for named parameter idiom
  Type & set__detections(
    const custom_interfaces::msg::DetectionBuffer_<ContainerAllocator> & _arg)
  {
    this->detections = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::srv::DetectionService_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::srv::DetectionService_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::srv::DetectionService_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::srv::DetectionService_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::DetectionService_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::DetectionService_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::DetectionService_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::DetectionService_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::srv::DetectionService_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::srv::DetectionService_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__srv__DetectionService_Response
    std::shared_ptr<custom_interfaces::srv::DetectionService_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__srv__DetectionService_Response
    std::shared_ptr<custom_interfaces::srv::DetectionService_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DetectionService_Response_ & other) const
  {
    if (this->detections != other.detections) {
      return false;
    }
    return true;
  }
  bool operator!=(const DetectionService_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DetectionService_Response_

// alias to use template instance with default allocator
using DetectionService_Response =
  custom_interfaces::srv::DetectionService_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace custom_interfaces

namespace custom_interfaces
{

namespace srv
{

struct DetectionService
{
  using Request = custom_interfaces::srv::DetectionService_Request;
  using Response = custom_interfaces::srv::DetectionService_Response;
};

}  // namespace srv

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__DETECTION_SERVICE__STRUCT_HPP_
