#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <fstream>
#include <iostream>
#include <vector>

#include "states.h"


class AlmanacToBlocks {
private:
    State currentState;

public:
    // here we store the different blocks
    std::vector<int> seeds;
    std::vector<std::string> Seed2Soil;
    std::vector<std::string> Soil2Fertilizer;
    std::vector<std::string> Fertilizer2Water;
    std::vector<std::string> Water2Light;
    std::vector<std::string> Light2Temperature;
    std::vector<std::string> Temperature2Humidity;
    std::vector<std::string> Humidity2Location;

public:
    AlmanacToBlocks();

    void handleLine(std::string line);
    void handleStateSeeds(std::string line);

};




#endif // STATEMACHINE_H
