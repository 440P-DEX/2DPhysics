/*
This is the header for constants, you can change value here.
Also it is recommended to change value here.
*/

#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

// Radius of the circles.
constexpr float RADIUS = 50.0F;

// The frame rate limit.
constexpr unsigned FPS = 60;

// The number of the Circle objects to generate.
constexpr unsigned OBJECTS = 5U;

// Width of the window.
constexpr unsigned WINDOW_WIDTH = 800U;

// Height of the window.
constexpr unsigned WINDOW_HEIGHT = 600U;

// Average gravitational acceleration.
constexpr float gravitationalAcceleration = 0.98f;

// Retention for reducing bouncing.
constexpr float retention = 0.8f;

// Friction for reducing horizontally moving.
constexpr float friction = 0.99f;

// Perfectly elastic collision.
constexpr float restitution = 1.0F;

#endif // !CONSTANTS_HPP