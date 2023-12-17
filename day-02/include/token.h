#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>

#include "string"

class token // add hidden definition here
{
public:
    int CubeVal = 0;
    std::string color;
    
    token() = delete;
    token(const std::string & input);
    ~token() = default;

    // add an ostream overload for formatting
    friend std::ostream& operator<< (std::ostream& out, const token& aToken)
    {
        out << "C:" << aToken.color << " - V:" << aToken.CubeVal;
        return out;
    }
};

#endif // TOKEN_H
