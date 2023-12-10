#include "trebuchet.h"
#include <exception>
#include <regex>
#include <string_view>
#include <unordered_map>

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
    // value not found
    constexpr int none = -1;

    // compound for allocating string and position inside vector
    struct lookup
    {
        std::string digit;
        std::vector<int> recordedPosition = {none};
    };

    // this returns all the available positions from the numeric string
    // but double digits are not yet implemented! (eg. "twofkljktwoonetwo")
    std::vector<lookup> lookupAlphString{
        {"zero", {}}, {"one", {}}, {"two", {}},   {"three", {}}, {"four", {}},
        {"five", {}}, {"six", {}}, {"seven", {}}, {"eight", {}}, {"nine", {}},
        {"0", {}}, {"1", {}}, {"2", {}},   {"3", {}}, {"4", {}},
        {"5", {}}, {"6", {}}, {"7", {}}, {"8", {}}, {"9", {}}};

    // parse all written numerals
    const std::string testAlph = lineOfText;
    for (auto& lookup : lookupAlphString)
    {
        auto stringPosition = 0;
        do{
            stringPosition = testAlph.find(lookup.digit, stringPosition);
            if (stringPosition != std::string::npos)
            {
                lookup.recordedPosition.push_back(stringPosition);
                stringPosition++;
            }
        } while (stringPosition != std::string::npos);
    }

    int string_size = testAlph.size() + 1;
    lookup firstCalibrationValue {"", {string_size}}; // make sure this is greater than any encoded value
    for (const auto &found : lookupAlphString)
    {
        for (auto & actualPosition : found.recordedPosition)
        {
            if (actualPosition != none && actualPosition < firstCalibrationValue.recordedPosition[0])
            {
                firstCalibrationValue.digit = found.digit;
                firstCalibrationValue.recordedPosition[0] = actualPosition;
            }
        }        
    }

    lookup lastCalibrationValue {"", {none}}; // make sure this is lesser than any encoded value
    for (const auto &found : lookupAlphString)
    {
        for (auto & actualPosition : found.recordedPosition)
        {
            if (actualPosition != none && actualPosition > lastCalibrationValue.recordedPosition[0])
            {
                lastCalibrationValue.digit = found.digit;
                lastCalibrationValue.recordedPosition[0] = actualPosition;
            }
        }  
    }  

    if (firstCalibrationValue.recordedPosition[0] == string_size || lastCalibrationValue.recordedPosition[0] == none)
        throw std::runtime_error{"Calibration value could not be found"};

    return (stringToInt(firstCalibrationValue.digit) * 10) + stringToInt(lastCalibrationValue.digit);
}

int trebuchetCalibration::stringToInt(const std::string& str) const
{
    static const std::unordered_map<std::string, int> lookup = {
        {"zero", 0}, {"one", 1}, {"two", 2},   {"three", 3}, {"four", 4},
        {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9},
        {"0", 0}, {"1", 1}, {"2", 2},   {"3", 3}, {"4", 4},
        {"5", 5}, {"6", 6}, {"7", 7}, {"8", 8}, {"9", 9}};

    auto it = lookup.find(str);
    if (it != lookup.end())
    {
        return it->second;
    }
    else
    {
        // Handle error or return a default value
        return -1; // Example: return -1 for not found
    }
}