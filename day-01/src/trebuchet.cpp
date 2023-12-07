#include "trebuchet.h"
#include <exception>
#include <regex>
#include <string_view>

trebuchetCalibration::trebuchetCalibration(unsigned initVal)
    : trebuchetCalibrationValue(initVal) // ignore the filehandle for testing
{
}

trebuchetCalibration::trebuchetCalibration(std::string const& inputFileName)
    : inputFileHandle(inputFileName,
                      std::ifstream::in), // ctor for a file handle
      trebuchetCalibrationValue(0)
{
    // parse the error handling of the input stream
    openInputFile();

    // run the parser and calculate needed data
    parseInputFile();

    // check the stream status after parsing
    checkInputFile();
}

trebuchetCalibration::~trebuchetCalibration() { inputFileHandle.close(); }

unsigned trebuchetCalibration::getCalibrationData() const
{
    return trebuchetCalibrationValue; // return calculated sum for calibration
}

void trebuchetCalibration::openInputFile()
{
    if (not inputFileHandle.is_open())
    {
        throw std::invalid_argument("wrong file name/path, could not open!");
    }
}

void trebuchetCalibration::parseInputFile()
{
    std::string line;
    while (std::getline(inputFileHandle, line))
    {
        // Process each line of the file and sum up all values
        trebuchetCalibrationValue += parseCalibrationLineAlpha(line);

        if (inputFileHandle.eof())
            break; // stop
    }
}

void trebuchetCalibration::checkInputFile()
{
    if (inputFileHandle.bad())
    {
        std::cout << "failed to read stream, try again!" << std::endl;
        throw std::ios_base::failure("wrong file name/path, could not open!");
    }
}

// parses a single line of text
// the following token need to be extracted from start and from end
// 1-9, one, two, three, four, five, six, seven, eight, nine
// extracted token need to be parsed and returned as a single uint value
unsigned trebuchetCalibration::parseCalibrationLineAlpha(
    const std::string& lineOfText) const
{
    // compound for allocating string and position
    struct lookup
    {
        std::string_view str;
        int x;
    };

    std::vector<lookup> lookupAlphString{
        {"zero", 0}, {"one", 0}, {"two", 0},   {"three", 0}, {"four", 0},
        {"five", 0}, {"six", 0}, {"seven", 0}, {"eight", 0}, {"nine", 0}};
    std::vector<lookup> lookupDigitString{{"0123456789", 0}};

    std::string_view test = lineOfText;

    for(auto & lookup : lookupAlphString)
    {
        auto foundDigit = test.find(lookup.str);
        if (foundDigit != std::string::npos)
        {
            lookup.x = foundDigit;
            std::cout << foundDigit;
        }
    }

    
    auto found = test.find(lookupAlphString[1].str);
    if (found != std::string::npos) 
    {
        std::cout << found << std::endl;
    } 
    else
    {
        std::cout << "not found" << std::endl;
    }

    return 0;
}

// parse a single line of parameters
// rules are simple:
// in each line of text there can either be 1 or 2 digits
// if we have 2 digits, these make up the number
// if we have only 1, we need to create a 2 digit number with this digit (1
// -> 11, ...)
unsigned
trebuchetCalibration::parseCalibrationLine(const std::string& lineOfText) const
{
    // match either the first or the last digit
    // match can be (m1,g1) or (m2,g2)
    std::regex left_pattern("^[a-z,A-Z]*([0-9])", std::regex::egrep);
    std::regex right_pattern("([0-9])[a-z,A-Z]*$", std::regex::egrep);

    std::smatch lmatch;
    std::smatch rmatch;
    int returnVal = 0;
    if (std::regex_search(lineOfText, lmatch, left_pattern) &&
        std::regex_search(lineOfText, rmatch, right_pattern))
    {
        std::stringstream concat;
        concat << lmatch[1].str() << rmatch[1].str();
        // std::cout << concat.str() << std::endl;3
        concat >> returnVal;
        // std::cout << lmatch[1].str() << std::endl;
        // std::cout << rmatch[1].str() << std::endl;
    }

    return returnVal;
}