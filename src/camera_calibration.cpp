#include "camera_calibration.h"
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>
#include <vector>
#include <iostream>

#define CV_64F 6

using std::vector;
using cv::Point3f;
using cv::Point2f;

CameraCalibration::CameraCalibration(){}
CameraCalibration::CameraCalibration(std::string path, unsigned int *chess_size):
                                        chess_xsize_{chess_size[0]},
                                        chess_ysize_{chess_size[1]}{
                                            chess_size_ = cv::Size(chess_xsize_,chess_ysize_);
                                            samples_.setFilenames(path);
                                            runCalibrate();
}

CameraCalibration::~CameraCalibration(){}

void CameraCalibration::setUserInput(){
    std::string path;
    unsigned int chess_xsize, chess_ysize;

    std::cout << "Please enter calibration directory: ";
    std::getline(std::cin, path);
    
    std::cout << "Please enter chessboard width: ";
    std::cin >> chess_xsize;

    std::cout << "Please enter chessboard height: ";
    std::cin >> chess_ysize;

    chess_xsize_ = chess_xsize;
    chess_ysize_ = chess_ysize;
    chess_size_ = cv::Size(chess_xsize,chess_ysize);
    samples_.setFilenames(path);
    runCalibrate();
}

void CameraCalibration::runCalibrate(){
    
    Mat image, grayscale;
    
    bool found;
    vector<Point2f> corners;
    vector<vector<Point2f>> image_points;

    vector<Point3f> obj_point;
    vector<vector<Point3f>> obj_points;

    camera_matrix_ = Mat::eye(3, 3, CV_64F);
    dist_coeffs_ = Mat::zeros(8, 1, CV_64F);
    vector<Mat> rvecs, tvecs;

    for (int i = 0; i < chess_ysize_; i++){
        for (int j = 0; j < chess_xsize_; j++)
        {
            obj_point.emplace_back(Point3f(j, i, 0));
        }
    }

    
    while (!samples_.empty())
    {
        std::string Filename = samples_.getNextfilename();
        image = cv::imread(Filename);
        cv::cvtColor(image, grayscale, cv::COLOR_RGB2GRAY);
        bool found = cv::findChessboardCorners(grayscale, chess_size_, corners, 3);
        if (found){
            image_points.push_back(corners);
            obj_points.push_back(obj_point);
        }
        
    }
    if (!image_points.empty())
    {
        double rms = cv::calibrateCamera(obj_points, image_points, grayscale.size(),
                                            camera_matrix_, dist_coeffs_, rvecs, tvecs);
    }
}

void CameraCalibration::undistort(Mat &input, Mat &output){
    cv::undistort(input, output, camera_matrix_,
                                dist_coeffs_);
}