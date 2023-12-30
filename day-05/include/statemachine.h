#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <fstream>
#include <iostream>
#include <vector>

#include "states.h"


class StateMachine_AlmanacToBlocks {
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
    StateMachine_AlmanacToBlocks();

    void handleLine(std::string line);
    void handleStateSeeds(std::string line);
    // void handleStateSeedToSoil(std::string line);
    // void handleStateSoilToFertilizer(std::string line);
    // void handleStateFertilizerToWater(std::string line);
    // void handleStateWaterToLight(std::string line);
    // void handleStateLightToTemperature(std::string line);
    // void handleStateTemperatureToHumidity(std::string line);
    // void handleStateHumidityToLocation(std::string line);

};




#endif // STATEMACHINE_H
