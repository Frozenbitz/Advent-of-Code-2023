#include "game.h"
#include <cassert>
#include <iostream>

int main()
{

    {
        std::string test1{"Game 1"};
        game testGame{test1};
        assert(testGame.gameKey == "Game");
        assert(testGame.gameID == 1);
    }

    {
        std::string test2{"Game 2"};
        game testGame{test2};
        assert(testGame.gameKey == "Game");
        assert(testGame.gameID == 2);
    }

    {
        std::string test2{"Game 42"};
        game testGame{test2};
        assert(testGame.gameKey == "Game");
        assert(testGame.gameID == 42);
    }

    {
        try
        {
            std::string test2{"Gamex 43"};
            game testGame{test2};
        }
        catch(const std::invalid_argument& e)
        {
            assert(true);
        }
    }



    return 0; // You can put a 1 here to see later that it would generate an
              // error
}