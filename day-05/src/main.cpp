#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "statemachine.h"

int main()
{
    std::ifstream almanac{{"./examples/example.txt"}, std::ifstream::in};

    if (not almanac.is_open())
        throw std::invalid_argument("wrong file name/path, could not open!");

    std::string line;
    std::vector<std::string> almanac_lines; // build a vector of lines
    while (std::getline(almanac, line))
    {
        // Process each line of the file and create the mapping
        almanac_lines.push_back(line);

        if (almanac.eof())
            break; // stop
    }

    // use a vector of lines to build the foundaiton of the different blocks
    StateMachine_AlmanacToBlocks state_machine;
    for (auto &&line : almanac_lines)
    {
        state_machine.handleLine(line);
    }

    std::vector<std::vector<std::string>> almanac_map;
    // ...
  
    if (almanac.bad())
    {
        std::cout << "failed to read stream, try again!" << std::endl;
        throw std::ios_base::failure("wrong file name/path, could not open!");
    }

    return 0;
}

