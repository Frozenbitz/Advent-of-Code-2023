#include "camelCardsFactory.h"

camelCardsFactory::camelCardsFactory(std::string input) : 
    filename(input)
{
    std::vector<std::string> lines = readLinesFromFile(filename);

    for (auto &&line : lines)
    {
        std::vector<std::string> data = splitString(line);
        cards.push_back(camelCards(data[0], stoi(data[1])));
    }
}


std::vector<std::string> camelCardsFactory::readLinesFromFile (const std::string& filename)
{
    std::ifstream inputStream{filename, std::ifstream::in};

    if (not inputStream.is_open())
        throw std::invalid_argument("wrong file name/path, could not open!");

    std::string line;
    std::vector<std::string> inputStream_lines; // build a vector of lines
    while (std::getline(inputStream, line))
    {
        // Process each line of the file and create the mapping
        inputStream_lines.push_back(line);

        if (inputStream.eof())
            break; // stop
    }

    if (inputStream.bad())
    { 
        std::cout << "failed to read stream, try again!" << std::endl;
        throw std::ios_base::failure("error occurred during file reading!");
    }

    inputStream.close(); // done reading the file

    return inputStream_lines;
}

std::vector<std::string> camelCardsFactory::splitString(const std::string& line) {
    std::string pattern = R"((.....){1}\s*(\d+)*)";
    std::regex token_pattern(pattern, std::regex_constants::ECMAScript);
    auto words_begin = std::sregex_iterator(line.begin(), line.end(), token_pattern);
    auto words_end = std::sregex_iterator(); //The default-constructed std::regex_iterator is the end-of-sequence iterator.

    long rangeStart = 0; 
    std::vector<std::string> data;
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) { // increment calls r_search
        std::smatch match = *i;
        data.push_back(match[1]);
        data.push_back(match[2]);
    }

    return data;
}


std::vector<camelCards> camelCardsFactory::getCards() {
    return cards;
}