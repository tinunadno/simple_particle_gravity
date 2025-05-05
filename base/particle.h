#ifndef PARTICLE_GRAVITY_SIMULATION_PARTICLE_H
#define PARTICLE_GRAVITY_SIMULATION_PARTICLE_H

#include "base/vec2/vec2.h"

class particle{
public:
    particle(const vec2& pos, const vec2& speed, double size, double mass, int color):
                        pos(pos), speed(speed), size(size), mass(mass), color(color){}

    vec2 pos, speed;
    double size;
    double mass;
    int color;


};

#endif //PARTICLE_GRAVITY_SIMULATION_PARTICLE_H
