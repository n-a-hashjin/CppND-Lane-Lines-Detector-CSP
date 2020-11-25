#include <iostream>
#include <string>
#include "file_handle.h"
#include "camera_calibration.h"
#include "preprocessing.h"
#include <unistd.h>
#include <opencv2/opencv.hpp>


enum Param {
    rho=2,
    theta = 1,
    threshold = 15,
    min_len = 40,
    max_gap = 20,
};

int main() {
    
    unsigned int usecs{1000000};
    std::cout << "Starting program!\r" << std::flush;
    usleep(usecs);
    
    cv::Mat ppFrame;
    cv::Mat frame = cv::imread("../imgs/test2.jpg");
    preprocessing preproc;
    preproc.runPreprocessing(frame, ppFrame);
    /*
    std::string path = "../imgs/";
    unsigned int chess_size[2] = {9,6};
    CameraCalibration calibration(path, chess_size);
    CameraCalibration calibration
    calibration.setUserInput();
    */
    std::cout << "goodbye...       \r" << std::flush;
    usleep(usecs);
    std::cout << "goodbye.. \r" << std::flush;
    usleep(usecs);
    std::cout << "goodbye. \r" << std::flush;
    usleep(usecs);
    std::cout << "goodbye \r" << std::flush;
    usleep(usecs);
    return 0;
}