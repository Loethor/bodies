#include "simulation.hpp"
#include "vector_math.hpp"
#include <cmath>

std::vector<Vec3> Simulation::computeAccelerations() const {
    const double G = 6.67430e-11; // Gravitational constant (m^3 kg^-1 s^-2)
    
    std::vector<Vec3> accelerations(bodies.size(), {0.0, 0.0, 0.0});
    
    for (size_t i = 0; i < bodies.size(); ++i) {
        for (size_t j = 0; j < bodies.size(); ++j) {
            if (i == j) continue;
            
            // Vector from body i to body j
            Vec3 r = bodies[j].position - bodies[i].position;
            double distance = norm(r);
            
            // Avoid division by zero
            if (distance < 1e-10) continue;
            
            // Gravitational force magnitude: F = G * m1 * m2 / r^2
            // Acceleration: a = F / m1 = G * m2 / r^2
            double acc_magnitude = G * bodies[j].mass / (distance * distance);
            
            // Direction of acceleration (unit vector)
            Vec3 direction = normalize(r);
            
            // Add acceleration contribution from body j
            accelerations[i] = accelerations[i] + direction * acc_magnitude;
        }
    }
    
    return accelerations;
}
