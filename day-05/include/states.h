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

#endif // STATES_H

