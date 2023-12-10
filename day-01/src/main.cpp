#include "trebuchet.h"
#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::string inputPath {"./examples/"};
    std::string inputFile {"/riddle.txt"};
    trebuchetCalibration TCalibrate(inputPath, inputFile);

    // return the calibration data
    std::cout << TCalibrate.getCalibrationData() << std::endl;

    return 0;
}
