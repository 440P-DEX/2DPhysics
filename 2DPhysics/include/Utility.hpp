#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <SFML/Graphics.hpp>

/*
	Generates a random float value within the specified range [min, max].

	@param min: The minimum value of the range (inclusive).
	@param max: The maximum value of the range (inclusive).
	@return A random float value within the specified range.
*/
float randomFloat(float min, float max);

/*
	Generates a random int value within the specified range [min, max].

	@param min: The minimum value of the range (inclusive).
	@param max: The maximum value of the range (inclusive).
	@return A random int value within the specified range.
*/
unsigned int randomInt(unsigned int min, unsigned int max);

/*
	Generates a random RGBA color with full Opacity.

	@return A random full Opacity RGBA color.
*/
sf::Color randomColor();

#endif // !UTILITY_HPP