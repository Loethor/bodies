#pragma once

#include <vector>
#include "body.hpp"

class Simulation {
public:
    std::vector<Body> bodies;
    double dt;

    void step();
};
