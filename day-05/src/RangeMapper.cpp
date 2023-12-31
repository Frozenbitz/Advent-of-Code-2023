#include "RangeMapper.h"
#include <sstream>

RangeMapper::RangeMapper(const std::vector<std::string>& source) {

    for (auto &&line : source)
    {
        Range tmp = split2Range(line, ' ');
        localRanges.push_back(tmp);
    }
}

long RangeMapper::convert(long value) const {

    long tmp = value;
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
    
    return Range(stol(tokens[0]), stol(tokens[1]), stol(tokens[2]));
}