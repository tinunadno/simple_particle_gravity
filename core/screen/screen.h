#ifndef PARTICLE_GRAVITY_SIMULATION_SCREEN_H
#define PARTICLE_GRAVITY_SIMULATION_SCREEN_H

#include <memory>
#include <SFML/Graphics.hpp>
#include "../../base/particle.h"
#include "base/vec2/vec2.h"
#include "base/unit_system/unit_system.h"
#include "../scene/scene.h"

class screen {
public:
    screen(const std::pair<vec2, vec2>& screen_scale, std::vector<particle>& particles,
           std::pair<int, int> window_size, float planet_scale_coefficient) :
            _scene(std::make_unique<scene>(particles)),
            _screen_scale(screen_scale),
            _planet_scale_coefficient(planet_scale_coefficient),
            _window(sf::VideoMode(window_size.first, window_size.second), "Gravity engine")
    {
        _window.setFramerateLimit(60);
        _particles_representation.reserve(_scene->_particles.size());

        for (const auto& p : _scene->_particles) {

            sf::CircleShape circle((float) convert_value_to_screen_space_coordinates(
                    p.size, _screen_scale, window_size) * _planet_scale_coefficient);

            auto pos = convert_vector_to_screen_space_coefficient(
                    p.pos, _screen_scale, window_size);

            circle.setPosition((float) pos.x, (float) pos.y);
            circle.setFillColor(sf::Color(
                    (p.color >> 16) & 0xFF,
                    (p.color >> 8) & 0xFF,
                    p.color & 0xFF
            ));

            circle.setOrigin(circle.getRadius(), circle.getRadius());
            _particles_representation.push_back(std::move(circle));
            _window.draw(circle);
        }
    }

    void init_render(double dt);

private:

    void update_circles();

    std::pair<vec2, vec2> _screen_scale;
    const float _planet_scale_coefficient;
    sf::RenderWindow _window;
    std::vector<sf::CircleShape> _particles_representation;
    std::unique_ptr<scene> _scene;
};

#endif //PARTICLE_GRAVITY_SIMULATION_SCREEN_H
