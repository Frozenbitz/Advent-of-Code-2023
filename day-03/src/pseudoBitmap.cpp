#include  "pseudoBitmap.h"

pseudoBitmap::pseudoBitmap(const std::string & filePath) : 
inputFileHandle {filePath, std::ifstream::in}, 
stringArt() 
{
    if (not inputFileHandle.is_open())
        throw std::invalid_argument("wrong file name/path, could not open!");

    std::string line;
    while (std::getline(inputFileHandle, line))
    {
        // Process each line of the file and collect all games
        appendLineToImage(line);

        if (inputFileHandle.eof())
            break; // stop
    }

    if (inputFileHandle.bad())
    {
        std::cout << "failed to read stream, try again!" << std::endl;
        throw std::ios_base::failure("wrong file name/path, could not open!");
    }
}

pseudoBitmap::~pseudoBitmap()
{
    inputFileHandle.close();
}

void pseudoBitmap::appendLineToImage (const std::string & lineOfText)
{
    // emplace a new line
    stringArt.push_back(std::list<std::string>{});

    auto& currentLine = stringArt.back();
    for (auto & i : lineOfText)
    {
        currentLine.push_back({i});
    }
}

void pseudoBitmap::drawImage() const
{
    for (auto & line : stringArt)
    {
        for (auto & artChar : line)
        {
            std::cout << artChar;
        }
        std::cout << std::endl;
    }
}