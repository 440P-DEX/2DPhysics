/*
	This is the header for constants, you can change value here.
	You can also change it directly in main.cpp.
*/

#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

// Radius of the circles.
constexpr float RADIUS = 50.0F;

// The frame rate limit.
constexpr unsigned FPS = 144U;

// The number of the Circle objects to generate.
constexpr unsigned OBJECTS = 5U;

// Width of the window.
constexpr unsigned WINDOW_WIDTH = 800U;

// Height of the window.
constexpr unsigned WINDOW_HEIGHT = 600U;

// Average gravitational acceleration.
constexpr float gravitationalAcceleration = 58.8F;

// Retention for reducing bouncing.
constexpr float retention = 0.8F;

// Friction for reducing horizontally moving.
constexpr float friction = 0.99F;

// 95% of the collision velocity.
constexpr float restitution = 0.95F;

// Max objects in each node.
constexpr int MAX_OBJECTS = 4;

// Max levels of each node.
constexpr int MAX_LEVELS = 5;

#endif // !CONSTANTS_HPP