#include "Constants.hpp"

Circle::Circle(float radius, const sf::Color& color, const sf::Vector2f& initialPosition) : circle(radius)
{
	position = initialPosition - sf::Vector2f(radius, radius);
	circle.setFillColor(color);
	circle.setPosition(position);
}

Circle::Circle() = default;
Circle::~Circle() = default;

void Circle::init(float radius, const sf::Color& color, const sf::Vector2f& initialPosition)
{
	position = initialPosition - sf::Vector2f(radius, radius);
	circle.setFillColor(color);
	circle.setRadius(radius);
	circle.setPosition(position);
}

void Circle::update()
{
	velocity.y += gravitationalAcceleration;
	position += velocity;

	if (position.y + circle.getRadius() * 2 >= WINDOW_HEIGHT)
	{
		position.y = WINDOW_HEIGHT - circle.getRadius() * 2;
		velocity.y *= -dampingFactor;
	}

	circle.setPosition(position);
}

const sf::CircleShape& Circle::getObj() const
{
	return circle;
}