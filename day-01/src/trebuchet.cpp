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
        std::string str;
        int x = none;
    };

    // this returns all the available positions from the numeric string
    // but double digits are not yet implemented! (eg. "twofkljktwoonetwo")
    std::vector<lookup> lookupAlphString{
        {"zero", none}, {"one", none}, {"two", none},   {"three", none}, {"four", none},
        {"five", none}, {"six", none}, {"seven", none}, {"eight", none}, {"nine", none},
        {"0", none}, {"1", none}, {"2", none},   {"3", none}, {"4", none},
        {"5", none}, {"6", none}, {"7", none}, {"8", none}, {"9", none}};

    // parse all written numerals
    const std::string testAlph = lineOfText;
    for (auto& lookup : lookupAlphString)
    {
        auto stringPosition = testAlph.find(lookup.str);
        if (stringPosition != std::string::npos)
        {
            lookup.x = stringPosition;
        }
    }

    int string_size = testAlph.size() + 1;
    lookup firstCalibrationValue {"", string_size}; // make sure this is greater than any encoded value
    for (const auto &i : lookupAlphString)
    {
        if (i.x != none && i.x < firstCalibrationValue.x)
        {
            firstCalibrationValue = i;
        }
    }

    lookup lastCalibrationValue {"", -1}; // make sure this is lesser than any encoded value
    for (const auto &i : lookupAlphString)
    {
        if (i.x != none && i.x > lastCalibrationValue.x)
        {
            lastCalibrationValue = i;
        }
    }  

    if (firstCalibrationValue.x == string_size || lastCalibrationValue.x == none)
        throw std::runtime_error{"Calibration value could not be found"};

    return (stringToInt(firstCalibrationValue.str) * 10) + stringToInt(lastCalibrationValue.str);
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