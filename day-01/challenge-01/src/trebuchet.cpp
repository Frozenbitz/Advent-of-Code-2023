#include "trebuchet.h"
#include <exception>
#include <regex>

trebuchetCalibration::trebuchetCalibration(std::string const& inputFileName)
    : inputFileHandle(inputFileName,
                      std::ifstream::in), // ctor for a file handle
      trebuchetCalibrationValue(0)
{
    // parse the error handling of the input stream
    if (not inputFileHandle.is_open())
    {
        throw std::invalid_argument("wrong file name/path, could not open!");
    }

    std::string line;
    while (std::getline(inputFileHandle, line))
    {
        // Process each line of the file and sum up all values
        trebuchetCalibrationValue += parseCalibrationLine(line);

        if (inputFileHandle.eof())
            break; // stop
    }

    if (inputFileHandle.bad())
    {
        std::cout << "failed to read stream, try again!" << std::endl;
    }
}

trebuchetCalibration::~trebuchetCalibration() { inputFileHandle.close(); }

// return calculated sum for claibration
unsigned trebuchetCalibration::getCalibrationData() const { return 0; }

// parse a single line of parameters
// rules are simple:
// in each line of text there can either be 1 or 2 digits
// if we have 2 digits, these make up the number
// if we have only 1, we need to create a 2 digit number with this digit (1 ->
// 11, ...)
unsigned
trebuchetCalibration::parseCalibrationLine(const std::string& lineOfText) const
{
    // match either the first or the last digit
    // match can be (m1,g1) or (m2,g2)
    std::regex left_pattern("^[a-z,A-Z]*([0-9])", std::regex::egrep);
    std::regex right_pattern("([0-9])[a-z,A-Z]*$", std::regex::egrep);

    std::smatch lmatch;
    std::smatch rmatch;
    if (std::regex_search(lineOfText, lmatch, left_pattern) &&
        std::regex_search(lineOfText, rmatch, right_pattern))
    {

        std::cout << "current no of matches: " << lmatch.size() << std::endl;
        std::cout << "current no of matches: " << rmatch.size() << std::endl;

        for (auto& i : lmatch)
        {
            std::cout << i.str() << std::endl;
        }
        for (auto& i : rmatch)
        {
            std::cout << i.str() << std::endl;
        }

        // if (matches.size() == 3)
        // {
        //     std::cout << matches[0].str() << std::endl;
        //     std::cout << matches[1].str() << std::endl;
        //     std::cout << matches[2].str() << std::endl;
        // }
        // else if (matches.size() == 2)
        // {
        //     std::cout << matches[1].str() << std::endl;
        // }
        // else
        // {
        //     // throw "failed to extract data";
        // }
    }

    return 1;
}