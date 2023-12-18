#ifndef PSEUDO_BITMAP_H
#define PSEUDO_BITMAP_H

#include <string>
#include <fstream>
#include <iostream>
#include <list>


class pseudoBitmap
{
private:
    std::ifstream inputFileHandle;
    std::list<std::list<std::string>> stringArt;
    // the stringArt should contain token for storing and accessing the chars
    // these token could be used for lookup
public:
    pseudoBitmap(const std::string & filePath);
    ~pseudoBitmap();

    void appendLineToImage (const std::string & lineOfText);
    void drawImage() const;
};


#endif // PSEUDO_BITMAP_H
