#include "cubeConundrum.h"
#include <sstream>
#include <regex>


cubeConundrum::cubeConundrum(std::string const& inputPath,
                             std::string const& inputData)
    : inputFileHandle{{inputPath + inputData}, std::ifstream::in},
      cumulativeGameData{
          {"redMax", 0}, {"greenMax", 0}, {"blueMax", 0},
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
        // input files are tokenized with ";" >> our data extraction should be
        //  based on this, otherwise part 2 will be pain

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
    tokenizedString.pop_back(); // remove the element we want to further split
    tokenizedString.insert(tokenizedString.end(), games.begin(), games.end());

    std::vector<std::string> outputVector;
    for (auto const & cubeToken : tokenizedString)
    {
        std::vector tmp = split(cubeToken, ',');
        outputVector.insert(outputVector.end(), tmp.begin(), tmp.end());
    }

    for (auto const & i : outputVector)
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


token cubeConundrum::stringToToken(const std::string& str) const
{
    return token(str);
}
