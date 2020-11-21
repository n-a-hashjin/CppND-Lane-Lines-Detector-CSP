#include <iostream>
#include <string>
#include "file_handle.h"
#include "camera_calibration.h"

int main() {
    std::cout << "Hi!" << std::endl;

    std::string path = "../imgs/";
    int chess_size[2] = {9,6};
    CameraCalibration calibration(path, chess_size);
    calibration.calibrate();

    std::cout << "goodbye!" << std::endl;
    return 0;
}