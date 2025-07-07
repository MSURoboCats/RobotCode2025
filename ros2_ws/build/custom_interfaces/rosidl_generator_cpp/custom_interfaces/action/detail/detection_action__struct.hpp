// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interfaces:action/DetectionAction.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__ACTION__DETAIL__DETECTION_ACTION__STRUCT_HPP_
#define CUSTOM_INTERFACES__ACTION__DETAIL__DETECTION_ACTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'depth_image'
#include "sensor_msgs/msg/detail/image__struct.hpp"
// Member 'camera_info'
#include "sensor_msgs/msg/detail/camera_info__struct.hpp"
// Member 'detections'
#include "custom_interfaces/msg/detail/detection_buffer__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_interfaces__action__DetectionAction_Goal __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__action__DetectionAction_Goal __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct DetectionAction_Goal_
{
  using Type = DetectionAction_Goal_<ContainerAllocator>;

  explicit DetectionAction_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : depth_image(_init),
    camera_info(_init),
    detections(_init)
  {
    (void)_init;
  }

  explicit DetectionAction_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : depth_image(_alloc, _init),
    camera_info(_alloc, _init),
    detections(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _depth_image_type =
    sensor_msgs::msg::Image_<ContainerAllocator>;
  _depth_image_type depth_image;
  using _camera_info_type =
    sensor_msgs::msg::CameraInfo_<ContainerAllocator>;
  _camera_info_type camera_info;
  using _detections_type =
    custom_interfaces::msg::DetectionBuffer_<ContainerAllocator>;
  _detections_type detections;

  // setters for named parameter idiom
  Type & set__depth_image(
    const sensor_msgs::msg::Image_<ContainerAllocator> & _arg)
  {
    this->depth_image = _arg;
    return *this;
  }
  Type & set__camera_info(
    const sensor_msgs::msg::CameraInfo_<ContainerAllocator> & _arg)
  {
    this->camera_info = _arg;
    return *this;
  }
  Type & set__detections(
    const custom_interfaces::msg::DetectionBuffer_<ContainerAllocator> & _arg)
  {
    this->detections = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::action::DetectionAction_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::action::DetectionAction_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::action::DetectionAction_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::action::DetectionAction_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::action::DetectionAction_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::action::DetectionAction_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::action::DetectionAction_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::action::DetectionAction_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::action::DetectionAction_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::action::DetectionAction_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__action__DetectionAction_Goal
    std::shared_ptr<custom_interfaces::action::DetectionAction_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__action__DetectionAction_Goal
    std::shared_ptr<custom_interfaces::action::DetectionAction_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DetectionAction_Goal_ & other) const
  {
    if (this->depth_image != other.depth_image) {
      return false;
    }
    if (this->camera_info != other.camera_info) {
      return false;
    }
    if (this->detections != other.detections) {
      return false;
    }
    return true;
  }
  bool operator!=(const DetectionAction_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DetectionAction_Goal_

// alias to use template instance with default allocator
using DetectionAction_Goal =
  custom_interfaces::action::DetectionAction_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace custom_interfaces


// Include directives for member types
// Member 'points'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_interfaces__action__DetectionAction_Result __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__action__DetectionAction_Result __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct DetectionAction_Result_
{
  using Type = DetectionAction_Result_<ContainerAllocator>;

  explicit DetectionAction_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit DetectionAction_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _points_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _points_type points;

  // setters for named parameter idiom
  Type & set__points(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->points = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::action::DetectionAction_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::action::DetectionAction_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::action::DetectionAction_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::action::DetectionAction_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::action::DetectionAction_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::action::DetectionAction_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::action::DetectionAction_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::action::DetectionAction_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::action::DetectionAction_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::action::DetectionAction_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__action__DetectionAction_Result
    std::shared_ptr<custom_interfaces::action::DetectionAction_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__action__DetectionAction_Result
    std::shared_ptr<custom_interfaces::action::DetectionAction_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DetectionAction_Result_ & other) const
  {
    if (this->points != other.points) {
      return false;
    }
    return true;
  }
  bool operator!=(const DetectionAction_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DetectionAction_Result_

// alias to use template instance with default allocator
using DetectionAction_Result =
  custom_interfaces::action::DetectionAction_Result_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace custom_interfaces


// Include directives for member types
// Member 'mask'
// already included above
// #include "sensor_msgs/msg/detail/image__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_interfaces__action__DetectionAction_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__action__DetectionAction_Feedback __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct DetectionAction_Feedback_
{
  using Type = DetectionAction_Feedback_<ContainerAllocator>;

  explicit DetectionAction_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : mask(_init)
  {
    (void)_init;
  }

  explicit DetectionAction_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : mask(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _mask_type =
    sensor_msgs::msg::Image_<ContainerAllocator>;
  _mask_type mask;

  // setters for named parameter idiom
  Type & set__mask(
    const sensor_msgs::msg::Image_<ContainerAllocator> & _arg)
  {
    this->mask = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::action::DetectionAction_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::action::DetectionAction_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::action::DetectionAction_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::action::DetectionAction_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::action::DetectionAction_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::action::DetectionAction_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::action::DetectionAction_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::action::DetectionAction_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::action::DetectionAction_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::action::DetectionAction_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__action__DetectionAction_Feedback
    std::shared_ptr<custom_interfaces::action::DetectionAction_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__action__DetectionAction_Feedback
    std::shared_ptr<custom_interfaces::action::DetectionAction_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DetectionAction_Feedback_ & other) const
  {
    if (this->mask != other.mask) {
      return false;
    }
    return true;
  }
  bool operator!=(const DetectionAction_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DetectionAction_Feedback_

// alias to use template instance with default allocator
using DetectionAction_Feedback =
  custom_interfaces::action::DetectionAction_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace custom_interfaces


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "custom_interfaces/action/detail/detection_action__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_interfaces__action__DetectionAction_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__action__DetectionAction_SendGoal_Request __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct DetectionAction_SendGoal_Request_
{
  using Type = DetectionAction_SendGoal_Request_<ContainerAllocator>;

  explicit DetectionAction_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit DetectionAction_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    goal(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _goal_type =
    custom_interfaces::action::DetectionAction_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const custom_interfaces::action::DetectionAction_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::action::DetectionAction_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::action::DetectionAction_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::action::DetectionAction_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::action::DetectionAction_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::action::DetectionAction_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::action::DetectionAction_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::action::DetectionAction_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::action::DetectionAction_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::action::DetectionAction_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::action::DetectionAction_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__action__DetectionAction_SendGoal_Request
    std::shared_ptr<custom_interfaces::action::DetectionAction_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__action__DetectionAction_SendGoal_Request
    std::shared_ptr<custom_interfaces::action::DetectionAction_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DetectionAction_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const DetectionAction_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DetectionAction_SendGoal_Request_

// alias to use template instance with default allocator
using DetectionAction_SendGoal_Request =
  custom_interfaces::action::DetectionAction_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace custom_interfaces


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_interfaces__action__DetectionAction_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__action__DetectionAction_SendGoal_Response __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct DetectionAction_SendGoal_Response_
{
  using Type = DetectionAction_SendGoal_Response_<ContainerAllocator>;

  explicit DetectionAction_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit DetectionAction_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::action::DetectionAction_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::action::DetectionAction_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::action::DetectionAction_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::action::DetectionAction_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::action::DetectionAction_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::action::DetectionAction_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::action::DetectionAction_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::action::DetectionAction_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::action::DetectionAction_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::action::DetectionAction_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__action__DetectionAction_SendGoal_Response
    std::shared_ptr<custom_interfaces::action::DetectionAction_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__action__DetectionAction_SendGoal_Response
    std::shared_ptr<custom_interfaces::action::DetectionAction_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DetectionAction_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const DetectionAction_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DetectionAction_SendGoal_Response_

// alias to use template instance with default allocator
using DetectionAction_SendGoal_Response =
  custom_interfaces::action::DetectionAction_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace custom_interfaces

namespace custom_interfaces
{

namespace action
{

struct DetectionAction_SendGoal
{
  using Request = custom_interfaces::action::DetectionAction_SendGoal_Request;
  using Response = custom_interfaces::action::DetectionAction_SendGoal_Response;
};

}  // namespace action

}  // namespace custom_interfaces


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_interfaces__action__DetectionAction_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__action__DetectionAction_GetResult_Request __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct DetectionAction_GetResult_Request_
{
  using Type = DetectionAction_GetResult_Request_<ContainerAllocator>;

  explicit DetectionAction_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit DetectionAction_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::action::DetectionAction_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::action::DetectionAction_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::action::DetectionAction_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::action::DetectionAction_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::action::DetectionAction_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::action::DetectionAction_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::action::DetectionAction_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::action::DetectionAction_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::action::DetectionAction_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::action::DetectionAction_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__action__DetectionAction_GetResult_Request
    std::shared_ptr<custom_interfaces::action::DetectionAction_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__action__DetectionAction_GetResult_Request
    std::shared_ptr<custom_interfaces::action::DetectionAction_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DetectionAction_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const DetectionAction_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DetectionAction_GetResult_Request_

// alias to use template instance with default allocator
using DetectionAction_GetResult_Request =
  custom_interfaces::action::DetectionAction_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace custom_interfaces


// Include directives for member types
// Member 'result'
// already included above
// #include "custom_interfaces/action/detail/detection_action__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_interfaces__action__DetectionAction_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__action__DetectionAction_GetResult_Response __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct DetectionAction_GetResult_Response_
{
  using Type = DetectionAction_GetResult_Response_<ContainerAllocator>;

  explicit DetectionAction_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit DetectionAction_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    int8_t;
  _status_type status;
  using _result_type =
    custom_interfaces::action::DetectionAction_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const custom_interfaces::action::DetectionAction_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::action::DetectionAction_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::action::DetectionAction_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::action::DetectionAction_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::action::DetectionAction_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::action::DetectionAction_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::action::DetectionAction_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::action::DetectionAction_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::action::DetectionAction_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::action::DetectionAction_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::action::DetectionAction_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__action__DetectionAction_GetResult_Response
    std::shared_ptr<custom_interfaces::action::DetectionAction_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__action__DetectionAction_GetResult_Response
    std::shared_ptr<custom_interfaces::action::DetectionAction_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DetectionAction_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const DetectionAction_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DetectionAction_GetResult_Response_

// alias to use template instance with default allocator
using DetectionAction_GetResult_Response =
  custom_interfaces::action::DetectionAction_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace custom_interfaces

namespace custom_interfaces
{

namespace action
{

struct DetectionAction_GetResult
{
  using Request = custom_interfaces::action::DetectionAction_GetResult_Request;
  using Response = custom_interfaces::action::DetectionAction_GetResult_Response;
};

}  // namespace action

}  // namespace custom_interfaces


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "custom_interfaces/action/detail/detection_action__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_interfaces__action__DetectionAction_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__action__DetectionAction_FeedbackMessage __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct DetectionAction_FeedbackMessage_
{
  using Type = DetectionAction_FeedbackMessage_<ContainerAllocator>;

  explicit DetectionAction_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit DetectionAction_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    feedback(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _feedback_type =
    custom_interfaces::action::DetectionAction_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const custom_interfaces::action::DetectionAction_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::action::DetectionAction_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::action::DetectionAction_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::action::DetectionAction_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::action::DetectionAction_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::action::DetectionAction_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::action::DetectionAction_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::action::DetectionAction_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::action::DetectionAction_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::action::DetectionAction_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::action::DetectionAction_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__action__DetectionAction_FeedbackMessage
    std::shared_ptr<custom_interfaces::action::DetectionAction_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__action__DetectionAction_FeedbackMessage
    std::shared_ptr<custom_interfaces::action::DetectionAction_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DetectionAction_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const DetectionAction_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DetectionAction_FeedbackMessage_

// alias to use template instance with default allocator
using DetectionAction_FeedbackMessage =
  custom_interfaces::action::DetectionAction_FeedbackMessage_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace custom_interfaces

#include "action_msgs/srv/cancel_goal.hpp"
#include "action_msgs/msg/goal_info.hpp"
#include "action_msgs/msg/goal_status_array.hpp"

namespace custom_interfaces
{

namespace action
{

struct DetectionAction
{
  /// The goal message defined in the action definition.
  using Goal = custom_interfaces::action::DetectionAction_Goal;
  /// The result message defined in the action definition.
  using Result = custom_interfaces::action::DetectionAction_Result;
  /// The feedback message defined in the action definition.
  using Feedback = custom_interfaces::action::DetectionAction_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = custom_interfaces::action::DetectionAction_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = custom_interfaces::action::DetectionAction_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = custom_interfaces::action::DetectionAction_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct DetectionAction DetectionAction;

}  // namespace action

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__ACTION__DETAIL__DETECTION_ACTION__STRUCT_HPP_
