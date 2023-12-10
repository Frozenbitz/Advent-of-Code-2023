#include "trebuchet.h"
#include <iostream>

int main()
{
    // create a trebuchet object to calculate the data, test will fail on
    // exception
    // TODO we could add tests for this, to try different settings on streams
    std::string inputPath {"./testdata/"};
    trebuchetCalibration TCalibrate1(inputPath, std::string{"testDigits.txt"});
    if (TCalibrate1.getCalibrationData() != 281) return -1;
    
    return 0; // You can put a 1 here to see later that it would generate an
              // error
}