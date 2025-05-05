#include "screen.h"

void screen::init_render(double dt) {
    while (_window.isOpen()){

        sf::Event event;
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                _window.close();
        }

        _scene->iterate(dt);
        _window.clear();
        update_circles();
        _window.display();

    }
}

void screen::update_circles() {
    auto tmp = _window.getSize();
    for(int i = 0; i < _particles_representation.size(); i++){
        auto& circle = _particles_representation[i];
        auto& p = _scene->_particles[i];
        auto pos = convert_vector_to_screen_space_coefficient(
                p.pos, _screen_scale, {tmp.x, tmp.y});
        circle.setPosition((float)pos.x, (float)pos.y);
        _window.draw(circle);
    }
}