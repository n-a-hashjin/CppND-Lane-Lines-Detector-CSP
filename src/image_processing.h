#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H
#include <opencv2/imgproc.hpp>
#include <opencv2/core/types.hpp>
#include <vector>

using cv::Point;
using std::vector;
using cv::Mat;
class ImageProcessing
{
public:
    ImageProcessing(vector<vector<int>> vertices);
    ~ImageProcessing();
    void regionOfInterest(Mat &frame, Mat &masked);
private:
    std::vector<Point> vertices_;
};


#endif