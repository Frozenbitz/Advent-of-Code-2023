#include "AlmanacToBlock.h"

#include <regex>

AlmanacToBlocks::AlmanacToBlocks() : 
    currentState(State::seeds)
    {}



void AlmanacToBlocks::handleLine(std::string line) {

    switch (currentState) {

        case State::seeds:

            if (line.find("seed-to-soil") != std::string::npos) {
                currentState = State::seed_to_soil;
                break;
            };

            handleStateSeeds(line);
            //currentState = State::seed_to_soil; // process the next touple
            break;

        case State::seed_to_soil:
            if (line.find("soil-to-fertilizer") != std::string::npos) {
                currentState = State::soil_to_fertilizer;
                break;
            };

            if (not line.empty()) {
                    Seed2Soil.push_back(line);
            }

            break;

        case State::soil_to_fertilizer:
            if (line.find("fertilizer-to-water") != std::string::npos) {
                currentState = State::fertilizer_to_water;
                break;
            };

            if (not line.empty()) {
                Soil2Fertilizer.push_back(line);
            }
            break;

        case State::fertilizer_to_water:
            if (line.find("water-to-light") != std::string::npos) {
                currentState = State::water_to_light;
                break;
            };

            if (not line.empty()) {
                Fertilizer2Water.push_back(line);
            }
            break;

        case State::water_to_light:
            if (line.find("light-to-temperature") != std::string::npos) {
                currentState = State::light_to_temperature;
                break;
            };

            if (not line.empty()) {
                Water2Light.push_back(line);
            }
            break;

        case State::light_to_temperature:   
            if (line.find("temperature-to-humidity") != std::string::npos) {
                currentState = State::temperature_to_humidity;
                break;
            };

            if (not line.empty()) {
                Light2Temperature.push_back(line);
            }
            break;


        case State::temperature_to_humidity:
            if (line.find("humidity-to-location") != std::string::npos) {
                currentState = State::humidity_to_location;
                break;
            };

            if (not line.empty()) {
                Temperature2Humidity.push_back(line);
            }
            break;

        case State::humidity_to_location:
            
            if (not line.empty()) {
                Humidity2Location.push_back(line);
            }
            break;
            
        default:
            throw std::invalid_argument("wrong state!");
    }
}


void AlmanacToBlocks::handleStateSeeds(std::string line) {
    
    std::string pattern = R"(\s*(\d+)\s*)";
    std::regex token_pattern(pattern, std::regex_constants::ECMAScript);
    auto words_begin = std::sregex_iterator(line.begin(), line.end(), token_pattern);
    auto words_end = std::sregex_iterator(); //The default-constructed std::regex_iterator is the end-of-sequence iterator.

    for (std::sregex_iterator i = words_begin; i != words_end; ++i) { // invrement calls r_search
        std::smatch match = *i;
        seeds.push_back(stol(match.str()));
    }
}
