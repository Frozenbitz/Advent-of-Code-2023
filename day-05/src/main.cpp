#include <fstream>
#include <iostream>
#include <string>

// #include "..."

int main()
{
    std::ifstream almanac{{"./examples/example.txt"}, std::ifstream::in};

    if (not almanac.is_open())
        throw std::invalid_argument("wrong file name/path, could not open!");

    std::string line;
    while (std::getline(almanac, line))
    {
        // Process each line of the file and collect all games


        if (almanac.eof())
            break; // stop
    }
  
    if (almanac.bad())
    {
        std::cout << "failed to read stream, try again!" << std::endl;
        throw std::ios_base::failure("wrong file name/path, could not open!");
    }

    return 0;
}

