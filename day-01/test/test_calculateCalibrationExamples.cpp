#include "trebuchet.h"
#include <iostream>

int main()
{
    // create a trebuchet object to calculate the data, test will fail on exception
    std::string inputPath {"./testdata/"};

    // missing this test: four2tszbgmxpbvninebxns6nineqbqzgjpmpqr
    trebuchetCalibration TCalibrate1(inputPath, std::string{"test01.txt"});
    if (TCalibrate1.getCalibrationData() != 285) return 1;

    trebuchetCalibration TCalibrate2(inputPath, {"test02.txt"});
    if (TCalibrate2.getCalibrationData() != 104) return 2;

    trebuchetCalibration TCalibrate3(inputPath, {"test03.txt"});
    if (TCalibrate3.getCalibrationData() != 261) return 3;
    
    return 0; // You can put a 1 here to see later that it would generate an
              // error
}