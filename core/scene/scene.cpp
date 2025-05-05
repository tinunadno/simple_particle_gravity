#include "scene.h"

double weight_epsilon = 1;

void scene::iterate(double dt) {
    std::vector<vec2> accelerations(_particles.size());
    // updating speed
    for(int i = 0; i < _particles.size(); i++){
        auto& current_particle = _particles[i];
        for(int j = 0; j < _particles.size(); j++){
            if(i == j){
                continue;
            }


            const auto& influencer = _particles[j];

//            if(influencer.mass < weight_epsilon) {
//                continue;
//            }

            double distance = current_particle.pos | influencer.pos;
            double some_smart_formula_coefficient = influencer.mass / (distance * distance);

            vec2 gravity_vector = influencer.pos;
            gravity_vector-=current_particle.pos;
            !gravity_vector;                                                                        // normalizing
            gravity_vector*=some_smart_formula_coefficient;

            accelerations[i] += gravity_vector;
        }
    }

    // updating positions
    for(int i = 0; i < _particles.size(); i++){
        accelerations[i] *= dt;
        _particles[i].speed += accelerations[i];
        _particles[i].pos += _particles[i].speed * dt;
    }
}