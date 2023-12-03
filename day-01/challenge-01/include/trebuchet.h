#ifndef TREBUCHET_H
#define TREBUCHET_H

// Contents of your trebuchet.h header file go here
#include <iostream>
#include <fstream>
#include <string>


class trebuchetCalibration
{
private:
    /* data */

    // filehandle
    std::ifstream inputFileHandle;

    // trebuchet parameters
    unsigned trebuchetCalibrationValue;

    unsigned parseCalibrationLine(const std::string & lineOfText) const;

public:
    trebuchetCalibration() = delete;
    trebuchetCalibration(std::string const & inputFileName);
    ~trebuchetCalibration();

    unsigned getCalibrationData() const;
};


#endif // TREBUCHET_H
