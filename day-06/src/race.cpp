#include "race.h"

Race::Race(int time, int distance) :
    availableTime(time),
    distanceToBeat(distance),
    successfullRaces(0)
{
    SimulateRaces();
}

void Race::SimulateRaces() {
    
    for (auto && attempt : std::ranges::iota_view(0, availableTime))
    {
        int startingSpeed = attempt;
        int travelTime = availableTime - attempt;
        int distanceCovered = startingSpeed * travelTime;

        if (distanceCovered > distanceToBeat)
        {
            successfullRaces++;
        }
    }   
}


int Race::GetSuccessfullRaces() const {

    return successfullRaces;
}