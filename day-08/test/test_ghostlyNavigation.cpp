#include <iostream>

#include "Navigator.h"
#include <cassert>

int main() {
    
    {
        Navigator nav {"testdata/test03.txt"};
        int steps = nav.ghostlyTraverse();
        assert(steps == 6);
    }

    return 0; 
}