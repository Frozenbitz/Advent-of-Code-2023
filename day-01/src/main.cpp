#include "trebuchet.h"
#include <fstream>
#include <iostream>
#include <string>

int main()
{

    // here are the main steps:
    // provide a file containing the data to analyse
    // std::string inputDataFileName =
    // "/home/peter/Coding/AdventOfCode/day-01/example3.txt";
    std::string inputDataFileName =
    "/home/peter/Coding/AdventOfCode/day-01/riddle.txt";
    // std::string inputDataFileName =
    //     "/home/peter/Coding/AdventOfCode/day-01/example2.txt";

    // create a trebuchet object to calculate the data

    trebuchetCalibration TCalibrate(inputDataFileName);

    // return the calibration data
    std::cout << TCalibrate.getCalibrationData() << std::endl;

    return 0;
}
