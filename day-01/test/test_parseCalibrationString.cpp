#include "trebuchet.h"
#include <iostream>

int main()
{
    {
        trebuchetCalibration TCalibrate1(0);
        std::string case1 = R"(two1nine)";
        TCalibrate1.parseCalibrationLineAlpha(case1);
        if (TCalibrate1.getCalibrationData() != 29)
            return -1;
    }

    {
        trebuchetCalibration TCalibrate2(0);
        std::string case2 = R"(eightwothree)";
        TCalibrate2.parseCalibrationLineAlpha(case2);
        if (TCalibrate2.getCalibrationData() != 83)
            return -2;
    }

    {
        trebuchetCalibration TCalibrate3(0);
        std::string case3 = R"(4nineeightseven2)";
        TCalibrate3.parseCalibrationLineAlpha(case3);
        if (TCalibrate3.getCalibrationData() != 42)
            return -3;
    }

    {
        trebuchetCalibration TCalibrate4(0);
        std::string case4 = R"(zoneight234)";
        TCalibrate4.parseCalibrationLineAlpha(case4);
        if (TCalibrate4.getCalibrationData() != 14)
            return -4;
    }

    {
        trebuchetCalibration TCalibrate5(0);
        std::string case5 = R"(7pqrstsixteen)";
        TCalibrate5.parseCalibrationLineAlpha(case5);
        if (TCalibrate5.getCalibrationData() != 76)
            return -5;
    }

    return 0; 
}