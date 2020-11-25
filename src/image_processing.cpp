#include "image_processing.h"
#include <opencv2/core/hal/interface.h>
#include <opencv2/core.hpp>

#define RAD 3.14159265359/180
ImageProcessing::ImageProcessing(vector<vector<int>> vertices)
{
    while (!vertices.empty())
    {
        vector<int> point = vertices.back();
        vertices_.push_back(Point(point[0],point[1]));
        vertices.pop_back();
    }
    
    
}

ImageProcessing::~ImageProcessing()
{
}

void ImageProcessing::regionOfInterest(cv::Mat &frame, cv::Mat &masked){
    masked = Mat::zeros(frame.size(), CV_8UC3);
    Mat mask = Mat::zeros(frame.size(), CV_8UC1);
    cv::fillPoly(mask, vertices_, cv::Scalar(255, 255, 255), 8, 0);
    cv::bitwise_and(frame, mask, masked);
}