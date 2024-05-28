#include "Circle.hpp"
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
	if (!isDragged)
	{
		velocity.x *= friction;
		velocity.y += gravitationalAcceleration;
		position += velocity;

		if (position.y + circle.getRadius() * 2 >= WINDOW_HEIGHT)
		{
			position.y = WINDOW_HEIGHT - circle.getRadius() * 2;
			velocity.y *= -retention;
		}

		if (position.x + circle.getRadius() * 2 >= WINDOW_WIDTH)
		{
			position.x = WINDOW_WIDTH - circle.getRadius() * 2;
			velocity.x = -velocity.x;
		}
		else if (position.x <= 0)
		{
			position.x = 0;
			velocity.x = -velocity.x;
		}

		circle.setPosition(position);
	}
	else
	{
		velocity = sf::Vector2f();
	}
}

const sf::CircleShape& Circle::getObj() const
{
	return circle;
}

void Circle::onMousePressed(const sf::Vector2f& mousePosition)
{
	if (circle.getGlobalBounds().contains(mousePosition))
	{
		isDragged = true;
	}
}

void Circle::onMouseReleased(const sf::Vector2f& momentum)
{
	if (isDragged) velocity = momentum;
	isDragged = false;
}

void Circle::onMouseMoved(const sf::Vector2f& mousePosition)
{
	if (isDragged)
	{
		position = mousePosition - sf::Vector2f(circle.getRadius(), circle.getRadius());
		circle.setPosition(position);
	}
}
