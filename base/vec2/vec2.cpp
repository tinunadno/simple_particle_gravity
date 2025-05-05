#include "vec2.h"


vec2 operator*(const vec2 &a, double val) {
    return {a.x * val, a.y * val};
}

vec2 operator/(const vec2 &a, double val) {
    return {a.x / val, a.y / val};
}

double operator|(const vec2 &a, const vec2 &b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}
