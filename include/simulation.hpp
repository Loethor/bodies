#pragma once

#include <vector>
#include "body.hpp"
#include "vector_math.hpp"

class Simulation {
public:
    std::vector<Body> bodies;
    double dt;

    std::vector<Vec3> computeAccelerations() const;
};
