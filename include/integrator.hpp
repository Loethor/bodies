#pragma once

#include "simulation.hpp"

class Integrator {
public:
    virtual ~Integrator() = default;
    virtual void step(Simulation& simulation) = 0;
};
