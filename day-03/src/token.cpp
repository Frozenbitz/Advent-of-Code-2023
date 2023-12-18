#include "token.h"
#include <stdexcept>

token::token(std::string const& tokenValue, int line, int offset,
             std::string newNeighbours)
    : value{tokenValue}, parsedValue{stoi(tokenValue)},
      location{{"line", line}, {"offset", offset}}, neighbours{newNeighbours}
{
    if (parsedValue < 0)
        throw std::invalid_argument("token cannot be negative");
}

bool token::verify() const
{
    std::string lookupSymbols {"@#$%&*+=-"};

    if (neighbours.find_first_of(lookupSymbols) != std::string::npos)
    {
        return true;
    }
    
    return false;
}

int token::getValue() const
{
    return parsedValue;
}