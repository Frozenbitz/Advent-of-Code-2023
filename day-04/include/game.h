#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>

class game
{
private:
    std::vector<int> winningNumbers;
    std::vector<int> scratchHands;

public:
    game(std::string const & game);
    ~game() = default;

    int getPoints() const;

};



#endif // GAME_H