#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::string inputPath{"./examples"};
    std::string inputFile{"/example.txt"};
    std::ifstream inputFileHandle{{inputPath + inputFile}, std::ifstream::in};

    if (not inputFileHandle.is_open())
        throw std::invalid_argument("wrong file name/path, could not open!");

    std::string line;
    // std::vector<cubeConundrum> games;
    while (std::getline(inputFileHandle, line))
    {
        // Process each line of the file and collect all games
        // games.push_back(cubeConundrum(line));

        if (inputFileHandle.eof())
            break; // stop
    }

    if (inputFileHandle.bad())
    {
        std::cout << "failed to read stream, try again!" << std::endl;
        throw std::ios_base::failure("wrong file name/path, could not open!");
    }

    return 0;
}
