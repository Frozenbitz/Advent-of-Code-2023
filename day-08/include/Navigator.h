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
    int ghostlyTraverse() const;
    bool atEnd(std::vector<std::string> const & currentSteps) const;

private:
    std::vector<std::string> directionInstructions;
    std::map<std::string, Node> nodes;

    std::vector<std::string> start;
};

#endif // NAVIGATOR_H