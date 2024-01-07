#ifndef CAMELCARDS_H
#define CAMELCARDS_H

#include <algorithm>    // std::min_element, std::max_element, std::sort
#include <string>
#include <vector>
#include <ranges>
#include <utility>
#include <memory>
#include <iostream>
#include <map>

class camelCards {
    // Class members and methods go here

public:
    camelCards(std::string cards, int newBid); // constructor

    // other methods...
    int getBid() const;
    int getPower() const;
    bool operator<(const camelCards& other) const;
    std::string getMaxKey(std::map<std::string, int> keyStore) const;
    std::map<std::string, int> applyJokerRule(std::map<std::string, int> keyStore) const;

private:
    int bid;
    int power;
    std::vector<std::pair<std::string, int>> hand;
    std::string cardHands;
};

#endif // CAMELCARDS_H