#include "image_processing.h"
#include <opencv2/core/hal/interface.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

#define RAD CV_PI/180

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

void ImageProcessing::houghLines(Mat &frame, vector<cv::Vec4i> &lines){
    double rho = 2;
    double theta = 1*RAD;
    int threshold = 15;
    double min_len = 40;
    double max_gap = 20;
    cv::HoughLinesP(frame, lines, rho, theta, threshold, min_len, max_gap);
    ///testing
    /* 
    Mat color_dst;
    cvtColor( frame, color_dst, cv::COLOR_GRAY2BGR );
    for( size_t i = 0; i < lines.size(); i++ )
    {
        cv::line( color_dst, Point(lines[i][0], lines[i][1]),
        Point( lines[i][2], lines[i][3]), cv::Scalar(0,0,255), 3, 8 );
    }
    cv::namedWindow( "Source", 1 );
    cv::imshow( "Source", frame );
    cv::namedWindow( "Detected Lines", 1 );
    cv::imshow( "Detected Lines", color_dst );
    cv::waitKey();
    */
}

void ImageProcessing::drawLaneLines(Mat &src, vector<cv::Vec4i> &lines /*Mat &output*/){
    //double alpha=0.7, beta=1;
    //Mat drawedLineImg = Mat(src.size().height, src.size().width, CV_8UC3);
    //std::cout << "src size, width and height: " << src.size() << " " << src.size().width << " " << src.size().height << std::endl;
    //std::cout << "src size, width and height: " << drawedLineImg.size() << " " << drawedLineImg.size().width << " " << drawedLineImg.size().height << std::endl;
    //cvtColor( src, drawedLineImg, cv::COLOR_GRAY2BGR );

    for( size_t i = 0; i < lines.size(); i++ )
    {
        cv::line( src, Point(lines[i][0], lines[i][1]),
        Point( lines[i][2], lines[i][3]), cv::Scalar(0,0,255), 3, 8 );
    }
    cv::namedWindow( "Detected Lines", 1 );
    cv::imshow( "Detected Lines", src );
    cv::waitKey();
    //output = drawedLineImg;
    //cv::addWeighted( src, alpha, drawedLineImg, beta, 0.0, output);
}

