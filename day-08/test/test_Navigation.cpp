#include <iostream>

#include "Navigator.h"
#include <cassert>

int main() {
    
    {
        Navigator nav {"testdata/test01.txt"};
        int steps = nav.traverseFromTo("AAA", "AAA");
        assert(steps == 0);
    }

    {
        Navigator nav {"testdata/test01.txt"};
        try
        {
            int steps = nav.traverseFromTo("AAA", "ZZZ");
        }
        catch(const std::invalid_argument& e)
        {
            // caught
        }        
    }

    {
        Navigator nav {"testdata/test02.txt"};
        int steps = nav.traverseFromTo("AAA", "ZZZ");
        assert(steps == 6);
    }

    return 0; 
}