#ifndef TOKEN_H
#define TOKEN_H

#include "string"

class token // add hidden definition here
{
public:
    int CubeVal = 0;
    std::string color;
    
    token() = delete;
    token(const std::string & input);
    ~token() = default;
};

#endif // TOKEN_H
