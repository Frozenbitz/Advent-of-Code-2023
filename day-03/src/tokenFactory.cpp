#include "tokenFactory.h"
#include <ranges>

tokenFactory::tokenFactory(pseudoBitmap const & artHandle, int width, int heigth) :
stringArtHandle {artHandle.getStringArtHandle()}, bitmapHandle{artHandle}, width{width}, heigth{heigth}
{

}

std::vector<token> tokenFactory::tokenize() const
{
    std::vector<token> collectionOfToken = {};

    std::string tokenBuffer {}; // store chars to build a token
    std::string neighbours {};
    int line = -1;
    int offset = -1;

    for (auto row : std::ranges::iota_view(0, heigth)) 
    {
        for (auto && col : std::ranges::iota_view(0,width))
        {
            std::string randomChar = stringArtHandle.at(row).at(col);

            // found no digit
            if (randomChar.find_first_of("1234567890") == std::string::npos)
            {
                if (not tokenBuffer.empty()) // buffer empty?
                {
                    generateToken(collectionOfToken, tokenBuffer, line, offset, neighbours);
                }
                
                continue;
            }

            // are we at the start?
            if (line < 0 && offset < 0 )
            {
                line = row;
                offset = col;
            }

            neighbours.append(bitmapHandle.getNeighbours(row, col));
            tokenBuffer.append(randomChar);
        }

        if (not tokenBuffer.empty()) // empty the buffer
        {
            generateToken(collectionOfToken, tokenBuffer, line, offset, neighbours);
        }  
        
    }

    return collectionOfToken;
}

void tokenFactory::generateToken(std::vector<token> & collection, std::string & sToken, int & line, int & offset, std::string & neighbours) const
{
    // generate a new token
    token customToken {sToken, line, offset, neighbours};
    collection.push_back(customToken);
    line = -1;
    offset = -1;
    neighbours.clear();
    sToken.clear();
}