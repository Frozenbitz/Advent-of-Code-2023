#include "camelCards.h"

#include <iostream>
#include <stdexcept>


camelCards::camelCards(std::string cards, int newBid) :
    bid{newBid}, power{0}, cardHands{cards}
{
    // create a map of cards (this stores the amount of each card)
    std::map<std::string, int> tmp;
    for (auto && mappedValue : cards)
    {
        tmp[{mappedValue}] += 1;
    }

    tmp = applyJokerRule(tmp);
    
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
         {{ "A", 14 }, { "K", 13 }, { "Q", 12}, {"J", 1}, {"T", 10}, {"9", 9}, // updated J
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


std::string camelCards::getMaxKey(std::map<std::string, int> keyStore) const {

    // find the max value in the map
    int maxValue = 0;
    std::string maxKey = "";

    for (auto && values : keyStore)
    {
        if (maxValue < values.second) {
            maxValue = values.second;
            maxKey = values.first;
        }
    }
    
    return maxKey;
}


std::map<std::string, int> camelCards::applyJokerRule(std::map<std::string, int> keyStore) const {

    // if we have an "J", find the possible max value
    // add J to max value
    // remove J from the map
    // this should only change the power, not rule 2 below (operator<)

    if (keyStore.contains("J")){
        int JMax = keyStore.at({"J"});

        if (JMax == 5)
            return {{"AAAAA", 5}};

        if (JMax > 0) {
            keyStore.erase({"J"});
            std::string key = getMaxKey(keyStore);
            keyStore.at({key}) += JMax;
        }
    }

    return keyStore;
}