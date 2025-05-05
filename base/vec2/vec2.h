#ifndef PARTICLE_GRAVITY_SIMULATION_VEC2_H
#define PARTICLE_GRAVITY_SIMULATION_VEC2_H

#include <cmath>

class vec2 {
public:
    vec2(double x, double y) : x(x), y(y) {}

    vec2() : x(0), y(0) {}

    vec2 &operator+=(const vec2 &added) {
        x += added.x;
        y += added.y;
        return *this;
    }

    vec2 &operator-=(const vec2 &subbed) {
        x -= subbed.x;
        y -= subbed.y;
        return *this;
    }

    vec2 & operator*=(double val){
        x*= val;
        y*= val;
        return *this;
    }

    vec2 & operator*=(const vec2& other){
        x*= other.x;
        y*= other.y;
        return *this;
    }

    vec2 & operator*=(const std::pair<int, int> other){
        x*= other.first;
        y*= other.second;
        return *this;
    }

    vec2 & operator/=(double val){
        x/= val;
        y/= val;
        return *this;
    }

    double operator()() const {
        return sqrt(x * x + y * y);
    }

    void operator!() {
        double l = sqrt(x * x + y * y);
        x /= l;
        y /= l;
    }

    friend vec2 operator*(const vec2 &a, double val);

    friend vec2 operator/(const vec2 &a, double val);

    friend double operator|(const vec2 &a, const vec2 &b);

    ~vec2() = default;

    double x;
    double y;
};
#endif //PARTICLE_GRAVITY_SIMULATION_VEC2_H
