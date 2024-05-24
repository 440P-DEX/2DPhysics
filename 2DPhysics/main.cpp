#include "Constants.hpp"

/*
	Generates a random float value within the specified range [min, max].

	@param min The minimum value of the range (inclusive).
	@param max The maximum value of the range (inclusive).
	@return A random float value within the specified range.
*/
static float randomFloat(float min = 0.f, float max = 0.f)
{
	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_real_distribution<float> dis(min, max);

	return dis(gen);
}

/*
	Updates the position of each circle in the provided vector using basic physics calculations.

	@param circles The list of circles to be updated.
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
		circles.push_back(std::make_unique<Circle>(RADIUS, sf::Color::Green, sf::Vector2f(randomFloat(RADIUS, WINDOW_WIDTH - RADIUS), randomFloat(RADIUS, WINDOW_HEIGHT - RADIUS))));
	}

	while (window->isOpen())
	{
		window->run(circles);
		update(circles);
	}

	return 0;
}