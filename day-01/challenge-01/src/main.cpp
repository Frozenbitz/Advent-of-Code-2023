#include <iostream>
#include <fstream>
#include <string>
#include "trebuchet.h"

int main() {

    // here are the main steps: 
    // provide a file containing the data to analyse
    // std::string inputDataFileName = "/home/peter/Coding/AdventOfCode/day-01/challenge-01/example.txt";
    // std::string inputDataFileName = "/home/peter/Coding/AdventOfCode/day-01/challenge-01/riddle.txt";
    std::string inputDataFileName = "/home/peter/Coding/AdventOfCode/day-01/challenge-01/example2.txt";

    // create a trebuchet object to calculate the data

    trebuchetCalibration TCalibrate(inputDataFileName);

    // return the calibration data
    std::cout <<  TCalibrate.getCalibrationData() << std::endl;

    return 0;
}
