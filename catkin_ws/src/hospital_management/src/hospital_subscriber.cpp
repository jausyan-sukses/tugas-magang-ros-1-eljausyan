#include "hospital_management/hospital_subscriber.h"

HospitalSubscriber::HospitalSubscriber() {
    patient_sub_ = nh_.subscribe("patient_info", 1000, &HospitalSubscriber::patientCallback, this);
    medicine_sub_ = nh_.subscribe("medicine_info", 1000, &HospitalSubscriber::medicineCallback, this);
}

void HospitalSubscriber::patientCallback(const std_msgs::String::ConstPtr& msg) {
    ROS_INFO("Data Pasien Diterima: %s", msg->data.c_str());
}

void HospitalSubscriber::medicineCallback(const std_msgs::String::ConstPtr& msg) {
    ROS_INFO("Data Obat Diterima: %s", msg->data.c_str());
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "hospital_subscriber");
    HospitalSubscriber hospitalSubscriber;
    ros::spin();
    return 0;
}
