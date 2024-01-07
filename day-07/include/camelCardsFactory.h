#ifndef CAMELCARDSFACTORY_H
#define CAMELCARDSFACTORY_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <regex>
// #include <map>
#include <unordered_map>
#include "camelCards.h"

class camelCardsFactory {
    std::string filename;
    std::vector<camelCards> cards;

public:
    camelCardsFactory(std::string input); // constructor

    std::vector<std::string> readLinesFromFile (const std::string& filename);
    std::vector<std::string> splitString(const std::string& line);
    std::vector<camelCards> getCards();
};

#endif // CAMELCARDSFACTORY_H