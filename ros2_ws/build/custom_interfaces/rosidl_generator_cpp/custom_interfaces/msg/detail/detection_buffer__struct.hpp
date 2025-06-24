// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interfaces:msg/DetectionBuffer.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__DETECTION_BUFFER__STRUCT_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__DETECTION_BUFFER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'detections'
#include "custom_interfaces/msg/detail/bounding_box__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_interfaces__msg__DetectionBuffer __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__msg__DetectionBuffer __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DetectionBuffer_
{
  using Type = DetectionBuffer_<ContainerAllocator>;

  explicit DetectionBuffer_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit DetectionBuffer_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _detections_type =
    std::vector<custom_interfaces::msg::BoundingBox_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<custom_interfaces::msg::BoundingBox_<ContainerAllocator>>>;
  _detections_type detections;

  // setters for named parameter idiom
  Type & set__detections(
    const std::vector<custom_interfaces::msg::BoundingBox_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<custom_interfaces::msg::BoundingBox_<ContainerAllocator>>> & _arg)
  {
    this->detections = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::msg::DetectionBuffer_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::msg::DetectionBuffer_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::msg::DetectionBuffer_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::msg::DetectionBuffer_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::DetectionBuffer_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::DetectionBuffer_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::DetectionBuffer_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::DetectionBuffer_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::msg::DetectionBuffer_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::msg::DetectionBuffer_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__msg__DetectionBuffer
    std::shared_ptr<custom_interfaces::msg::DetectionBuffer_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__msg__DetectionBuffer
    std::shared_ptr<custom_interfaces::msg::DetectionBuffer_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DetectionBuffer_ & other) const
  {
    if (this->detections != other.detections) {
      return false;
    }
    return true;
  }
  bool operator!=(const DetectionBuffer_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DetectionBuffer_

// alias to use template instance with default allocator
using DetectionBuffer =
  custom_interfaces::msg::DetectionBuffer_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__DETECTION_BUFFER__STRUCT_HPP_
