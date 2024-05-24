#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include "Window.hpp"
#include <memory>
#include <vector>
#include <random>

// Radius of the circles.
constexpr float RADIUS = 50.f;

// Width of the window.
constexpr unsigned WINDOW_WIDTH = 800U;

// Height of the window.
constexpr unsigned WINDOW_HEIGHT = 600U;

// Average gravitational acceleration.
constexpr float gravitationalAcceleration = 0.98f;

// Damping factor for reducing bouncing.
constexpr float dampingFactor = 0.8f;

#endif // !CONSTANTS_HPP