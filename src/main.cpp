#include <iostream>
#include "body.hpp"
#include "simulation.hpp"
#include "euler_integrator.hpp"
#include "config_loader.hpp"

int main() {
    // Load bodies from config file
    std::vector<Body> bodies = ConfigLoader::loadBodies("data/earth_moon.txt");
    
    // Create a simulation
    Simulation simulation;
    simulation.dt = 3600.0; // 1 hour time step
    simulation.bodies = bodies;

    // Create integrator
    EulerIntegrator integrator;
    
    std::cout << "Initial state:\n";
    for (const auto& body : simulation.bodies) {
        body.printState();
    }
    
    // Integrator advances the simulation one step
    integrator.step(simulation);
    
    std::cout << "\nAfter integration:\n";;
    for (const auto& body : simulation.bodies) {
        body.printState();
    }
    
    return 0;
}