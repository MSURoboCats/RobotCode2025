// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_interfaces:msg/ImuData.idl
// generated code does not contain a copyright notice
#include "custom_interfaces/msg/detail/imu_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `orientation`
#include "geometry_msgs/msg/detail/quaternion__functions.h"
// Member `euler_angles`
// Member `angular_velocity`
// Member `linear_acceleration`
#include "geometry_msgs/msg/detail/vector3__functions.h"

bool
custom_interfaces__msg__ImuData__init(custom_interfaces__msg__ImuData * msg)
{
  if (!msg) {
    return false;
  }
  // global_time_seconds
  // orientation
  if (!geometry_msgs__msg__Quaternion__init(&msg->orientation)) {
    custom_interfaces__msg__ImuData__fini(msg);
    return false;
  }
  // euler_angles
  if (!geometry_msgs__msg__Vector3__init(&msg->euler_angles)) {
    custom_interfaces__msg__ImuData__fini(msg);
    return false;
  }
  // angular_velocity
  if (!geometry_msgs__msg__Vector3__init(&msg->angular_velocity)) {
    custom_interfaces__msg__ImuData__fini(msg);
    return false;
  }
  // linear_acceleration
  if (!geometry_msgs__msg__Vector3__init(&msg->linear_acceleration)) {
    custom_interfaces__msg__ImuData__fini(msg);
    return false;
  }
  return true;
}

void
custom_interfaces__msg__ImuData__fini(custom_interfaces__msg__ImuData * msg)
{
  if (!msg) {
    return;
  }
  // global_time_seconds
  // orientation
  geometry_msgs__msg__Quaternion__fini(&msg->orientation);
  // euler_angles
  geometry_msgs__msg__Vector3__fini(&msg->euler_angles);
  // angular_velocity
  geometry_msgs__msg__Vector3__fini(&msg->angular_velocity);
  // linear_acceleration
  geometry_msgs__msg__Vector3__fini(&msg->linear_acceleration);
}

bool
custom_interfaces__msg__ImuData__are_equal(const custom_interfaces__msg__ImuData * lhs, const custom_interfaces__msg__ImuData * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // global_time_seconds
  if (lhs->global_time_seconds != rhs->global_time_seconds) {
    return false;
  }
  // orientation
  if (!geometry_msgs__msg__Quaternion__are_equal(
      &(lhs->orientation), &(rhs->orientation)))
  {
    return false;
  }
  // euler_angles
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->euler_angles), &(rhs->euler_angles)))
  {
    return false;
  }
  // angular_velocity
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->angular_velocity), &(rhs->angular_velocity)))
  {
    return false;
  }
  // linear_acceleration
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->linear_acceleration), &(rhs->linear_acceleration)))
  {
    return false;
  }
  return true;
}

bool
custom_interfaces__msg__ImuData__copy(
  const custom_interfaces__msg__ImuData * input,
  custom_interfaces__msg__ImuData * output)
{
  if (!input || !output) {
    return false;
  }
  // global_time_seconds
  output->global_time_seconds = input->global_time_seconds;
  // orientation
  if (!geometry_msgs__msg__Quaternion__copy(
      &(input->orientation), &(output->orientation)))
  {
    return false;
  }
  // euler_angles
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->euler_angles), &(output->euler_angles)))
  {
    return false;
  }
  // angular_velocity
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->angular_velocity), &(output->angular_velocity)))
  {
    return false;
  }
  // linear_acceleration
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->linear_acceleration), &(output->linear_acceleration)))
  {
    return false;
  }
  return true;
}

custom_interfaces__msg__ImuData *
custom_interfaces__msg__ImuData__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__msg__ImuData * msg = (custom_interfaces__msg__ImuData *)allocator.allocate(sizeof(custom_interfaces__msg__ImuData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_interfaces__msg__ImuData));
  bool success = custom_interfaces__msg__ImuData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_interfaces__msg__ImuData__destroy(custom_interfaces__msg__ImuData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_interfaces__msg__ImuData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_interfaces__msg__ImuData__Sequence__init(custom_interfaces__msg__ImuData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__msg__ImuData * data = NULL;

  if (size) {
    data = (custom_interfaces__msg__ImuData *)allocator.zero_allocate(size, sizeof(custom_interfaces__msg__ImuData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_interfaces__msg__ImuData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_interfaces__msg__ImuData__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_interfaces__msg__ImuData__Sequence__fini(custom_interfaces__msg__ImuData__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_interfaces__msg__ImuData__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_interfaces__msg__ImuData__Sequence *
custom_interfaces__msg__ImuData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__msg__ImuData__Sequence * array = (custom_interfaces__msg__ImuData__Sequence *)allocator.allocate(sizeof(custom_interfaces__msg__ImuData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_interfaces__msg__ImuData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_interfaces__msg__ImuData__Sequence__destroy(custom_interfaces__msg__ImuData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_interfaces__msg__ImuData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_interfaces__msg__ImuData__Sequence__are_equal(const custom_interfaces__msg__ImuData__Sequence * lhs, const custom_interfaces__msg__ImuData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_interfaces__msg__ImuData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_interfaces__msg__ImuData__Sequence__copy(
  const custom_interfaces__msg__ImuData__Sequence * input,
  custom_interfaces__msg__ImuData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_interfaces__msg__ImuData);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_interfaces__msg__ImuData * data =
      (custom_interfaces__msg__ImuData *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_interfaces__msg__ImuData__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_interfaces__msg__ImuData__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_interfaces__msg__ImuData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
