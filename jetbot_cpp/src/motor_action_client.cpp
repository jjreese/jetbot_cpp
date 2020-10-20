//#include "action_tutorials_interfaces/action/fibonacci.hpp"
#include "rclcpp/rclcpp.hpp"

#include "rclcpp_action/rclcpp_action.hpp"
#include "rclcpp_components/register_node_macro.hpp"


class MotorActionClient : public rclcpp::Node
{
public:
  using Motor = action_tutorials_interfaces::action::Motor;
  using GoalHandleMotor = rclcpp_action::ClientGoalHandle<Motor>;
  MotorActionClient(const rclcpp::NodeOptions & node_options = rclcpp::NodeOptions())
  : Node("Motor_action_client", node_options)
  {
    this->client_ptr_ = rclcpp_action::create_client<Motor>(
      this->get_node_base_interface(),
      this->get_node_graph_interface(),
      this->get_node_logging_interface(),
      this->get_node_waitables_interface(),
      "Motor");

    this->timer_ = this->create_wall_timer(
      std::chrono::milliseconds(500),
      std::bind(&FibonacciActionClient::send_goal, this));
  }

private:
  rclcpp_action::Client<Motor>::SharedPtr client_ptr_;
  rclcpp::TimerBase::SharedPtr timer_;
