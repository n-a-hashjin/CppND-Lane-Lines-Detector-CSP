#include "camera_calibration.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
using namespace cv;
CameraCalibration::CameraCalibration(std::string path, const int *chess_size) : path_{path}{

    chess_xsize_ = chess_size[0];
    chess_ysize_ = chess_size[1];
}

CameraCalibration::~CameraCalibration(){}

void CameraCalibration::calibrate(){
    
    Mat shot;
    Mat grayscale;

    bool found;
    std::vector<Point2f> corners;

    samples_.setFilenames(path_);
    while (!samples_.empty())
    {
        std::string Filename = samples_.getNextfilename();
        shot = imread(Filename);
        cvtColor(shot, grayscale, COLOR_RGB2GRAY);
        bool found = findChessboardCorners(grayscale, Size(chess_xsize_,chess_ysize_), corners, 3);
        drawChessboardCorners(shot, Size(chess_xsize_,chess_ysize_), Mat(corners), found);
        if (!found) std::cout << "No corners are found for '" << Filename << "'" << std::endl;
        namedWindow("Show Image", 1);
        imshow("Show Image", shot);
        waitKey();
    }
    std::cout << path_ << " chess size (x,y): (" << chess_xsize_ << ", " << chess_ysize_ << ")" <<std::endl;
}