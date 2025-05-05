#ifndef PARTICLE_GRAVITY_SIMULATION_SCENE_H
#define PARTICLE_GRAVITY_SIMULATION_SCENE_H

#include <vector>
#include "../../base/particle.h"

class scene{
public:
    explicit scene(std::vector<particle>& particles){
        _particles = std::move(particles);
    }

    void iterate(double dt);

    void add_particle(const particle& p){
        _particles.push_back(p);
    }

    std::vector<particle> _particles;
};

#endif //PARTICLE_GRAVITY_SIMULATION_SCENE_H
