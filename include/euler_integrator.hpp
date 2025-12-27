#pragma once

#include "integrator.hpp"

class EulerIntegrator : public Integrator {
public:
    void step(Simulation& simulation) override;
};
