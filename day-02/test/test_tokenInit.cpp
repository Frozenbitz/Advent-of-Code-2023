#include "token.h"
#include <cassert>
#include <iostream>

int main()
{

    {
        std::string test1{"3 blue"};
        token testToken{test1};
        assert(testToken.color == "blue");
        assert(testToken.CubeVal == 3);
    }

    {
        std::string test2{"14 red"};
        token testToken{test2};
        assert(testToken.color == "red");
        assert(testToken.CubeVal == 14);
    }

    {
        std::string test3{"20 red"};
        token testToken{test3};
        assert(testToken.color == "red");
        assert(testToken.CubeVal == 20);
    }

    {
        std::string test4{"100 green"};
        token testToken{test4};
        assert(testToken.color == "green");
        assert(testToken.CubeVal == 100);
    }

    {
        std::string test5{"12345 blue"};
        token testToken{test5};
        assert(testToken.color == "blue");
        assert(testToken.CubeVal == 12345);
    }

    {
        std::string test6{"1 hello"};
        try
        {
            token testToken{test6};
        }
        catch (const std::invalid_argument& e)
        {
            assert(true);
        }
    }

    {
        std::string test7{"2 bluex"};
        token testToken{test7};
        assert(testToken.color == "blue");
        assert(testToken.CubeVal == 2);
    }

    return 0; // You can put a 1 here to see later that it would generate an
              // error
}