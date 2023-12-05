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

public:
    void openInputFile();
    void parseInputFile();
    void checkInputFile();
    unsigned parseCalibrationLineAlpha(const std::string & lineOfText) const;
    unsigned parseCalibrationLine(const std::string& lineOfText) const;

    trebuchetCalibration() = delete;
    trebuchetCalibration(unsigned initVal);
    trebuchetCalibration(std::string const & inputFileName);
    ~trebuchetCalibration();

    unsigned getCalibrationData() const;
};


#endif // TREBUCHET_H
