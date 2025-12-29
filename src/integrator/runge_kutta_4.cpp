#include "runge_kutta_4.hpp"
#include "simulation.hpp"
#include <vector>

void RungeKutta4Integrator::step(Simulation& simulation) {
    size_t n = simulation.bodies.size();
    std::vector<Vec3> k1_v(n), k2_v(n), k3_v(n), k4_v(n);
    std::vector<Vec3> k1_x(n), k2_x(n), k3_x(n), k4_x(n);
    std::vector<Vec3> orig_positions(n), orig_velocities(n);
    double dt = simulation.dt;

    // Store original positions and velocities
    for (size_t i = 0; i < n; ++i) {
        orig_positions[i] = simulation.bodies[i].position;
        orig_velocities[i] = simulation.bodies[i].velocity;
    }

    // k1
    std::vector<Vec3> a1 = simulation.computeAccelerations();
    for (size_t i = 0; i < n; ++i) {
        k1_v[i] = a1[i];
        k1_x[i] = orig_velocities[i];
    }

    // k2
    for (size_t i = 0; i < n; ++i) {
        simulation.bodies[i].position = orig_positions[i] + k1_x[i] * (dt / 2.0);
        simulation.bodies[i].velocity = orig_velocities[i] + k1_v[i] * (dt / 2.0);
    }
    std::vector<Vec3> a2 = simulation.computeAccelerations();
    for (size_t i = 0; i < n; ++i) {
        k2_v[i] = a2[i];
        k2_x[i] = simulation.bodies[i].velocity;
    }

    // k3
    for (size_t i = 0; i < n; ++i) {
        simulation.bodies[i].position = orig_positions[i] + k2_x[i] * (dt / 2.0);
        simulation.bodies[i].velocity = orig_velocities[i] + k2_v[i] * (dt / 2.0);
    }
    std::vector<Vec3> a3 = simulation.computeAccelerations();
    for (size_t i = 0; i < n; ++i) {
        k3_v[i] = a3[i];
        k3_x[i] = simulation.bodies[i].velocity;
    }

    // k4
    for (size_t i = 0; i < n; ++i) {
        simulation.bodies[i].position = orig_positions[i] + k3_x[i] * dt;
        simulation.bodies[i].velocity = orig_velocities[i] + k3_v[i] * dt;
    }
    std::vector<Vec3> a4 = simulation.computeAccelerations();
    for (size_t i = 0; i < n; ++i) {
        k4_v[i] = a4[i];
        k4_x[i] = simulation.bodies[i].velocity;
    }

    // Update positions and velocities
    for (size_t i = 0; i < n; ++i) {
        simulation.bodies[i].position = orig_positions[i] +
            (k1_x[i] + 2.0 * k2_x[i] + 2.0 * k3_x[i] + k4_x[i]) * (dt / 6.0);
        simulation.bodies[i].velocity = orig_velocities[i] +
            (k1_v[i] + 2.0 * k2_v[i] + 2.0 * k3_v[i] + k4_v[i]) * (dt / 6.0);
    }
}