#include <fstream>
#include <iostream>
#include <string>

#include "card.h"

int main()
{
    std::ifstream inputFileHandle{{"./examples/example.txt"}, std::ifstream::in};

    if (not inputFileHandle.is_open())
        throw std::invalid_argument("wrong file name/path, could not open!");

    std::string line;
    std::vector<card> games;
    while (std::getline(inputFileHandle, line))
    {
        // Process each line of the file and collect all games
        games.push_back(card(line));

        if (inputFileHandle.eof())
            break; // stop
    }
  
    if (inputFileHandle.bad())
    {
        std::cout << "failed to read stream, try again!" << std::endl;
        throw std::ios_base::failure("wrong file name/path, could not open!");
    }

    int sumOfPoints = 0;
    for (auto &&game : games)
    {
        sumOfPoints += game.getPoints();
    }
    
    std::cout << "the total amount of points is: " << sumOfPoints << std::endl;

    return 0;
}

