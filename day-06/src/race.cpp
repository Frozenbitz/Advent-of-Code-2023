#include "race.h"

Race::Race(long time, long distance) :
    availableTime(time),
    distanceToBeat(distance),
    successfullRaces(0)
{
    SimulateRaces();
}

void Race::SimulateRaces() {
    
    for (auto && attempt : std::ranges::iota_view(0, availableTime))
    {
        long startingSpeed = attempt;
        long travelTime = availableTime - attempt;
        long distanceCovered = startingSpeed * travelTime;

        if (distanceCovered > distanceToBeat)
        {
            successfullRaces++;
        }
    }   
}


long Race::GetSuccessfullRaces() const {

    return successfullRaces;
}