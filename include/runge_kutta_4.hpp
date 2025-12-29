#pragma once

#include "integrator.hpp"

class RungeKutta4Integrator : public Integrator {
public:
    void step(Simulation& simulation) override;
};
