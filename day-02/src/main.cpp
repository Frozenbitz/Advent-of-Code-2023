#include <fstream>
#include <iostream>
#include <string>
#include "cubeConundrum.h"

int main()
{
    std::string inputPath {"./examples"};
    std::string inputFile {"/riddle.txt"};
    std::ifstream inputFileHandle{{inputPath + inputFile}, std::ifstream::in};

    if (not inputFileHandle.is_open())
        throw std::invalid_argument("wrong file name/path, could not open!");
    

    std::string line;
    std::vector<cubeConundrum> games;
    while (std::getline(inputFileHandle, line))
    {
        // input files are tokenized with ";" >> our data extraction should be
        //  based on this, otherwise part 2 will be pain

        // Process each line of the file and collect all games
        games.push_back(cubeConundrum(line));

        if (inputFileHandle.eof())
            break; // stop
    }

    if (inputFileHandle.bad())
    {
        std::cout << "failed to read stream, try again!" << std::endl;
        throw std::ios_base::failure("wrong file name/path, could not open!");
    }

    int sumOfIds = 0;
    for (auto & i : games)
    {
        if (i.evaluateGame(12,13,14) == true)
        {
            sumOfIds += i.getCumulativeGameData("Game");
        }
    }

    std::cout << "The sum of all possible IDs is: " << sumOfIds << std::endl;

    return 0;
}
