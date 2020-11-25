#include "preprocessing.h"
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
using cv::Mat;
preprocessing::preprocessing(){
    calibration_.setUserInput();
}

preprocessing::~preprocessing(){}

void preprocessing::runPreprocessing(Mat input, Mat &cannyImage){
    cv::namedWindow("Before", 1);
    imshow("Before", input);
    cv::waitKey();
    Mat undistortImage;
    calibration_.undistort(input, undistortImage);
    Mat blurredImage;
    gaussian_blur(undistortImage, blurredImage, cv::Size(5,5));

    canny(blurredImage, cannyImage, 50, 150);
    cv::namedWindow("After", 1);
    imshow("After", cannyImage);
    cv::waitKey();
}

void preprocessing::gaussian_blur(Mat &image, Mat &blurredImage, cv::Size kernelSize){
    cv::GaussianBlur(image, blurredImage, kernelSize, 0);
}
void preprocessing::canny(Mat &image, Mat &cannyImage,
                    double low_threshold,double high_threshold){

    cv::Canny(image, cannyImage, low_threshold, high_threshold, 3, true);
}