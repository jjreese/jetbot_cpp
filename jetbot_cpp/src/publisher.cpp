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


#include "publisher.h"

/* This example creates a subclass of Node and uses std::bind() to register a
 * member function as a callback from the timer. */

  Motor_Wrapper::Motor_Wrapper()
  : Node("motor_wrapper"), count_(0)
  {
    publisher_ = this->create_publisher<std_msgs::msg::String>("jetbot_motor_string", 10);
    publisher2 = this->create_publisher<geometry_msgs::msg::Twist>("jetbot_motor_twist",10);
  }
 void  Motor_Wrapper::Send(void)
 {
    auto message = std_msgs::msg::String();
    auto twist_msg = geometry_msgs::msg::Twist();
    message.data = "Hello, world! " + std::to_string(count_++);
    //twist_msg = ({x: 0.0, y: 0.0, z: 0.0},{x: 0.0,y: 0.0,z: 0.0});
    RCLCPP_INFO(this->get_logger(), "Publishing Twist Message!: '%s'", message.data.c_str());
    publisher_->publish(message);
    publisher2->publish(twist_msg);
 }



int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Motor_Wrapper>());
  rclcpp::shutdown();
  return 0;
}

