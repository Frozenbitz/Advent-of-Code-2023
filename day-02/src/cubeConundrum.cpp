#include "cubeConundrum.h"
#include <sstream>


cubeConundrum::cubeConundrum(std::string const& inputPath,
                             std::string const& inputData)
    : inputFileHandle{{inputPath + inputData}, std::ifstream::in},
      cumulativeGameData{
          {"redMin", 0},   {"redMax", 0},  {"greenMin", 0},
          {"greenMax", 0}, {"blueMin", 0}, {"blueMax", 0},
      },
      gameSum(0)
{
    openInputFile();

    // run the parser and calculate needed data
    parseInputFile();

    // check the stream status after parsing
    checkInputFile();
}

void cubeConundrum::openInputFile()
{
    if (not inputFileHandle.is_open())
    {
        throw std::invalid_argument("wrong file name/path, could not open!");
    }
}

void cubeConundrum::parseInputFile()
{
    std::string line;
    while (std::getline(inputFileHandle, line))
    {
        // input files are tokenized with ";" >> our data extraction should be based on this, otherwise part 2 will be pain

        // Process each line of the file and sum up all values
        readColorRangeFromText (line);

        if (inputFileHandle.eof())
            break; // stop
    }
}

void cubeConundrum::checkInputFile()
{
    if (inputFileHandle.bad())
    {
        std::cout << "failed to read stream, try again!" << std::endl;
        throw std::ios_base::failure("wrong file name/path, could not open!");
    }
}


void cubeConundrum::readColorRangeFromText ( const std::string & lineOfText)
{
    std::vector<std::string> tokenizedString = split(lineOfText, {':'});
    std::vector<std::string> games = split(tokenizedString.at(1), {';'});
    tokenizedString.pop_back();
    tokenizedString.insert(tokenizedString.end(), games.begin(), games.end());

    for (auto const & i : tokenizedString)
    {
        std::cout << i << std::endl;
    }
}

// See: https://www.fluentcpp.com/2017/04/21/how-to-split-a-string-in-c/
std::vector<std::string> cubeConundrum::split(const std::string& s, char delimiter)
{
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}

// int cubeConundrum::stringToInt(const std::string& str) const
// {
//     static const std::unordered_map<std::string, int> lookup = {
//         {"zero", 0}, {"one", 1}, {"two", 2},   {"three", 3}, {"four", 4},
//         {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9},
//         {"0", 0},    {"1", 1},   {"2", 2},     {"3", 3},     {"4", 4},
//         {"5", 5},    {"6", 6},   {"7", 7},     {"8", 8},     {"9", 9}};

//     auto it = lookup.find(str);
//     if (it != lookup.end())
//     {
//         return it->second;
//     }
//     else
//     {
//         // Handle error or return a default value
//         return -1; // Example: return -1 for not found
//     }
// }