#include "Utility.hpp"

float randomFloat(float min, float max)
{
	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_real_distribution<float> dis(min, max);

	return dis(gen);
}

unsigned int randomInt(unsigned int min, unsigned int max)
{
	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<int> dis(min, max);

	return dis(gen);
}

sf::Color randomColor()
{
	auto r = static_cast<sf::Uint8>(randomInt(0, 255));
	auto g = static_cast<sf::Uint8>(randomInt(0, 255));
	auto b = static_cast<sf::Uint8>(randomInt(0, 255));
	return sf::Color(r, g, b);
}
