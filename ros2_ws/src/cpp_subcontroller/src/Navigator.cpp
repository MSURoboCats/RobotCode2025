/**
 * Navigator.cpp
 * Makes high level decision
 */

#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <time.h>
#include <math.h>

#include "rclcpp/rclcpp.hpp"

#include "custom_interfaces/msg/imu_data.hpp"
#include "geometry_msgs/msg/vector3.hpp"
#include "geometry_msgs/msg/quaternion.hpp"

using std::placeholders::_1;

using namespace std::chrono_literals; 

using namespace std;

#define ACCEL_NOISE_THRESHOLD 0.2 



class Navigator : public rclcpp::Node{
    public:
    Navigator() : Node("navigator"){
        
    }


    private:
    double v3_position[3];             // x,y,z
    double v3_velocity[3];             // x,y,z
    double q_orientation[4];           // w,x,y,z
    double d_lastTimeStamp = 0.0;      // seconds

   

    void Navigator_Subscription_Callback(const custom_interfaces::msg::ImuData &msg){
       
    }
    rclcpp::Subscription<custom_interfaces::msg::ImuData>::SharedPtr subscription_; 
};


int main(int argc, char* argv[]){
    rclcpp::init(argc, argv);

    
    rclcpp::spin(std::make_shared<Navigator>());
    


    rclcpp::shutdown();
    return 0;
}
