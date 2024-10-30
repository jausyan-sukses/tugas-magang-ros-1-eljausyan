#ifndef HOSPITAL_MANAGEMENT_HOSPITAL_SUBSCRIBER_H
#define HOSPITAL_MANAGEMENT_HOSPITAL_SUBSCRIBER_H

#include "ros/ros.h"
#include "std_msgs/String.h"

class HospitalSubscriber {
public:
    HospitalSubscriber();
    void patientCallback(const std_msgs::String::ConstPtr& msg);
    void medicineCallback(const std_msgs::String::ConstPtr& msg);

private:
    ros::NodeHandle nh_;
    ros::Subscriber patient_sub_;
    ros::Subscriber medicine_sub_;
};

#endif 
