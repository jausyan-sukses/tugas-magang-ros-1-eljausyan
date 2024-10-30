#ifndef HOSPITAL_MANAGEMENT_PATIENT_PUBLISHER_H
#define HOSPITAL_MANAGEMENT_PATIENT_PUBLISHER_H

#include "ros/ros.h"
#include "std_msgs/String.h"
#include <string>

class PatientPublisher {
public:
    PatientPublisher();

    // Setters
    void setPatientName(const std::string &name);
    void setPatientAge(int age);
    void setPatientID(int id);
    void setKeluhan(const std::string &keluhan);

    // Getters
    std::string getPatientName() const;
    int getPatientAge() const;
    int getPatientID() const;
    std::string getKeluhan() const;

    void publishPatientInfo();
    
private:
    ros::NodeHandle nh_;
    ros::Publisher patient_pub_;
    
    std::string patient_name_;
    int patient_age_;
    int patient_id_;
    std::string keluhan_;

    void getUserInput();
    std::string diagnose();
};

#endif
