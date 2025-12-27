#include <iostream>
#include "body.hpp"
#include "simulation.hpp"
#include "euler_integrator.hpp"

int main() {
    // Create a simulation
    Simulation sim;
    sim.dt = 0.01;

    // Add two bodies
    Body body1({0.0, 0.0, 0.0}, {0.01, 0.0, 0.0}, 1.0e24);
    Body body2({1.0, 0.0, 0.0}, {0.0, 0.01, 0.0}, 1.0e24);
    
    sim.bodies.push_back(body1);
    sim.bodies.push_back(body2);

    // Create integrator and integrate
    EulerIntegrator integrator;
    
    std::cout << "Initial positions:\n";
    std::cout << "  Body 1: (" << sim.bodies[0].position[0] << ", " << sim.bodies[0].position[1] << ", " << sim.bodies[0].position[2] << ")\n";
    std::cout << "  Body 2: (" << sim.bodies[1].position[0] << ", " << sim.bodies[1].position[1] << ", " << sim.bodies[1].position[2] << ")\n";
    
    integrator.integrate(sim);
    
    std::cout << "After integration:\n";
    std::cout << "  Body 1: (" << sim.bodies[0].position[0] << ", " << sim.bodies[0].position[1] << ", " << sim.bodies[0].position[2] << ")\n";
    std::cout << "  Body 2: (" << sim.bodies[1].position[0] << ", " << sim.bodies[1].position[1] << ", " << sim.bodies[1].position[2] << ")\n";
    
    return 0;
}