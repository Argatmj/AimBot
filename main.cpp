#include <iostream>
#include "opencv2/opencv.hpp"
#include "serialib.h" 

#define DEVICE_PORT "COM3"  

int main() {
    cv::VideoCapture cap(0);
    cv::CascadeClassifier face_cascade, eye_cascade;

    serialib serial;
    if (serial.openDevice(DEVICE_PORT, 9600) != 1) {
        std::cerr << "Failed to open serial port!" << std::endl;
        return -1;
    }

    if (!face_cascade.load("C:/Users/user/opencv/sources/data/haarcascades/haarcascade_frontalface_default.xml")) {
        std::cout << "Error loading face cascade";
        return -1;
    }

    if (!cap.isOpened()) {
        std::cout << "Camera can't be opened";
        return -1;
    }

    cv::Mat frame;

    while (cap.read(frame)) {
        if (frame.empty()) {
            std::cout << "Unable to capture frame";
            break;
        }

        cv::Mat grayscale;
        cv::cvtColor(frame, grayscale, cv::COLOR_BGR2GRAY);
        cv::GaussianBlur(grayscale, grayscale, cv::Size(5, 5), 0);
        cv::equalizeHist(grayscale, grayscale);

        std::vector<cv::Rect> faces;
        face_cascade.detectMultiScale(grayscale, faces, 1.1, 10, 0, cv::Size(60, 60));

        for (size_t i = 0; i < faces.size(); i++) {
            cv::Point face_center(faces[i].x + faces[i].width / 2,faces[i].y + faces[i].height / 3);
            cv::circle(frame, face_center,5, cv::Scalar(0, 0, 255), -1);
            cv::Mat face= grayscale(faces[i]);

            std::string data = std::to_string(face_center.x) + "," + std::to_string(face_center.y) + "\n";
            serial.writeString(data.c_str());
        }

        cv::imshow("video", frame);
        if (cv::waitKey(5) == 'q') {
            break;
        }
    }

    cap.release();
    cv::destroyAllWindows();
    return 0;
}
