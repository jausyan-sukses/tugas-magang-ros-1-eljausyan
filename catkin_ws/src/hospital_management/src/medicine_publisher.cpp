#include "hospital_management/medicine_publisher.h"
#include <sstream>
#include <iostream>

MedicinePublisher::MedicinePublisher() {
    medicine_pub_ = nh_.advertise<std_msgs::String>("medicine_info", 1000);
    getUserInput();
}

void MedicinePublisher::getUserInput() {
    std::cout << "Masukkan Nama Obat: ";
    std::getline(std::cin, medicine_name_);
    
    std::cout << "Masukkan Takaran Obat: ";
    std::getline(std::cin, dosage_);
}

void MedicinePublisher::publishMedicine() {
    std_msgs::String msg;
    std::stringstream ss;
    ss << "Obat: " << medicine_name_ << ", Takaran: " << dosage_;
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());
    medicine_pub_.publish(msg);
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "medicine_publisher");
    MedicinePublisher medicinePublisher;

    ros::Rate loop_rate(1);
    while (ros::ok()) {
        medicinePublisher.publishMedicine();
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}

