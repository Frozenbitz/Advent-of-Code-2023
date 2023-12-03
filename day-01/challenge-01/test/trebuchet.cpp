#include "trebuchet.h"
#include <iostream>

int main()
{

    // input data as raw string:
    std::string inputData =
        R"(1abc2
    pqr3stu8vwx
    a1b2c3d4e5f
    treb7uchet)";

    std::string inputDataFileName =
        "/home/peter/Coding/AdventOfCode/day-01/challenge-01/example.txt";

    // create a trebuchet object to calculate the data, test will fail on
    // exception
    // TODO we could add tests for this, to try different settings on streams
    try
    {
        trebuchetCalibration TCalibrate(inputDataFileName);

        if (TCalibrate.getCalibrationData() != 77)
            return -1;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }

    return 0; // You can put a 1 here to see later that it would generate an
              // error
}