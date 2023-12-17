#include "game.h"
#include "regex"
#include <iostream>

// -----------------------------------------------------------------------------
// Add Implementation for game

game::game(const std::string& input) :
gameID{-1}, gameKey{"Game"} 
{
    std::string pattern = R"(^[[:space:]]*Game[[:space:]]?([[:digit:]]+))";
    std::regex token_pattern(pattern, 
                            std::regex::ECMAScript|
                            std::regex::multiline); // for ^ support 
    std::smatch tmatch;

    if (std::regex_search(input, tmatch, token_pattern))
    {
        gameID = stoi(tmatch[1]);
    }

    // stop if we cannot construct
    if (gameID < 0)
        throw std::invalid_argument("missing the game ID");
}   