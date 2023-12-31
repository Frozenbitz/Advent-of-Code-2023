#include "RangeMapper.h"
#include <sstream>

RangeMapper::RangeMapper(const std::vector<std::string>& source) {

    for (auto &&line : source)
    {
        Range tmp = split2Range(line, ' ');
        localRanges.push_back(tmp);
    }
}

int RangeMapper::convert(int value) const {

    int tmp = value;
    for (auto &&subRange : localRanges)
    {
        if (subRange.contains(value))
        {
            return subRange.map(value);
        }
    }
    
    return tmp;
}

Range RangeMapper::split2Range(const std::string& s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    
    return Range(stoi(tokens[0]), stoi(tokens[1]), stoi(tokens[2]));
}