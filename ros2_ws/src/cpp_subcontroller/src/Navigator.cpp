/**
 * Navigator.cpp
 * Responsible for autonomous navigation between tasks
 */

#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <time.h>
#include <math.h>

#include "rclcpp/rclcpp.hpp"

#include "custom_interfaces/msg/world_map.hpp"
#include "custom_interfaces/msg/map_object.hpp"
#include "custom_interfaces/msg/aabb.hpp"
#include "builtin_interfaces/msg/time.hpp"


#include "sensor_msgs/msg/imu.hpp"
#include "std_msgs/msg/header.hpp"
#include "geometry_msgs/msg/vector3.hpp"
#include "geometry_msgs/msg/quaternion.hpp"

using std::placeholders::_1;

using namespace std::chrono_literals; 

using namespace std;

#define ACCEL_NOISE_THRESHOLD 0.2 



class Navigator : public rclcpp::Node{
    public:
    Navigator() : Node("navigator"){
        this->declare_parameter("imu_topic", "camera/camera/imu");
        this->declare_parameter("world_map_topic","WorldMap");
        s_worldMap = this->create_subscription<custom_interfaces::msg::WorldMap>(
            this->get_parameter("world_map_topic").as_string(), 
            5,
            std::bind(&Navigator::WorldMapCallback, this, _1)
        );
        s_IMU = this->create_subscription<sensor_msgs::msg::Imu>(
            this->get_parameter("imu_topic").as_string(),
            5,
            std::bind(&Navigator::IMUCallback,this,_1)
        );

        this->m_cachedMap = custom_interfaces::msg::WorldMap();
        this->m_cachedIMU = sensor_msgs::msg::Imu();

        this->m_cachedIMU.header.frame_id = "-1";
        this->m_cachedMap.header.frame_id = "-1";

    }


    private:

    custom_interfaces::msg::WorldMap    m_cachedMap;
    sensor_msgs::msg::Imu               m_cachedIMU;



    bool IsNewData(const std_msgs::msg::Header &original, const std_msgs::msg::Header &compare){
        bool isOriginalInvalid = original.frame_id.compare("-1") == 0;

        if(isOriginalInvalid) return true; 

        bool isFrameIDDifferent = original.frame_id.compare(compare.frame_id) != 0;

        bool isTimeStampDifferent = !((original.stamp.sec == compare.stamp.sec) && (original.stamp.nanosec == compare.stamp.nanosec));

        return isFrameIDDifferent && isTimeStampDifferent;

    }


    void IMUCallback(const sensor_msgs::msg::Imu &msg){
        if(this->m_cachedIMU.header.frame_id.compare("-1") != 0){
            // first IMU message
            this->m_cachedIMU = msg;
        }
        else if(IsNewData(this->m_cachedIMU.header,msg.header)){
            // TODO: Handle IMU new data
            this->m_cachedIMU = msg;
            RCLCPP_WARN(this->get_logger(),"Navigator::IMUCallback() : Warning! : new IMU data not handled outside of re-assigning cache! Please impliment me!");
        }

    }

    void WorldMapCallback(const custom_interfaces::msg::WorldMap &msg){
        if(IsNewData(this->m_cachedMap.header,msg.header)){
            this->m_cachedMap = msg;
        }
    }
   

    
    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr s_IMU;
    rclcpp::Subscription<custom_interfaces::msg::WorldMap>::SharedPtr s_worldMap;
};


int main(int argc, char* argv[]){
    rclcpp::init(argc, argv);

    
    rclcpp::spin(std::make_shared<Navigator>());
    


    rclcpp::shutdown();
    return 0;
}
