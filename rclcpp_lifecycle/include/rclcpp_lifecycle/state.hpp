// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef RCLCPP_LIFECYCLE__STATE_HPP_
#define RCLCPP_LIFECYCLE__STATE_HPP_

#include <string>

#include "rclcpp_lifecycle/visibility_control.h"

// forward declare rcl_state_t
typedef struct rcl_lifecycle_state_t rcl_lifecycle_state_t;

namespace rclcpp_lifecycle
{

class State
{
public:
  RCLCPP_LIFECYCLE_PUBLIC
  State();

  RCLCPP_LIFECYCLE_PUBLIC
  State(unsigned int id, const std::string & label);

  RCLCPP_LIFECYCLE_PUBLIC
  explicit State(const rcl_lifecycle_state_t * rcl_lifecycle_state_handle);

  RCLCPP_LIFECYCLE_PUBLIC
  virtual ~State();

  RCLCPP_LIFECYCLE_PUBLIC
  unsigned int
  id() const;

  RCLCPP_LIFECYCLE_PUBLIC
  std::string
  label() const;

protected:
  bool owns_rcl_state_handle_;
  const rcl_lifecycle_state_t * state_handle_;
};

}  // namespace rclcpp_lifecycle
#endif  // RCLCPP_LIFECYCLE__STATE_HPP_
