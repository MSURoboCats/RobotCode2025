// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:action/DetectionAction.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__ACTION__DETAIL__DETECTION_ACTION__BUILDER_HPP_
#define CUSTOM_INTERFACES__ACTION__DETAIL__DETECTION_ACTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/action/detail/detection_action__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace action
{

namespace builder
{

class Init_DetectionAction_Goal_detections
{
public:
  explicit Init_DetectionAction_Goal_detections(::custom_interfaces::action::DetectionAction_Goal & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::action::DetectionAction_Goal detections(::custom_interfaces::action::DetectionAction_Goal::_detections_type arg)
  {
    msg_.detections = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::action::DetectionAction_Goal msg_;
};

class Init_DetectionAction_Goal_camera_info
{
public:
  explicit Init_DetectionAction_Goal_camera_info(::custom_interfaces::action::DetectionAction_Goal & msg)
  : msg_(msg)
  {}
  Init_DetectionAction_Goal_detections camera_info(::custom_interfaces::action::DetectionAction_Goal::_camera_info_type arg)
  {
    msg_.camera_info = std::move(arg);
    return Init_DetectionAction_Goal_detections(msg_);
  }

private:
  ::custom_interfaces::action::DetectionAction_Goal msg_;
};

class Init_DetectionAction_Goal_depth_image
{
public:
  Init_DetectionAction_Goal_depth_image()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DetectionAction_Goal_camera_info depth_image(::custom_interfaces::action::DetectionAction_Goal::_depth_image_type arg)
  {
    msg_.depth_image = std::move(arg);
    return Init_DetectionAction_Goal_camera_info(msg_);
  }

private:
  ::custom_interfaces::action::DetectionAction_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::action::DetectionAction_Goal>()
{
  return custom_interfaces::action::builder::Init_DetectionAction_Goal_depth_image();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace action
{

namespace builder
{

class Init_DetectionAction_Result_points
{
public:
  Init_DetectionAction_Result_points()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::action::DetectionAction_Result points(::custom_interfaces::action::DetectionAction_Result::_points_type arg)
  {
    msg_.points = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::action::DetectionAction_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::action::DetectionAction_Result>()
{
  return custom_interfaces::action::builder::Init_DetectionAction_Result_points();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace action
{

namespace builder
{

class Init_DetectionAction_Feedback_mask
{
public:
  Init_DetectionAction_Feedback_mask()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::action::DetectionAction_Feedback mask(::custom_interfaces::action::DetectionAction_Feedback::_mask_type arg)
  {
    msg_.mask = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::action::DetectionAction_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::action::DetectionAction_Feedback>()
{
  return custom_interfaces::action::builder::Init_DetectionAction_Feedback_mask();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace action
{

namespace builder
{

class Init_DetectionAction_SendGoal_Request_goal
{
public:
  explicit Init_DetectionAction_SendGoal_Request_goal(::custom_interfaces::action::DetectionAction_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::action::DetectionAction_SendGoal_Request goal(::custom_interfaces::action::DetectionAction_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::action::DetectionAction_SendGoal_Request msg_;
};

class Init_DetectionAction_SendGoal_Request_goal_id
{
public:
  Init_DetectionAction_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DetectionAction_SendGoal_Request_goal goal_id(::custom_interfaces::action::DetectionAction_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_DetectionAction_SendGoal_Request_goal(msg_);
  }

private:
  ::custom_interfaces::action::DetectionAction_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::action::DetectionAction_SendGoal_Request>()
{
  return custom_interfaces::action::builder::Init_DetectionAction_SendGoal_Request_goal_id();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace action
{

namespace builder
{

class Init_DetectionAction_SendGoal_Response_stamp
{
public:
  explicit Init_DetectionAction_SendGoal_Response_stamp(::custom_interfaces::action::DetectionAction_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::action::DetectionAction_SendGoal_Response stamp(::custom_interfaces::action::DetectionAction_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::action::DetectionAction_SendGoal_Response msg_;
};

class Init_DetectionAction_SendGoal_Response_accepted
{
public:
  Init_DetectionAction_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DetectionAction_SendGoal_Response_stamp accepted(::custom_interfaces::action::DetectionAction_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_DetectionAction_SendGoal_Response_stamp(msg_);
  }

private:
  ::custom_interfaces::action::DetectionAction_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::action::DetectionAction_SendGoal_Response>()
{
  return custom_interfaces::action::builder::Init_DetectionAction_SendGoal_Response_accepted();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace action
{

namespace builder
{

class Init_DetectionAction_GetResult_Request_goal_id
{
public:
  Init_DetectionAction_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::action::DetectionAction_GetResult_Request goal_id(::custom_interfaces::action::DetectionAction_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::action::DetectionAction_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::action::DetectionAction_GetResult_Request>()
{
  return custom_interfaces::action::builder::Init_DetectionAction_GetResult_Request_goal_id();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace action
{

namespace builder
{

class Init_DetectionAction_GetResult_Response_result
{
public:
  explicit Init_DetectionAction_GetResult_Response_result(::custom_interfaces::action::DetectionAction_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::action::DetectionAction_GetResult_Response result(::custom_interfaces::action::DetectionAction_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::action::DetectionAction_GetResult_Response msg_;
};

class Init_DetectionAction_GetResult_Response_status
{
public:
  Init_DetectionAction_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DetectionAction_GetResult_Response_result status(::custom_interfaces::action::DetectionAction_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_DetectionAction_GetResult_Response_result(msg_);
  }

private:
  ::custom_interfaces::action::DetectionAction_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::action::DetectionAction_GetResult_Response>()
{
  return custom_interfaces::action::builder::Init_DetectionAction_GetResult_Response_status();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace action
{

namespace builder
{

class Init_DetectionAction_FeedbackMessage_feedback
{
public:
  explicit Init_DetectionAction_FeedbackMessage_feedback(::custom_interfaces::action::DetectionAction_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::action::DetectionAction_FeedbackMessage feedback(::custom_interfaces::action::DetectionAction_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::action::DetectionAction_FeedbackMessage msg_;
};

class Init_DetectionAction_FeedbackMessage_goal_id
{
public:
  Init_DetectionAction_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DetectionAction_FeedbackMessage_feedback goal_id(::custom_interfaces::action::DetectionAction_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_DetectionAction_FeedbackMessage_feedback(msg_);
  }

private:
  ::custom_interfaces::action::DetectionAction_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::action::DetectionAction_FeedbackMessage>()
{
  return custom_interfaces::action::builder::Init_DetectionAction_FeedbackMessage_goal_id();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__ACTION__DETAIL__DETECTION_ACTION__BUILDER_HPP_
