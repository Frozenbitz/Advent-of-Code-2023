#ifndef CAMELCARDS_H
#define CAMELCARDS_H

#include <algorithm>    // std::min_element, std::max_element, std::sort
#include <string>
#include <vector>
#include <ranges>
#include <utility>
#include <memory>
#include <iostream>

class camelCards {
    // Class members and methods go here

public:
    camelCards(std::string cards, int newBid); // constructor

    // other methods...
    int getBid() const;
    int getPower() const;
    bool operator<(const camelCards& other) const;

private:
    int bid;
    int power;
    std::vector<std::pair<std::string, int>> hand;
    std::string cardHands;
};

#endif // CAMELCARDS_H