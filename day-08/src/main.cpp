#include <algorithm>    // std::min_element, std::max_element, std::sort
// #include <atomic>       // std::atomic (hard to use)
// #include <execution>    //parallel execution

// #include <limits>       // std::numeric_limits
// #include <ranges>
// #include <string>
// #include <unordered_map>
// #include <vector>
// #include <numeric>

#include "Navigator.h"

int main()
{
    
    Navigator nav {"examples/riddle.txt"};
    int steps = nav.traverseFromTo("AAA", "ZZZ");

    std::cout << "Total steps until end: " << steps << std::endl;

    return 0;
}

