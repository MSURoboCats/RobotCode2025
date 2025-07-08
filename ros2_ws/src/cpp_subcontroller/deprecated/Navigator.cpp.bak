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


int sign(int x){
    return (x < 0) ? -1 : 1;
}

/// @brief Floors the given value absolutely while preserving signage if the decimal portion is less than a given threshold
/// @param x the value to floor
/// @param threshold the threshold to check against
/// @return x if the decimal portion is above the given threshold, floor(x) if the decimal portion is below a certain threshold
double SignedConditionalFloor(double x, double threshold){
    double minor = abs(x) - abs((int)x);
    
    if(minor < threshold) return floor(abs(x)) * sign(x);
    else return x; 
}

class Navigator : public rclcpp::Node{
    public:
    Navigator() : Node("navigator"){
        subscription_ = this->create_subscription<custom_interfaces::msg::ImuData>("imu",5, std::bind(&Navigator::Navigator_Subscription_Callback,this,_1));
        
        v3_position[0] = v3_position[1] = v3_position[2] = 0;
        
        v3_velocity[0] = v3_velocity[1] = v3_velocity[2] = 0;

        q_orientation[0] = q_orientation[1] = q_orientation[2] = q_orientation[3] = 0;
        d_lastTimeStamp = chrono::duration_cast<std::chrono::seconds>(chrono::system_clock::now().time_since_epoch()).count();
    }


    private:
    double v3_position[3];             // x,y,z
    double v3_velocity[3];             // x,y,z
    double q_orientation[4];           // w,x,y,z
    double d_lastTimeStamp = 0.0;      // seconds

   

    void Navigator_Subscription_Callback(const custom_interfaces::msg::ImuData &msg){
        double cTimeStamp = msg.global_time_seconds; 
        double cAccel[3] = {msg.linear_acceleration.x, msg.linear_acceleration.y,msg.linear_acceleration.z};


        /// This is a pretty crude way of doing it, and produces inaccurate results, try deriving velocity and position using the limit defition of a derivitive

        cAccel[0] = SignedConditionalFloor(cAccel[0],ACCEL_NOISE_THRESHOLD);
        cAccel[1] = SignedConditionalFloor(cAccel[1],ACCEL_NOISE_THRESHOLD);
        cAccel[2] = SignedConditionalFloor(cAccel[2],ACCEL_NOISE_THRESHOLD);

        double deltaTime = cTimeStamp - d_lastTimeStamp; 

        v3_velocity[0] += cAccel[0] * deltaTime;
        v3_velocity[1] += cAccel[1] * deltaTime;
        v3_velocity[2] += cAccel[2] * deltaTime;

        v3_position[0] += v3_velocity[0] * deltaTime;
        v3_position[1] += v3_velocity[1] * deltaTime;
        v3_position[2] += v3_velocity[2] * deltaTime;

        q_orientation[0] = msg.orientation.w;
        q_orientation[1] = msg.orientation.x;
        q_orientation[2] = msg.orientation.y;
        q_orientation[3] = msg.orientation.z;

        d_lastTimeStamp = cTimeStamp;

        stringstream sout; 

        sout << "Read data from IMU:\n\tTimestamp: " << cTimeStamp << ", delta: " << deltaTime << "\n";
        sout << "\tVelocity (x,y,z): " << v3_velocity[0] << ", " << v3_velocity[1] << ", " << v3_velocity[2] << "\n"; 
        sout << "\tPosition (x,y,z): " << v3_position[0] << ", " << v3_position[1] << ", " << v3_position[2] << "\n";
        sout << "\tOrientation (w,x,y,z): " << q_orientation[0] << ", " << q_orientation[1] << ", " << q_orientation[2] << ", " << q_orientation[3] << "\n";


        RCLCPP_INFO(this->get_logger(),"%s",sout.str().c_str());
    }
    rclcpp::Subscription<custom_interfaces::msg::ImuData>::SharedPtr subscription_; 
};


int main(int argc, char* argv[]){
    rclcpp::init(argc, argv);

    
    rclcpp::spin(std::make_shared<Navigator>());
    


    rclcpp::shutdown();
    return 0;
}
