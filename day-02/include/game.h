#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>

class game // add hidden definition here
{
public:
    int gameID = -1; // 0 could be used
    std::string gameKey;
    
    game() = delete;
    game(const std::string & input);
    ~game() = default;

    // add an ostream overload for formatting
    friend std::ostream& operator<< (std::ostream& out, const game& aToken)
    {
        out << aToken.gameKey << " - ID:" << aToken.gameID;
        return out;
    }
};

#endif // GAME_H