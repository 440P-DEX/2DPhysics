#include "Circle.hpp"

Circle::Circle(float radius, const sf::Color& color, const sf::Vector2f& initialPosition, const sf::Vector2u& size)
	: circle(std::make_unique<sf::CircleShape>(radius)),
	windowSize(static_cast<sf::Vector2f>(size)),
	position(initialPosition),
	mass(radius* radius* radius) {
	circle->setFillColor(color);
	circle->setPosition(position);
	circle->setOrigin(radius, radius);
}

Circle::Circle() = default;
Circle::~Circle() = default;

void Circle::update() {
	deltaTime = clock.restart().asSeconds();

	if (!isDragged) {
		velocity.x *= friction;
		velocity.y += gravitationalAcceleration;
		position += velocity * deltaTime;

		float radius = circle->getRadius();

		if (position.y + radius >= windowSize.y) {
			position.y = windowSize.y - radius;
			velocity.y *= -retention;
		}

		if (position.x + radius >= windowSize.x) {
			position.x = windowSize.x - radius;
			velocity.x *= -retention;
		}
		else if (position.x - radius <= 0) {
			position.x = 0 + radius;
			velocity.x *= -retention;
		}

		circle->setPosition(position);
	}
	else {
		velocity = sf::Vector2f();
	}
}

const sf::CircleShape& Circle::getObj() const {
	return *circle;
}

sf::FloatRect Circle::getBounds() const {
	return circle->getGlobalBounds();
}

void Circle::onMousePressed(const sf::Vector2f& mousePosition) {
	if (circle->getGlobalBounds().contains(mousePosition)) {
		isDragged = true;
	}
}

void Circle::onMouseReleased(const sf::Vector2f& momentum) {
	if (isDragged) { velocity = momentum; }
	isDragged = false;
}

void Circle::onMouseMoved(const sf::Vector2f& mousePosition) {
	if (isDragged) {
		position = mousePosition;
		circle->setPosition(position);
	}
}

bool Circle::isColliding(const Circle& other) const {
	float distanceX = this->position.x - other.position.x;
	float distanceY = this->position.y - other.position.y;
	float radiusSum = this->circle->getRadius() + other.circle->getRadius();
	float distanceSquared = distanceX * distanceX + distanceY * distanceY;

	return distanceSquared <= radiusSum * radiusSum;
}

void Circle::onCollision(Circle& other) {
	sf::Vector2f relativeVelocity = other.velocity - this->velocity;

	sf::Vector2f normal = other.position - this->position;
	float distance = std::sqrt(normal.x * normal.x + normal.y * normal.y);

	if (distance == 0.0F) {
		normal = sf::Vector2f(1.0F, 1.0F);
		distance = 1.0F;
	}

	float overlap = this->circle->getRadius() + other.circle->getRadius() - distance;

	normal /= distance;

	float velocityAlongNormal = relativeVelocity.x * normal.x + relativeVelocity.y * normal.y;

	this->position -= normal * (overlap / 2.0F);
	other.position += normal * (overlap / 2.0F);

	if (velocityAlongNormal > 0) return;

	float m1 = this->mass;
	float m2 = other.mass;

	float impulseScalar = -(1 + restitution) * velocityAlongNormal;
	impulseScalar /= (1 / m1 + 1 / m2);

	sf::Vector2f impulse = impulseScalar * normal;

	this->velocity -= impulse / m1;
	other.velocity += impulse / m2;
}