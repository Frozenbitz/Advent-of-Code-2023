#include <fstream>
#include <iostream>
#include <string>
#include "cubeConundrum.h"

int main()
{
    std::string inputPath {"./examples"};
    std::string inputFile {"/example.txt"};
    cubeConundrum(inputPath, inputFile);

    return 0;
}
