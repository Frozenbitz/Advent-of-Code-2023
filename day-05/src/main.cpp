#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "AlmanacToBlock.h"
#include "RangeMapper.h"

int main()
{
    std::ifstream almanac{{"./examples/example.txt"}, std::ifstream::in};

    if (not almanac.is_open())
        throw std::invalid_argument("wrong file name/path, could not open!");

    std::string line;
    std::vector<std::string> almanac_lines; // build a vector of lines
    while (std::getline(almanac, line))
    {
        // Process each line of the file and create the mapping
        almanac_lines.push_back(line);

        if (almanac.eof())
            break; // stop
    }

    if (almanac.bad())
    {
        std::cout << "failed to read stream, try again!" << std::endl;
        throw std::ios_base::failure("error occured during file reading!");
    }

    almanac.close(); // done reading the file

    // use a vector of lines to build the foundaiton of the different blocks
    AlmanacToBlocks collectionOfMappers;
    for (auto &&line : almanac_lines)
    {
        collectionOfMappers.handleLine(line);
    }

    std::unordered_map<std::string, RangeMapper> almanac_map;
    almanac_map["seed-to-soil"] = RangeMapper(collectionOfMappers.Seed2Soil);
    almanac_map["soil-to-fertilizer"] = RangeMapper(collectionOfMappers.Soil2Fertilizer);
    almanac_map["fertilizer-to-water"] = RangeMapper(collectionOfMappers.Fertilizer2Water);
    almanac_map["water-to-light"] = RangeMapper(collectionOfMappers.Water2Light);
    almanac_map["light-to-temperature"] = RangeMapper(collectionOfMappers.Light2Temperature);
    almanac_map["temperature-to-humidity"] = RangeMapper(collectionOfMappers.Temperature2Humidity);
    almanac_map["humidity-to-location"] = RangeMapper(collectionOfMappers.Humidity2Location);

    std::vector<int> locationNumber;
    for (auto &&seed : collectionOfMappers.seeds)
    {
        int map2soil = almanac_map["seed-to-soil"].convert(seed);
        int map2fertilizer = almanac_map["soil-to-fertilizer"].convert(map2soil);
        int map2water = almanac_map["fertilizer-to-water"].convert(map2fertilizer);
        int map2light = almanac_map["water-to-light"].convert(map2water);
        int map2temperature = almanac_map["light-to-temperature"].convert(map2light);
        int map2humidity = almanac_map["temperature-to-humidity"].convert(map2temperature);
        int map2location = almanac_map["humidity-to-location"].convert(map2humidity);
        std::cout << "seed: " << seed << " -> location: " << map2location << std::endl;
        locationNumber.push_back(map2location);
    }

    auto minIt = std::min_element(locationNumber.begin(), locationNumber.end());
    if (minIt != locationNumber.end()) {
        std::cout << "The smallest element is " << *minIt << '\n';
    }

    return 0;
}

