#ifndef CUBECONUNDRUM_H
#define CUBECONUNDRUM_H

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "token.h"

class cubeConundrum
{
private:
    /* data */
    // std::ifstream inputFileHandle;
    std::unordered_map<std::string, int> cumulativeGameData;

public:
    cubeConundrum() = delete;
    cubeConundrum(std::string const& lineOfText); // parse and represent a single game
    ~cubeConundrum() = default;

    std::vector<std::string> split(const std::string& s, char delimiter);
    std::vector<token> tokenizeColorRangeFromString ( const std::string & lineOfText);

    void tokenMax(const std::vector<token> & tokenVector);
    int getCumulativeGameData(std::string const & key) const;
    bool setCumulativeGameData(std::string const & key, int value);
    bool evaluateGame(int red, int green, int blue) const;
    int evaluatePower() const;
};

#endif // CUBECONUNDRUM_H
