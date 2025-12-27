#include "euler_integrator.hpp"
#include "simulation.hpp"

void EulerIntegrator::step(Simulation& simulation) {
    std::vector<Vec3> accelerations = simulation.computeAccelerations();
    
    for (size_t i = 0; i < simulation.bodies.size(); ++i) {
        // v_new = v_old + a * dt
        simulation.bodies[i].velocity = simulation.bodies[i].velocity + accelerations[i] * simulation.dt;
        
        // x_new = x_old + v * dt
        simulation.bodies[i].position = simulation.bodies[i].position + simulation.bodies[i].velocity * simulation.dt;
    }
}
