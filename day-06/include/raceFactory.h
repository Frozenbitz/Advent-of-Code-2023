#ifndef RACE_PARSER_H
#define RACE_PARSER_H

#include <vector>
#include <string>
#include <fstream>
#include <regex>  
#include <ranges>  

#include "race.h"

class raceFactory {
public:
    raceFactory(const std::string& filename);
    std::vector<Race> getRaces();
    std::vector<std::string> readLinesFromFile (const std::string& filename);
    std::vector<int> splitString(const std::string& line);

private:
    std::string filename;
    std::vector<Race> races;
};

#endif // RACE_PARSER_H