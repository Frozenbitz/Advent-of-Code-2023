#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include <regex>

#include "Node.h"

class Navigator {
public:
    Navigator(std::string file); // constructor
    ~Navigator() = default; // destructor


    std::vector<std::string> readLinesFromFile (const std::string& filename);
    Node splitString(const std::string& line);
    int traverseFromTo(std::string from, std::string to) const;

private:
    std::vector<std::string> directionInstructions;
    std::map<std::string, Node> nodes;
};

#endif // NAVIGATOR_H