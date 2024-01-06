#include <algorithm>    // std::min_element, std::max_element, 
// #include <atomic>       // std::atomic (hard to use)
// #include <execution>    //parallel execution

#include <limits>       // std::numeric_limits
#include <ranges>
#include <string>
#include <unordered_map>
#include <vector>
#include <numeric>

#include "raceFactory.h"

int main()
{
    
    raceFactory raceParser {"examples/riddle.txt"};
    std::vector<Race> listOfRace = raceParser.getRaces();

    std::vector<int> success;
    for (auto &&race : listOfRace)
    {
        success.push_back(race.GetSuccessfullRaces());
    }
    
    int results = std::accumulate(success.begin(), success.end(), 1, std::multiplies<int>());
    std::cout << "The number of successfull races is: " << results << '\n';

    return 0;
}

