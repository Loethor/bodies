#pragma once

#include "simulation.hpp"

class Integrator {
public:
    virtual ~Integrator() = default;
    virtual void integrate(Simulation& sim) = 0;
};
