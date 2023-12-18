#include "pseudoBitmap.h"
#include <ranges>
#include <string>

pseudoBitmap::pseudoBitmap(const std::string& filePath)
    : inputFileHandle{filePath, std::ifstream::in},
      stringArt(), imageEssentials{{"width", 0}, {"heigth", 0}}
{
    if (not inputFileHandle.is_open())
        throw std::invalid_argument("wrong file name/path, could not open!");

    parseImageFromHandle();

    if (inputFileHandle.bad())
    {
        std::cout << "failed to read stream, try again!" << std::endl;
        throw std::ios_base::failure("wrong file name/path, could not open!");
    }
}

void pseudoBitmap::parseImageFromHandle()
{
    std::string line;
    while (std::getline(inputFileHandle, line))
    {
        processLineOfText(inputFileHandle, line);

        if (inputFileHandle.eof())
            break; // stop
    }
}

void pseudoBitmap::processLineOfText(std::ifstream& fileHandle,
                                     std::string const& line)
{
    // Process each line of the file and collect all games
    auto oldLine = line.length();

    if (getImageEssentials("width") == 0)
    {
        setImageEssentials("width", oldLine);
    }

    appendLineToImage(line);
    incrementImageEssentials("heigth");

    if (getImageEssentials("width") != oldLine)
        throw std::invalid_argument("line width does not match up");
}

pseudoBitmap::~pseudoBitmap() { inputFileHandle.close(); }

void pseudoBitmap::appendLineToImage(const std::string& lineToAppend)
{
    // emplace a new line
    stringArt.push_back(std::vector<std::string>{});

    auto& currentLine = stringArt.back();
    for (auto& character : lineToAppend)
    {
        currentLine.push_back({character});
    }
}

void pseudoBitmap::drawImage() const
{
    for (auto& line : stringArt)
    {
        for (auto& artChar : line)
        {
            std::cout << artChar;
        }
        std::cout << std::endl;
    }
}

int pseudoBitmap::getImageEssentials(std::string const& key) const
{
    auto iter = imageEssentials.find(key);
    if (iter != imageEssentials.end())
    {
        return iter->second;
    }

    return -1;
}

void pseudoBitmap::setImageEssentials(std::string const& key, int value)
{
    auto iter = imageEssentials.find(key);
    if (iter != imageEssentials.end())
    {
        iter->second = value;
        return;
    }

    throw std::invalid_argument("wrong key supplied");
}

void pseudoBitmap::incrementImageEssentials(std::string const& key)
{
    auto iter = imageEssentials.find(key);
    if (iter != imageEssentials.end())
    {
        iter->second += 1;
        return;
    }

    throw std::invalid_argument("wrong key supplied");
}

std::vector<std::vector<std::string>> const&
pseudoBitmap::getStringArtHandle() const
{
    return stringArt;
}

std::unordered_map<std::string, int> pseudoBitmap::getSize() const
{
    return std::unordered_map<std::string, int>{
        {"width", getImageEssentials("width")},
        {"heigth", getImageEssentials("heigth")}};
}

std::string pseudoBitmap::getNeighbours(int row, int column) const 
{
    std::string neighbours {};

    for (auto tryRow : std::ranges::iota_view(row-1, row+2)) 
    {
        for (auto tryCol : std::ranges::iota_view(column-1, column+2)) 
        {
            try
            {
                std::string lookupSymbols {"0123456789"};
                auto currentSymbol = stringArt.at(tryRow).at(tryCol);
                if (currentSymbol.find_first_of(lookupSymbols) == std::string::npos)
                {
                    neighbours.append(currentSymbol);
                }
            }
            catch(const std::out_of_range& e)
            {
                // ignore
            }
        }
    }

    return neighbours;
}