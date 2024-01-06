#include "raceFactory.h"


raceFactory::raceFactory(const std::string& filename) : filename(filename) {

    std::vector<std::string> lines = readLinesFromFile(filename);

    std::vector<long> timeSeries = splitString(lines[0]);
    std::vector<long> distanceSeries = splitString(lines[1]);
    long size = timeSeries.size();
    
    if (timeSeries.size() != distanceSeries.size()) {
        throw std::invalid_argument("time and distance series must be of equal length!");
    }

    // without kerning
    // for (auto &&i : std::ranges::iota_view(0, size))
    // {
    //     races.push_back(Race(timeSeries[i], distanceSeries[i]));
    // }
    
    // with kerning
    std::stringstream ssTime;
    for (auto && timeVal : timeSeries)
    {
        ssTime << timeVal;
    }
    
    std::stringstream ssDistance;
    for (auto && distanceVal : distanceSeries)
    {
        ssDistance << distanceVal;
    }
    
    long newTime = stol(ssTime.str());
    long newDistance = stol(ssDistance.str());

    races.push_back(Race(newTime, newDistance));

}

std::vector<Race> raceFactory::getRaces() {
    return races;
}

std::vector<std::string> raceFactory::readLinesFromFile (const std::string& filename)
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

std::vector<long> raceFactory::splitString(const std::string& line) {
    std::string pattern = R"(\s*(\d+)\s*)";
    std::regex token_pattern(pattern, std::regex_constants::ECMAScript);
    auto words_begin = std::sregex_iterator(line.begin(), line.end(), token_pattern);
    auto words_end = std::sregex_iterator(); //The default-constructed std::regex_iterator is the end-of-sequence iterator.

    long rangeStart = 0; 
    std::vector<long> data;
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) { // increment calls r_search
        std::smatch match = *i;
        data.push_back(stol(match.str()));
    }

    return data;
}