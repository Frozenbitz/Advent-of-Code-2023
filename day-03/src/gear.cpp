#include "gear.h"
#include <stdexcept>

gear::gear(int line, int offset, std::vector<token> newNeighbours)
    : location{{"line", line}, {"offset", offset}}, neighbours{newNeighbours}
{
    if (neighbours.size() != 2)
        throw std::invalid_argument("cannot have more than 2 ratio parameters");
}

int gear::getRatio() const
{
    int ratio = 1;

    for (auto &&i : neighbours)
    {
        ratio *= i.getValue();
    }

    return ratio;
}