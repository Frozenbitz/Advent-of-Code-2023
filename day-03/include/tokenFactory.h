#ifndef TOKENFACTORY_H
#define TOKENFACTORY_H

#include "token.h"
#include "pseudoBitmap.h"
#include <string>
#include <vector>

class tokenFactory
{
private:
    const std::vector<std::vector<std::string>> & stringArtHandle;
    pseudoBitmap const & bitmapHandle;
    int width = 0;
    int heigth = 0;
public:
    tokenFactory() = delete;
    tokenFactory(pseudoBitmap const & artHandle, int width, int heigth);
    ~tokenFactory() = default;

    std::vector<token> tokenize() const;
    void generateToken(std::vector<token> & collection, std::string & token, int & line, int & offset, std::string & neighbours) const;
};




#endif // TOKENFACTORY_H