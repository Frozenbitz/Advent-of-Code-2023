#ifndef CUBECONUNDRUM_H
#define CUBECONUNDRUM_H

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

class cubeConundrum
{
private:
    /* data */
    std::ifstream inputFileHandle;
    std::unordered_map<std::string, int> cumulativeGameData;
    int gameSum = 0;

public:
    cubeConundrum() = delete;
    cubeConundrum(std::string const& inputPath, std::string const& inputData);
    ~cubeConundrum() = default;

    // public handles
    void checkInputFile();
    void parseInputFile();
    void openInputFile();

    std::vector<std::string> split(const std::string& s, char delimiter);
    void readColorRangeFromText ( const std::string & lineOfText);
};

#endif // CUBECONUNDRUM_H
