#include "gearFactory.h"
#include <ranges>

gearFactory::gearFactory(const std::vector<token> & tokenHandle, pseudoBitmap const & artHandle, int width, int heigth) :
stringArtHandle {artHandle.getStringArtHandle()}, bitmapHandle{artHandle}, collectionOfToken{tokenHandle}, width{width}, heigth{heigth}
{

}

std::vector<gear> gearFactory::tokenize() const
{
    std::vector<gear> collectionOfGear = {};
    std::vector<token> neighbours {};

    for (auto row : std::ranges::iota_view(0, heigth)) 
    {
        for (auto && col : std::ranges::iota_view(0,width))
        {
            std::string randomChar = stringArtHandle.at(row).at(col);

            if (randomChar.find_first_of("*") != std::string::npos)
            {
                neighbours = getGearNeighbours(row, col);

                if (neighbours.empty())
                    continue;

                gear customGear {row, col, neighbours};
                collectionOfGear.push_back(customGear);
                neighbours.clear();
            }
        }
    }

    return collectionOfGear;
}

std::vector<token> gearFactory::getGearNeighbours(int line, int offset) const
{
    std::vector<token> nearToken {};

    for (auto && aToken : collectionOfToken)
    {
        for (auto tryLine : std::ranges::iota_view(line-1, line+2)) 
        {
            for (auto tryOffset : std::ranges::iota_view(offset-1, offset+2)) 
            {
                if(aToken.contains(tryLine, tryOffset))
                {
                    nearToken.push_back(aToken);
                }
            }
        }
    }

    removeDuplicates(nearToken);

    if (nearToken.size() == 2)
    {
        return nearToken;
    }
    
    return {};
}

void gearFactory::removeDuplicates(std::vector<token>& vec) const {
    // Sort the vector
    std::sort(vec.begin(), vec.end());

    // Use std::unique to rearrange the vector elements and remove duplicates
    auto last = std::unique(vec.begin(), vec.end());

    // Erase the unspecified values and shrink the container to fit the new size
    vec.erase(last, vec.end());
}