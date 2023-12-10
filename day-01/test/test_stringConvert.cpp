#include "trebuchet.h"
#include <iostream>

int main()
{
    // init an empty/testable trebuchet
    trebuchetCalibration TCalibrate1(0);

    std::string two = "two";
    if (TCalibrate1.stringToInt(two) != 2)
        return 1;
    
    std::string mfour = "minus four";
    if (TCalibrate1.stringToInt(mfour) != -1)
        return 2;

    std::string eight = "eight";
    if (TCalibrate1.stringToInt(eight) != 8)
        return 3;

        std::string ten = "ten";
    if (TCalibrate1.stringToInt(ten) != -1)
        return 4;

    return 0; 
}