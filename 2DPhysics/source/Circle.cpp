#include "Circle.hpp"

Circle::Circle(float radius, const sf::Color& color, const sf::Vector2f& initialPosition) : circle(radius), position(initialPosition)
{
	circle.setFillColor(color);
	circle.setPosition(position);
	circle.setOrigin(radius, radius);
}

Circle::Circle() = default;
Circle::~Circle() = default;

void Circle::update()
{
	if (!isDragged)
	{
		velocity.x *= friction;
		velocity.y += gravitationalAcceleration;
		position += velocity;

		float radius = circle.getRadius();
		const auto size = static_cast<sf::Vector2f>(Application::Instance->getWindowSize());

		if (position.y + radius >= size.y)
		{
			position.y = size.y - radius;
			velocity.y *= -retention;
		}

		if (position.x + radius >= size.x)
		{
			position.x = size.x - radius;
			velocity.x = -velocity.x;
		}
		else if (position.x - radius <= 0)
		{
			position.x = 0 + radius;
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
		position = mousePosition;
		circle.setPosition(position);
	}
}

bool Circle::isColliding(const Circle& other) const
{
	float distanceX = this->position.x - other.position.x;
	float distanceY = this->position.y - other.position.y;
	float radiusSum = this->circle.getRadius() + other.circle.getRadius();
	float distanceSquared = distanceX * distanceX + distanceY * distanceY;

	return distanceSquared <= radiusSum * radiusSum;
}