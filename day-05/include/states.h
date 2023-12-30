#ifndef STATES_H
#define STATES_H

enum class State {
    seeds, // initial state
    seed_to_soil,
    soil_to_fertilizer,
    fertilizer_to_water,
    water_to_light,
    light_to_temperature,
    temperature_to_humidity,
    humidity_to_location
};

// enum class Event {
//     none, 
//     startSeed,
//     startSeed2Soil,
//     startSoil2Fertilizer,
//     startFertilizer2Water,
//     startWater2Light,
//     startLight2Temperature,
//     startTemperature2Humidity,
//     startHumidity2Location
// };

#endif // STATES_H

