#ifndef HOSPITAL_MANAGEMENT_MEDICINE_PUBLISHER_H
#define HOSPITAL_MANAGEMENT_MEDICINE_PUBLISHER_H

#include "ros/ros.h"
#include "std_msgs/String.h"
#include <string>

class MedicinePublisher {
public:
    MedicinePublisher();
    void publishMedicine();
   
private:
    ros::NodeHandle nh_;
    ros::Publisher medicine_pub_;
    
    std::string medicine_name_;
    std::string dosage_;

    void getUserInput();
};

#endif 
