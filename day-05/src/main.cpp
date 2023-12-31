#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <ranges>
#include <limits>

#include "AlmanacToBlock.h"
#include "RangeMapper.h"

int main()
{
    std::ifstream almanac{{"./examples/riddle.txt"}, std::ifstream::in};

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

    long minRun = std::numeric_limits<int>::max();
    for (auto &&range : collectionOfMappers.seeds)
    {
        std::cout << "running : " << range.rangeStart << " seed range" << std::endl; 

        for (auto && seed: std::ranges::iota_view(range.rangeStart, range.rangeEnd))
        {
            long map2soil = almanac_map["seed-to-soil"].convert(seed);
            long map2fertilizer = almanac_map["soil-to-fertilizer"].convert(map2soil);
            long map2water = almanac_map["fertilizer-to-water"].convert(map2fertilizer);
            long map2light = almanac_map["water-to-light"].convert(map2water);
            long map2temperature = almanac_map["light-to-temperature"].convert(map2light);
            long map2humidity = almanac_map["temperature-to-humidity"].convert(map2temperature);
            long map2location = almanac_map["humidity-to-location"].convert(map2humidity);
            minRun = std::min(minRun, map2location);
        }
    }

    std::cout << "The smallest element is " << minRun << '\n';

    return 0;
}

