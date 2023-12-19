#ifndef GEARFACTORY_H
#define GEARFACTORY_H

#include "gear.h"
#include "pseudoBitmap.h"
#include <string>
#include <vector>

class gearFactory
{
private:
    const std::vector<std::vector<std::string>> & stringArtHandle;
    pseudoBitmap const & bitmapHandle;
    const std::vector<token> & collectionOfToken;
    int width = 0;
    int heigth = 0;
public:
    gearFactory() = delete;
    gearFactory(gearFactory& fact) = delete;
    gearFactory(const std::vector<token> & tokenHandle, pseudoBitmap const & artHandle, int width, int heigth);
    ~gearFactory() = default;

    std::vector<gear> tokenize() const;
    std::vector<token> getGearNeighbours(int line, int offset) const;
    void removeDuplicates(std::vector<token>& vec) const; 
};




#endif // GEARFACTORY_H