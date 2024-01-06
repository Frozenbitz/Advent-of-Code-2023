#ifndef RACE_H
#define RACE_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <ranges>  

class Race {
public:
    Race(int time, int distance);
    ~Race() = default;


    void SimulateRaces();
    int GetSuccessfullRaces() const;

private:
    int availableTime;
    int distanceToBeat;
    int successfullRaces;
};

#endif // RACE_H