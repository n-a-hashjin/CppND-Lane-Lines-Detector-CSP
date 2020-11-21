#ifndef CAMERA_CALIBRATION_H
#define CAMERA_CALIBRATION_H

#include <string>
#include "file_handle.h"
class CameraCalibration {
  public:
    CameraCalibration(std::string,const int *);
    ~CameraCalibration();
    void calibrate();
  private:
    unsigned int chess_xsize_;
    unsigned int chess_ysize_;
    std::string path_;
    FileHandle samples_;
};

#endif