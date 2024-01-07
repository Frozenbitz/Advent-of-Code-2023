#include "camelCards.h"

#include <iostream>
#include <stdexcept>
#include <map>

camelCards::camelCards(std::string cards, int newBid) :
    bid{newBid}, power{0}, cardHands{cards}
{
    // create a map of cards (this stores the amount of each card)
    std::map<std::string, int> tmp;
    for (auto && mappedValue : cards)
    {
        tmp[{mappedValue}] += 1;
    }

    // create a sorted list of cards
    for (auto && card : tmp)
    {
        hand.push_back(card);
    }

    // lambda for sorting our pairs
    auto boundFunction = [](std::pair<std::string, int> l, std::pair<std::string, int> r) {
        return std::get<int>(l) > std::get<int>(r);
    };

    std::sort(hand.begin(), hand.end(), boundFunction);
    
    // power is calculated based on the available types
    // there are seven available types of hands
    // 1. five of a kind
    // 2. four of a kind
    // 3. full house
    // 4. three of a kind
    // 5. two pairs
    // 6. one pair
    // 7. high card

    if (hand.size() == 1) {
        power = 7;
    } else if (hand.size() == 2) {
        if (hand.begin()->second == 3) {
            power = 5;
        } else {
            power = 6;
        }
    } else if (hand.size() == 3) {
        if (hand.begin()->second == 3) {
            power = 4;
        } else {
            power = 3;
        }
    } else if (hand.size() == 4) {
        power = 2;
    } else {
        power = 1;
    }

}


int camelCards::getBid() const {
    return bid;
}


int camelCards::getPower() const {
    return power;
}


bool camelCards::operator<(const camelCards& other) const {

    // reads this < other
    if (power < other.power) {
        return true;
    } else if (power > other.power) {
        return false;
    }

    // if power is equal, then compare the hands
    std::unordered_map <std::string, int> weights
         {{ "A", 14 }, { "K", 13 }, { "Q", 12}, {"J", 11}, {"T", 10}, {"9", 9},
        {"8", 8}, {"7", 7}, {"6", 6}, {"5", 5}, {"4", 4}, {"3", 3}, {"2", 2}};

    for (auto && index : std::ranges::iota_view(0, 5)) // size of cards
    {
        int lVal = weights.at({cardHands.at(index)});
        int rVal = weights.at({other.cardHands.at(index)});

        if (lVal < rVal) {
            return true;
        } else if (lVal > rVal) {
            return false;
        }
    }

    return true;
}
