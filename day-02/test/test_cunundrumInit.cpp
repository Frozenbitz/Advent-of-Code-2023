#include "cubeConundrum.h"
#include <cassert>
#include <iostream>

int main()
{

    {
        std::string test1{"Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green"};
        cubeConundrum testConundrum{test1};
        assert(testConundrum.getCumulativeGameData("Game") == 1);
        assert(testConundrum.getCumulativeGameData("red") == 4);
        assert(testConundrum.getCumulativeGameData("green") == 2);
        assert(testConundrum.getCumulativeGameData("blue") == 6);
        assert(testConundrum.evaluateGame(12, 13, 14) == true);
    }

    {
        std::string test2{"Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue"};
        cubeConundrum testConundrum{test2};
        assert(testConundrum.getCumulativeGameData("Game") == 2);
        assert(testConundrum.getCumulativeGameData("red") == 1);
        assert(testConundrum.getCumulativeGameData("green") == 3);
        assert(testConundrum.getCumulativeGameData("blue") == 4);
        assert(testConundrum.evaluateGame(12, 13, 14) == true);
    }

    {
        std::string test3{"Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red"};
        cubeConundrum testConundrum{test3};
        assert(testConundrum.getCumulativeGameData("Game") == 3);
        assert(testConundrum.getCumulativeGameData("red") == 20);
        assert(testConundrum.getCumulativeGameData("green") == 13);
        assert(testConundrum.getCumulativeGameData("blue") == 6);
        assert(testConundrum.evaluateGame(12, 13, 14) == false);
    }

    {
        std::string test4{"Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red"};
        cubeConundrum testConundrum{test4};
        assert(testConundrum.getCumulativeGameData("Game") == 4);
        assert(testConundrum.getCumulativeGameData("red") == 14);
        assert(testConundrum.getCumulativeGameData("green") == 3);
        assert(testConundrum.getCumulativeGameData("blue") == 15);
        assert(testConundrum.evaluateGame(12, 13, 14) == false);
    }

    {
        std::string test5{"Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green"};
        cubeConundrum testConundrum{test5};
        assert(testConundrum.getCumulativeGameData("Game") == 5);
        assert(testConundrum.getCumulativeGameData("red") == 6);
        assert(testConundrum.getCumulativeGameData("green") == 3);
        assert(testConundrum.getCumulativeGameData("blue") == 2);
        assert(testConundrum.evaluateGame(12, 13, 14) == true);
    }

    {
        std::string test5{"Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green"};
        cubeConundrum testConundrum{test5};
        assert(testConundrum.getCumulativeGameData("Game") == 5);
        assert(testConundrum.getCumulativeGameData("red") == 6);
        assert(testConundrum.getCumulativeGameData("green") == 3);
        assert(testConundrum.getCumulativeGameData("blue") == 2);
        assert(testConundrum.evaluateGame(6, 6, 6) == true);
    }

    return 0; // You can put a 1 here to see later that it would generate an
              // error
}