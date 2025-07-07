// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_interfaces:msg/AABB.idl
// generated code does not contain a copyright notice
#include "custom_interfaces/msg/detail/aabb__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `center`
#include "geometry_msgs/msg/detail/point__functions.h"
// Member `extents`
#include "geometry_msgs/msg/detail/vector3__functions.h"

bool
custom_interfaces__msg__AABB__init(custom_interfaces__msg__AABB * msg)
{
  if (!msg) {
    return false;
  }
  // center
  if (!geometry_msgs__msg__Point__init(&msg->center)) {
    custom_interfaces__msg__AABB__fini(msg);
    return false;
  }
  // extents
  if (!geometry_msgs__msg__Vector3__init(&msg->extents)) {
    custom_interfaces__msg__AABB__fini(msg);
    return false;
  }
  return true;
}

void
custom_interfaces__msg__AABB__fini(custom_interfaces__msg__AABB * msg)
{
  if (!msg) {
    return;
  }
  // center
  geometry_msgs__msg__Point__fini(&msg->center);
  // extents
  geometry_msgs__msg__Vector3__fini(&msg->extents);
}

bool
custom_interfaces__msg__AABB__are_equal(const custom_interfaces__msg__AABB * lhs, const custom_interfaces__msg__AABB * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // center
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->center), &(rhs->center)))
  {
    return false;
  }
  // extents
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->extents), &(rhs->extents)))
  {
    return false;
  }
  return true;
}

bool
custom_interfaces__msg__AABB__copy(
  const custom_interfaces__msg__AABB * input,
  custom_interfaces__msg__AABB * output)
{
  if (!input || !output) {
    return false;
  }
  // center
  if (!geometry_msgs__msg__Point__copy(
      &(input->center), &(output->center)))
  {
    return false;
  }
  // extents
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->extents), &(output->extents)))
  {
    return false;
  }
  return true;
}

custom_interfaces__msg__AABB *
custom_interfaces__msg__AABB__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__msg__AABB * msg = (custom_interfaces__msg__AABB *)allocator.allocate(sizeof(custom_interfaces__msg__AABB), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_interfaces__msg__AABB));
  bool success = custom_interfaces__msg__AABB__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_interfaces__msg__AABB__destroy(custom_interfaces__msg__AABB * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_interfaces__msg__AABB__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_interfaces__msg__AABB__Sequence__init(custom_interfaces__msg__AABB__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__msg__AABB * data = NULL;

  if (size) {
    data = (custom_interfaces__msg__AABB *)allocator.zero_allocate(size, sizeof(custom_interfaces__msg__AABB), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_interfaces__msg__AABB__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_interfaces__msg__AABB__fini(&data[i - 1]);
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
custom_interfaces__msg__AABB__Sequence__fini(custom_interfaces__msg__AABB__Sequence * array)
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
      custom_interfaces__msg__AABB__fini(&array->data[i]);
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

custom_interfaces__msg__AABB__Sequence *
custom_interfaces__msg__AABB__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__msg__AABB__Sequence * array = (custom_interfaces__msg__AABB__Sequence *)allocator.allocate(sizeof(custom_interfaces__msg__AABB__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_interfaces__msg__AABB__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_interfaces__msg__AABB__Sequence__destroy(custom_interfaces__msg__AABB__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_interfaces__msg__AABB__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_interfaces__msg__AABB__Sequence__are_equal(const custom_interfaces__msg__AABB__Sequence * lhs, const custom_interfaces__msg__AABB__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_interfaces__msg__AABB__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_interfaces__msg__AABB__Sequence__copy(
  const custom_interfaces__msg__AABB__Sequence * input,
  custom_interfaces__msg__AABB__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_interfaces__msg__AABB);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_interfaces__msg__AABB * data =
      (custom_interfaces__msg__AABB *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_interfaces__msg__AABB__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_interfaces__msg__AABB__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_interfaces__msg__AABB__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
