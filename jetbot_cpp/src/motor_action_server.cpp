#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "rclcpp_components/register_node_macro.hpp"
//#include "action/Motor.hpp"


class MotorActionServer : public rclcpp::Node
 {
  public:
	using Motor = jetbot_cpp::src::action::Motor
	MotorActionServer(const rclcpp::NodeOptions & options = rclcpp::NodeOptions())
	  : Node("motor_action_server",options)
	{
	   using namespace std::placeholders;
	      this->action_server_ = rclcpp_action::create_server<Motor>(
	      this->get_node_base_interface(),
	      this->get_node_clock_interface(),
              this->get_node_logging_interface(),
	      this->get_node_waitables_interface(),
      	      "Motor"//,
              //std::bind(&FibonacciActionServer::handle_goal, this, _1, _2),
              //std::bind(&FibonacciActionServer::handle_cancel, this, _1),
      	      //std::bind(&FibonacciActionServer::handle_accepted, this, _1));
	}

   private:
	rclcpp_action::Server<Motor>::SharedPtr action_server_;


 };
