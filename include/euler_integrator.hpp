#pragma once

#include "integrator.hpp"

class EulerIntegrator : public Integrator {
public:
    void integrate(Simulation& sim) override;
};
