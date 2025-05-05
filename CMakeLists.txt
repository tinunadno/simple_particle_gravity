cmake_minimum_required(VERSION 3.29)
project(particle_gravity_simulation)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML REQUIRED graphics)
include_directories(
        ${PROJECT_SOURCE_DIR}
        ${SFML}
)

add_executable(particle_gravity_simulation main.cpp
        base/vec2/vec2.h
        base/unit_system/unit_system.h
        base/unit_system/unit_system.h
        base/particle.h
        core/scene/scene.h
        core/scene/scene.cpp
        core/screen/screen.h
        base/unit_system/unit_system.cpp
        core/screen/screen.cpp
        base/vec2/vec2.cpp)

target_link_libraries( particle_gravity_simulation PRIVATE sfml-graphics )