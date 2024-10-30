#include "hospital_management/patient_publisher.h"
#include <sstream>
#include <iostream>

PatientPublisher::PatientPublisher() {
    patient_pub_ = nh_.advertise<std_msgs::String>("patient_info", 1000);
    getUserInput();
}

void PatientPublisher::setPatientName(const std::string &name) {
    patient_name_ = name;
}

void PatientPublisher::setPatientAge(int age) {
    patient_age_ = age;
}

void PatientPublisher::setPatientID(int id) {
    patient_id_ = id;
}

void PatientPublisher::setKeluhan(const std::string &keluhan) {
    keluhan_ = keluhan;
}

std::string PatientPublisher::getPatientName() const {
    return patient_name_;
}

int PatientPublisher::getPatientAge() const {
    return patient_age_;
}

int PatientPublisher::getPatientID() const {
    return patient_id_;
}

std::string PatientPublisher::getKeluhan() const {
    return keluhan_;
}

void PatientPublisher::getUserInput() {
    std::string name, keluhan;
    int age, id;

    std::cout << "Masukkan Nama Pasien: ";
    std::getline(std::cin, name);
    setPatientName(name);
    
    std::cout << "Masukkan Usia Pasien: ";
    std::cin >> age;
    setPatientAge(age);

    std::cout << "Masukkan ID Pasien: ";
    std::cin >> id;
    setPatientID(id);
    
    std::cin.ignore(); 
    std::cout << "Masukkan Keluhan Pasien: ";
    std::getline(std::cin, keluhan);
    setKeluhan(keluhan);
}

std::string PatientPublisher::diagnose() {
    if (keluhan_ == "demam" || keluhan_ == "sakit kepala") {
        return "Flu atau infeksi virus";
    } else if (keluhan_ == "batuk" || keluhan_ == "sesak napas") {
        return "Infeksi saluran pernapasan";
    } else if (keluhan_ == "nyeri dada") {
        return "Kemungkinan masalah jantung";
    } else {
        return "Penyakit tidak teridentifikasi, segera datang ke rumah sakit rujukan";
    }
}

void PatientPublisher::publishPatientInfo() {
    std_msgs::String msg;
    std::stringstream ss;

    ss << "Nama: " << getPatientName() << ", Usia: " << getPatientAge() 
       << ", ID: " << getPatientID() << ", Keluhan: " << getKeluhan() 
       << ", Diagnosis: " << diagnose();

    msg.data = ss.str();
    ROS_INFO("%s", msg.data.c_str());
    patient_pub_.publish(msg);
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "patient_publisher");
    PatientPublisher patientPublisher;

    ros::Rate loop_rate(1);
    while (ros::ok()) {
        patientPublisher.publishPatientInfo();
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
