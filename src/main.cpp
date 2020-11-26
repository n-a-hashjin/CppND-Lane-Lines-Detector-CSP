#include "file_handle.h"
#include "camera_calibration.h"
#include "preprocessing.h"
#include "image_processing.h"

#include <opencv2/opencv.hpp>
#include <unistd.h>
#include <iostream>
#include <string>
#include <vector>


int main() {
    
    unsigned int usecs{1000000};
    std::cout << "Starting program!\r" << std::flush;
    usleep(usecs);
    
    cv::Mat ppFrame;
    cv::Mat frame = cv::imread("../imgs/test2.jpg");

    preprocessing preproc;
    preproc.runPreprocessing(frame, ppFrame);
    
    vector<vector<int>> vertices;
    vector<int> top_left, bottom_left, bottom_right, top_right;
    bottom_left.assign({0, 670});
    bottom_right.assign({1280, 670});
    top_right.assign({700, 430});
    top_left.assign({572, 430});

    vertices.push_back(bottom_left);
    vertices.push_back(bottom_right);
    vertices.push_back(top_right);
    vertices.push_back(top_left);
    
    cv::Mat result;
    ImageProcessing imgProc(vertices);
    imgProc.regionOfInterest(ppFrame, result);

    vector<cv::Vec4i> lines;
    imgProc.houghLines(result, lines);
    cv::imshow("result", result);
    cv::waitKey();

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