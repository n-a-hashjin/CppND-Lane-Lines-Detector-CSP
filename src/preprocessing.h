#ifndef PREPROCESSING_H
#define PREPROCESSING_H
#include "camera_calibration.h"
#include <opencv2/imgproc.hpp>
using cv::Mat;
class preprocessing : CameraCalibration
{
public:
    preprocessing();
    ~preprocessing();
    void runPreprocessing(Mat &input, Mat &cannyImage);
private:
    void gaussian_blur(Mat &image, Mat &blurredImage, cv::Size kernelSize);
    void canny(Mat &image, Mat &cannyImage,double low_threshold,double high_threshold);
    /* data */
    CameraCalibration calibration_;
};


#endif