#include "unit_system.h"

double convert_value_to_screen_space_coordinates(double value, const std::pair<vec2, vec2> &scales,
                                                 std::pair<int, int> screen_size) {
    double scale_coefficient = scales.second.y - scales.first.y;
    value /= scale_coefficient;
    value *= screen_size.second;
    return value;
}

vec2 convert_vector_to_screen_space_coefficient(const vec2& value, const std::pair<vec2, vec2>& scales,
                                                std::pair<int, int> screen_size) {
    double ratio = (double)screen_size.first / (double)screen_size.second;
    vec2 normalized;
    normalized.x = (value.x / ratio- scales.first.x) / (scales.second.x- scales.first.x);
    normalized.y = (value.y - scales.first.y) / (scales.second.y - scales.first.y);
    return {normalized.x * screen_size.first, normalized.y * screen_size.second};
}