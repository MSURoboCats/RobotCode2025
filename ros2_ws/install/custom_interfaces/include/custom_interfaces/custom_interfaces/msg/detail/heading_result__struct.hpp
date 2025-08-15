// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interfaces:msg/HeadingResult.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__HEADING_RESULT__STRUCT_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__HEADING_RESULT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_interfaces__msg__HeadingResult __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__msg__HeadingResult __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct HeadingResult_
{
  using Type = HeadingResult_<ContainerAllocator>;

  explicit HeadingResult_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->text = "";
      this->average_error = 0.0;
    }
  }

  explicit HeadingResult_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : text(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->text = "";
      this->average_error = 0.0;
    }
  }

  // field types and members
  using _text_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _text_type text;
  using _average_error_type =
    double;
  _average_error_type average_error;

  // setters for named parameter idiom
  Type & set__text(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->text = _arg;
    return *this;
  }
  Type & set__average_error(
    const double & _arg)
  {
    this->average_error = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::msg::HeadingResult_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::msg::HeadingResult_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::msg::HeadingResult_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::msg::HeadingResult_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::HeadingResult_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::HeadingResult_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::HeadingResult_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::HeadingResult_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::msg::HeadingResult_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::msg::HeadingResult_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__msg__HeadingResult
    std::shared_ptr<custom_interfaces::msg::HeadingResult_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__msg__HeadingResult
    std::shared_ptr<custom_interfaces::msg::HeadingResult_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HeadingResult_ & other) const
  {
    if (this->text != other.text) {
      return false;
    }
    if (this->average_error != other.average_error) {
      return false;
    }
    return true;
  }
  bool operator!=(const HeadingResult_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HeadingResult_

// alias to use template instance with default allocator
using HeadingResult =
  custom_interfaces::msg::HeadingResult_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__HEADING_RESULT__STRUCT_HPP_
