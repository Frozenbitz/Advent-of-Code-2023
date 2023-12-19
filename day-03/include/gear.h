#ifndef GEAR_H
#define GEAR_H

#include <string>
#include <unordered_map>
#include <vector>

#include "token.h"

class gear
{
private:
    std::unordered_map<std::string, int> location {{"line", -1}, {"offset", -1}};
    std::vector<token> neighbours {};

public:
    gear(/* args */) = delete;
    gear(int line, int offset, std::vector<token> newNeighbours);
    ~gear() = default;

    int getRatio() const;
};



#endif // GEAR_H