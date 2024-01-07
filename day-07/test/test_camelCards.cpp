#include <iostream>

#include <memory>
#include "camelCards.h"
#include <cassert>

int main() {
    
    {
        camelCards myCard("KAQA3", 1);
        assert(myCard.getPower() == 2);
    }

    {
        camelCards myCard("AAAAA", 1);
        assert(myCard.getPower() == 7);
    }

    {
        camelCards myCard("AA8AA", 1);
        assert(myCard.getPower() == 6);
    }

    {
        camelCards myCard("23332", 1);
        assert(myCard.getPower() == 5);
    }

    {
        camelCards myCard("TTT98", 1);
        assert(myCard.getPower() == 4);
    }

    {
        camelCards myCard("T55J5", 1);
        assert(myCard.getPower() == 6); // 6 with joker, 4 before
    }

    {
        camelCards myCard("QQQJA", 1);
        assert(myCard.getPower() == 6); // 6 with joker, 4 before
    }

    {
        camelCards myCard("23432", 1);
        assert(myCard.getPower() == 3);
    }

    {
        camelCards myCard("A23A4", 1);
        assert(myCard.getPower() == 2);
    }

    {
        camelCards myCard("23456", 1);
        assert(myCard.getPower() == 1);
    }

    return 0; // You can put a 1 here to see later that it would generate an error
}