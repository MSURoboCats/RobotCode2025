// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:action/NavigationGoal.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__ACTION__DETAIL__NAVIGATION_GOAL__BUILDER_HPP_
#define CUSTOM_INTERFACES__ACTION__DETAIL__NAVIGATION_GOAL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/action/detail/navigation_goal__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace action
{

namespace builder
{

class Init_NavigationGoal_Goal_goal
{
public:
  Init_NavigationGoal_Goal_goal()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::action::NavigationGoal_Goal goal(::custom_interfaces::action::NavigationGoal_Goal::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::action::NavigationGoal_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::action::NavigationGoal_Goal>()
{
  return custom_interfaces::action::builder::Init_NavigationGoal_Goal_goal();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace action
{

namespace builder
{

class Init_NavigationGoal_Result_success
{
public:
  Init_NavigationGoal_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::action::NavigationGoal_Result success(::custom_interfaces::action::NavigationGoal_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::action::NavigationGoal_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::action::NavigationGoal_Result>()
{
  return custom_interfaces::action::builder::Init_NavigationGoal_Result_success();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace action
{

namespace builder
{

class Init_NavigationGoal_Feedback_status
{
public:
  Init_NavigationGoal_Feedback_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::action::NavigationGoal_Feedback status(::custom_interfaces::action::NavigationGoal_Feedback::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::action::NavigationGoal_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::action::NavigationGoal_Feedback>()
{
  return custom_interfaces::action::builder::Init_NavigationGoal_Feedback_status();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace action
{

namespace builder
{

class Init_NavigationGoal_SendGoal_Request_goal
{
public:
  explicit Init_NavigationGoal_SendGoal_Request_goal(::custom_interfaces::action::NavigationGoal_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::action::NavigationGoal_SendGoal_Request goal(::custom_interfaces::action::NavigationGoal_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::action::NavigationGoal_SendGoal_Request msg_;
};

class Init_NavigationGoal_SendGoal_Request_goal_id
{
public:
  Init_NavigationGoal_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigationGoal_SendGoal_Request_goal goal_id(::custom_interfaces::action::NavigationGoal_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_NavigationGoal_SendGoal_Request_goal(msg_);
  }

private:
  ::custom_interfaces::action::NavigationGoal_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::action::NavigationGoal_SendGoal_Request>()
{
  return custom_interfaces::action::builder::Init_NavigationGoal_SendGoal_Request_goal_id();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace action
{

namespace builder
{

class Init_NavigationGoal_SendGoal_Response_stamp
{
public:
  explicit Init_NavigationGoal_SendGoal_Response_stamp(::custom_interfaces::action::NavigationGoal_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::action::NavigationGoal_SendGoal_Response stamp(::custom_interfaces::action::NavigationGoal_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::action::NavigationGoal_SendGoal_Response msg_;
};

class Init_NavigationGoal_SendGoal_Response_accepted
{
public:
  Init_NavigationGoal_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigationGoal_SendGoal_Response_stamp accepted(::custom_interfaces::action::NavigationGoal_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_NavigationGoal_SendGoal_Response_stamp(msg_);
  }

private:
  ::custom_interfaces::action::NavigationGoal_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::action::NavigationGoal_SendGoal_Response>()
{
  return custom_interfaces::action::builder::Init_NavigationGoal_SendGoal_Response_accepted();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace action
{

namespace builder
{

class Init_NavigationGoal_GetResult_Request_goal_id
{
public:
  Init_NavigationGoal_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::action::NavigationGoal_GetResult_Request goal_id(::custom_interfaces::action::NavigationGoal_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::action::NavigationGoal_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::action::NavigationGoal_GetResult_Request>()
{
  return custom_interfaces::action::builder::Init_NavigationGoal_GetResult_Request_goal_id();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace action
{

namespace builder
{

class Init_NavigationGoal_GetResult_Response_result
{
public:
  explicit Init_NavigationGoal_GetResult_Response_result(::custom_interfaces::action::NavigationGoal_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::action::NavigationGoal_GetResult_Response result(::custom_interfaces::action::NavigationGoal_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::action::NavigationGoal_GetResult_Response msg_;
};

class Init_NavigationGoal_GetResult_Response_status
{
public:
  Init_NavigationGoal_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigationGoal_GetResult_Response_result status(::custom_interfaces::action::NavigationGoal_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_NavigationGoal_GetResult_Response_result(msg_);
  }

private:
  ::custom_interfaces::action::NavigationGoal_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::action::NavigationGoal_GetResult_Response>()
{
  return custom_interfaces::action::builder::Init_NavigationGoal_GetResult_Response_status();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace action
{

namespace builder
{

class Init_NavigationGoal_FeedbackMessage_feedback
{
public:
  explicit Init_NavigationGoal_FeedbackMessage_feedback(::custom_interfaces::action::NavigationGoal_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::action::NavigationGoal_FeedbackMessage feedback(::custom_interfaces::action::NavigationGoal_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::action::NavigationGoal_FeedbackMessage msg_;
};

class Init_NavigationGoal_FeedbackMessage_goal_id
{
public:
  Init_NavigationGoal_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigationGoal_FeedbackMessage_feedback goal_id(::custom_interfaces::action::NavigationGoal_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_NavigationGoal_FeedbackMessage_feedback(msg_);
  }

private:
  ::custom_interfaces::action::NavigationGoal_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::action::NavigationGoal_FeedbackMessage>()
{
  return custom_interfaces::action::builder::Init_NavigationGoal_FeedbackMessage_goal_id();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__ACTION__DETAIL__NAVIGATION_GOAL__BUILDER_HPP_
