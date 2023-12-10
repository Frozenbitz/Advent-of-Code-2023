#include "trebuchet.h"
#include <iostream>

int main()
{
    {
        trebuchetCalibration TCalibrate1(0);
        std::string case1 = R"(two1nine)";
        if (TCalibrate1.parseCalibrationLineAlpha(case1) != 29)
            return 1;
    }

    {
        trebuchetCalibration TCalibrate2(0);
        std::string case2 = R"(eightwothree)";
        if (TCalibrate2.parseCalibrationLineAlpha(case2) != 83)
            return 2;
    }

    {
        trebuchetCalibration TCalibrate3(0);
        std::string case3 = R"(4nineeightseven2)";
        if (TCalibrate3.parseCalibrationLineAlpha(case3) != 42)
            return 3;
    }

    {
        trebuchetCalibration TCalibrate4(0);
        std::string case4 = R"(zoneight234)";
        if (TCalibrate4.parseCalibrationLineAlpha(case4) != 14)
            return 4;
    }

    {
        trebuchetCalibration TCalibrate5(0);
        std::string case5 = R"(7pqrstsixteen)";
        if (TCalibrate5.parseCalibrationLineAlpha(case5) != 76)
            return 5;
    }

    return 0; 
}