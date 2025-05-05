#include <cmath>
#include "core/screen/screen.h"

#define color(r, g, b) (((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF))

int main() {
    using namespace std;

    vector<particle> particles;

    vec2 pos = vec2();
    vec2 speed = vec2();

    particles.emplace_back(
            pos,
            speed,
            3,
            100,
            color(220, 200, 255)
            );

    for(int i = 0; i < 1000; i++){
        double rad= i / 50.0 + 50;
        int clr_temp= 255-(int)(rad*2.5);
        int direction=1;
        pos = vec2(0, rad*(direction));
        speed = vec2(direction*sqrt(10),0) / 5;
        particles.emplace_back(
                pos,
                speed,
                .4,
                0.00001,
                color(255, clr_temp, clr_temp)
                );
    }


//    screen(const std::pair<vec2, vec2> &screen_scale, scene &scene_, std::pair<int, int> window_size, double planet_scale_coefficient) :

    pair<vec2, vec2> screen_scale = {
            vec2(-100, -100),
            vec2(100, 100)
    };

    auto scrn = screen(screen_scale, particles, {800, 400}, 1);

    scrn.init_render(1);

    return 0;
}
