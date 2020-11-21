#include "camera_calibration.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

using std::vector;
using cv::Mat;
using cv::Point3f;
using cv::Point2f;

CameraCalibration::CameraCalibration(std::string path, const int *chess_size) : path_{path}{

    chess_xsize_ = chess_size[0];
    chess_ysize_ = chess_size[1];
}

CameraCalibration::~CameraCalibration(){}

void CameraCalibration::calibrate(){
    
    Mat image, grayscale;
    
    bool found;
    vector<Point2f> corners;
    vector<vector<Point2f>> image_points;

    vector<Point3f> obj_point;
    vector<vector<Point3f>> obj_points;

    Mat camera_matrix = Mat::eye(3, 3, CV_64F);
    Mat dist_coeffs = Mat::zeros(8, 1, CV_64F);
    vector<Mat> rvecs, tvecs;

    cv::Size board_size = cv::Size(chess_xsize_,chess_ysize_);

    for (int i = 0; i < chess_ysize_; i++){
        for (int j = 0; j < chess_xsize_; j++)
        {
            obj_point.emplace_back(Point3f(j, i, 0));
        }
    }

    samples_.setFilenames(path_);
    while (!samples_.empty())
    {
        std::string Filename = samples_.getNextfilename();
        image = cv::imread(Filename);
        cv::cvtColor(image, grayscale, cv::COLOR_RGB2GRAY);
        bool found = cv::findChessboardCorners(grayscale, board_size, corners, 3);
        if (found){
            image_points.push_back(corners);
            obj_points.push_back(obj_point);
        }
        
    }
    
    double rms = cv::calibrateCamera(obj_points, image_points, grayscale.size(), camera_matrix,
                                                                    dist_coeffs, rvecs, tvecs);
    image = cv::imread("../imgs/calibration2.jpg");
    //cv::undistort(image, undistort_image, camera_matrix, dist_coeffs);
}