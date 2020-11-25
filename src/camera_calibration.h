#ifndef CAMERA_CALIBRATION_H
#define CAMERA_CALIBRATION_H

#include <string>
#include <opencv2/calib3d.hpp>
#include "file_handle.h"
using cv::Mat;
using cv::Size;

class CameraCalibration {
  public:
    CameraCalibration();
    CameraCalibration(std::string path, unsigned int *chess_size);

    ~CameraCalibration();

    void setUserInput();
    void undistort(Mat &input, Mat &output);
    Mat getCameraMatrix(){ return camera_matrix_; }
    Mat getDistCoeffs(){ return dist_coeffs_; }
  private:
    void runCalibrate();
    unsigned int chess_xsize_, chess_ysize_;
    FileHandle samples_;
    Mat camera_matrix_, dist_coeffs_;
    Size chess_size_;
};

#endif