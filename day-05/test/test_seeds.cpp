#include <iostream>
#include <cassert>

#include "AlmanacToBlock.h"

int main() {
    
    {
        std::string line = "seeds: 79 14 55 13"; 
        AlmanacToBlocks stateMachine;
        stateMachine.handleLine(line);
        assert(stateMachine.seeds.size() == 4);
        assert(stateMachine.seeds.at(0) == 79);
        assert(stateMachine.seeds.at(1) == 14);
        assert(stateMachine.seeds.at(2) == 55);
        assert(stateMachine.seeds.at(3) == 13);
    }

    {
        std::string line = "seeds: 79 123456 55 13"; 
        AlmanacToBlocks stateMachine;
        stateMachine.handleLine(line);
        assert(stateMachine.seeds.size() == 4);
        assert(stateMachine.seeds.at(0) == 79);
        assert(stateMachine.seeds.at(1) == 123456);
        assert(stateMachine.seeds.at(2) == 55);
        assert(stateMachine.seeds.at(3) == 13);
    }

    {
        std::string line = "seeds: 1"; 
        AlmanacToBlocks stateMachine;
        stateMachine.handleLine(line);
        assert(stateMachine.seeds.size() == 1);
        assert(stateMachine.seeds.at(0) == 1);
    }

    return 0; 
}