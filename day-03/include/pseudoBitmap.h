#ifndef PSEUDO_BITMAP_H
#define PSEUDO_BITMAP_H

#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>

class pseudoBitmap
{
private:
    std::ifstream inputFileHandle;
    std::vector<std::vector<std::string>> stringArt;
    std::unordered_map<std::string, int> imageEssentials;

    // the stringArt should contain token for storing and accessing the chars
    // these token could be used for lookup
public:
    pseudoBitmap(const std::string & filePath);
    ~pseudoBitmap();

    void parseImageFromHandle ();
    void appendLineToImage (const std::string & lineOfText);
    void processLineOfText(std::ifstream & fileHandle, std::string const & line);
    void drawImage() const;

    int getImageEssentials(std::string const& key) const;
    void setImageEssentials(std::string const& key, int value);
    void incrementImageEssentials(std::string const& key);

    std::vector<std::vector<std::string>> const & getStringArtHandle () const;
    std::unordered_map<std::string, int> getSize() const;
    std::string getNeighbours(int row, int column) const;
};


#endif // PSEUDO_BITMAP_H
