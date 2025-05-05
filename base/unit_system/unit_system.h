#ifndef PARTICLE_GRAVITY_SIMULATION_UNIT_SYSTEM_H
#define PARTICLE_GRAVITY_SIMULATION_UNIT_SYSTEM_H

#include <utility>
#include "base/vec2/vec2.h"

double convert_value_to_screen_space_coordinates(double value, const std::pair<vec2, vec2>& scales, std::pair<int, int> screen_size);

vec2 convert_vector_to_screen_space_coefficient(
        const vec2& value, const std::pair<vec2, vec2>& scales, std::pair<int, int> screen_size);

#endif //PARTICLE_GRAVITY_SIMULATION_UNIT_SYSTEM_H
