#include "Window.hpp"
#include "Constants.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <vector>
#include <random>

/*
	Generates a random float value within the specified range [min, max].

	@param min: The minimum value of the range (inclusive).
	@param max: The maximum value of the range (inclusive).
	@return A random float value within the specified range.
*/
static float randomFloat(float min, float max)
{
	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_real_distribution<float> dis(min, max);

	return dis(gen);
}

/*
	Generates a random int value within the specified range [min, max].

	@param min: The minimum value of the range (inclusive).
	@param max: The maximum value of the range (inclusive).
	@return A random int value within the specified range.
*/
static unsigned int randomInt(unsigned int min, unsigned int max)
{
	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<int> dis(min, max);

	return dis(gen);
}

/*
	Generates a random RGBA color with full Opacity.

	@return A random full Opacity RGBA color.
*/
static sf::Color randomColor()
{
	auto r = static_cast<sf::Uint8>(randomInt(0, 255));
	auto g = static_cast<sf::Uint8>(randomInt(0, 255));
	auto b = static_cast<sf::Uint8>(randomInt(0, 255));
	return sf::Color(r, g, b);
}

/*
	Updates the position of each circle in the provided vector using basic physics calculations.

	@param circles: The list of circles to be updated.
*/
static void update(const std::vector<std::unique_ptr<Circle>>& circles)
{
	for (const auto& circle : circles)
	{
		circle->update();
	}
}

int main()
{
	const auto window = std::make_unique<Window>(WINDOW_WIDTH, WINDOW_HEIGHT, "2D Physics");

	std::vector<std::unique_ptr<Circle>> circles;

	for (int i = 0; i < 5; ++i)
	{
		circles.push_back(std::make_unique<Circle>(RADIUS, randomColor(), sf::Vector2f(randomFloat(RADIUS, WINDOW_WIDTH - RADIUS), randomFloat(RADIUS, WINDOW_HEIGHT - RADIUS))));
	}

	while (window->isOpen())
	{
		window->run(circles);
		update(circles);
	}

	return 0;
}