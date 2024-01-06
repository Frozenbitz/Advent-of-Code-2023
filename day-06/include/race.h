#ifndef RACE_H
#define RACE_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <ranges>  

class Race {
public:
    Race(long time, long distance);
    ~Race() = default;


    void SimulateRaces();
    long GetSuccessfullRaces() const;

private:
    long availableTime;
    long distanceToBeat;
    long successfullRaces;
};

#endif // RACE_H