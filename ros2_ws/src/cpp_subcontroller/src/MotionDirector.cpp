/// MotionDirector.cpp
/// publishes commands to the "MotionionGoal" topic.
/// Temporary node used for testing purposes, meant to simulate
/// a more in-depth navigation node that would use some sort of 
/// PID to navigate from point to point


#include <chrono>
#include <functional>
#include <memory>
#include <string>


#include "rclcpp/rclcpp.hpp"
#include "custom_interfaces/msg/motion_goal.hpp"


using namespace std::chrono_literals;

using namespace std;

class MotionDirector : public rclcpp::Node{
    public:
        MotionDirector() : Node("motion_director"){
            publisher_ = this->create_publisher<custom_interfaces::msg::MotionGoal>("MotionGoal",5);
            timer_ = this->create_wall_timer(2s,std::bind(&MotionDirector::PublisherCallback,this));

            declare_parameter("cmd","halt");
        } 
    
    private:
        void PublisherCallback(){
            auto message = custom_interfaces::msg::MotionGoal();
            get_parameter("cmd",message.goal);

            RCLCPP_INFO(this->get_logger(),"Publishing Command: '%s'", message.goal.c_str());

            publisher_->publish(message);
        }
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Publisher<custom_interfaces::msg::MotionGoal>::SharedPtr publisher_;
};


int main(int argc, char* argv[]){
    rclcpp::init(argc, argv);

    
    rclcpp::spin(std::make_shared<MotionDirector>());
    


    rclcpp::shutdown();
    return 0;
}