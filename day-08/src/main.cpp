#include <algorithm>    // std::min_element, std::max_element, std::sort
// #include <atomic>       // std::atomic (hard to use)
// #include <execution>    //parallel execution

// #include <limits>       // std::numeric_limits
// #include <ranges>
// #include <string>
// #include <unordered_map>
// #include <vector>
// #include <numeric>

#include "camelCards.h"
#include "camelCardsFactory.h"


int main()
{
    
    camelCardsFactory parser {"examples/riddle.txt"};
    std::vector<camelCards> listOfCamelCards = parser.getCards();

    std::sort(listOfCamelCards.begin(), listOfCamelCards.end());
    
    long totalWinnings = 0;
    for (auto cardNo : std::ranges::iota_view(0, static_cast<int>(listOfCamelCards.size())))
    {
        totalWinnings += (cardNo + 1) * listOfCamelCards.at(cardNo).getBid();
    }

    std::cout << "All winnings together: " << totalWinnings << std::endl;

    return 0;
}

