#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <ranges>

#include "cardstash.h"

int main() {
    std::ifstream inputFileHandle{{"./examples/riddle.txt"}, std::ifstream::in};

    if (not inputFileHandle.is_open())
        throw std::invalid_argument("wrong file name/path, could not open!");

    std::string line;
    std::vector<cardstash> stash;
    while (std::getline(inputFileHandle, line)) {
        // Process each line of the file and collect all games
        stash.push_back(cardstash(line));

        if (inputFileHandle.eof())
            break; // stop
    }
  
    if (inputFileHandle.bad()) {
        std::cout << "failed to read stream, try again!" << std::endl;
        throw std::ios_base::failure("wrong file name/path, could not open!");
    }

    std::cout << "available NO of games:" << stash.size() << std::endl;

    // the last card we are allowed to put on the card stash
    int upperCardBounds = stash.back().getID(); 

    std::unordered_map <int, int> collectionOfScratchCards; // <id, sum> ...
    for (auto && someCard : stash) {
        int cardId = someCard.getID();
        int cardPoints = someCard.getPoints();
        int availableCopies = 1;

        if (not collectionOfScratchCards.contains(cardId)) {
            collectionOfScratchCards[cardId] = 1; // new card
        } else {
            collectionOfScratchCards[cardId] += 1; // add the current card
            availableCopies = collectionOfScratchCards[cardId]; // get existing copies!
        }

        int bounds = 0;
        if (cardId + cardPoints < upperCardBounds) {
            bounds = cardId + cardPoints;
        } else {
            bounds = upperCardBounds;
        }

        for (auto copies : std::ranges::iota_view(cardId + 1, bounds + 1)) {
            collectionOfScratchCards[copies] += availableCopies;
        }
    }
    
    int sum = 0;
    for (auto && scratchCard : collectionOfScratchCards)
    {
        sum += scratchCard.second;
    }
    
    std::cout << "Total number of cards: " << sum << std::endl;
    
    // std::cout << "the total amount of points is: " << sumOfPoints << std::endl;

    return 0;
}

