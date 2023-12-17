#include "token.h"
#include "regex"
#include <iostream>

// -----------------------------------------------------------------------------
// Add Implementation for token

token::token(const std::string& input) :
CubeVal{-1}, color{""} 
{
    std::string pattern = R"(^[[:space:]]*([[:digit:]]+)[[:space:]]*((?:red)|(?:green)|(?:blue)))";
    std::regex token_pattern(pattern, 
                            std::regex::ECMAScript|
                            std::regex::multiline); //be sure to select right mode 
    std::smatch tmatch;

    if (std::regex_search(input, tmatch, token_pattern))
    {
        CubeVal = stoi(tmatch[1]);
        color = tmatch[2];
    }

    // stop if we cannot construct
    if (CubeVal < 0 || color.empty())
        throw std::invalid_argument("missing at least one parameter");
}   
