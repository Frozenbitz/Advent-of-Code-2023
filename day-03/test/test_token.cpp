#include "token.h"
#include <cassert>
#include <iostream>

int main()
{

    {
        token testToken{"12345", 1, 2, {"...123@#$.."}};
        assert(testToken.verify() == true);
    }

    {
        token testToken{"12345", 1, 2, {"......."}};
        assert(testToken.verify() == false);
    }

    {
        try
        {
           token testToken{"-42", 2, 2, {"...123@#$.."}};
        }
        catch(const std::invalid_argument& e)
        {
        assert(true);
        }
    }

    return 0;
}