#include "token.h"
#include <stdexcept>

token::token(std::string const& tokenValue, int line, int offset,
             std::string newNeighbours)
    : value{tokenValue}, parsedValue{stoi(tokenValue)},
      location{{"line", line}, {"offset", offset}, {"length", tokenValue.length()}}, neighbours{newNeighbours}
{
    if (parsedValue < 0)
        throw std::invalid_argument("token cannot be negative");
}

bool token::verify() const
{
    std::string lookupSymbols {"/@#$%&*+=-"}; // these are relevant token we need for the neighbours

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

bool token::contains(int line, int offset) const
{
    if (line == location.at("line") &&
        offset >= location.at("offset") && 
        offset <= (location.at("offset") + location.at("length") - 1))
        {
            return true;
        }

    return false;
}


bool token::operator==(const token & rhs) const
{
    if (location.at("line") == rhs.location.at("line") &&
    location.at("offset") == rhs.location.at("offset"))
        return true;

    return false;
}

bool token::operator<(const token & rhs) const
{
    if (location.at("line") <= rhs.location.at("line") &&
    location.at("offset") < rhs.location.at("offset"))
        return true;

    return false;
}