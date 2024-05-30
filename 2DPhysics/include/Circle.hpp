#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <SFML/Graphics.hpp>
#include <cmath>
#include <memory>
#include "Constants.hpp"
#include "Application.hpp"

/*
	A class representing a 2D circle with basic physics.

	This class encapsulates a circle shape, its position, and its velocity,
	allowing it to be initialized, updated with basic physics, and rendered.
*/
class Circle
{
private:
	std::unique_ptr<sf::CircleShape> circle;
	sf::Vector2f position;
	sf::Vector2f velocity;
	bool isDragged = false;

public:
	/*
		Construct an object with the specified radius, color, and position.

		@param radius: The radius of the object.
		@param color: The color of the object.
		@param initialPosition: The initial position of the object.
	*/
	Circle(float radius, const sf::Color& corlor, const sf::Vector2f& initialPosition);

	Circle();
	~Circle();

	/*
		Update the position of the object using basic physics calculations.

		This method applies basic physics principles to update the position of the object.
		It adjusts the object's position based on its velocity and the passage of time.
	*/
	void update();

	/*
		Get the SFML circle shape object.

		@return: A const reference to the SFML circle shape object.
	*/
	const sf::CircleShape& getObj() const;

	/*
		Handle the mouse button pressed event.

		@param mousePosition: The position of the mouse when the button is pressed.
	*/
	void onMousePressed(const sf::Vector2f& mousePosition);

	/*
		Handle the mouse button released event.

		@param momentum: The momentum of the object after being thrown.
	*/
	void onMouseReleased(const sf::Vector2f& momentum);

	/*
		Handle the mouse moved event.

		@param mousePosition: The current position of the mouse.
	*/
	void onMouseMoved(const sf::Vector2f& mousePosition);

	/*
		Check if the circle is being dragged.

		@return Return true if the object is being dragged, otherwise.
	*/
	bool isBeingDragged() const { return isDragged; }

	/* 
		Check if the object collides other objects.

		@return Return true if the object.
	*/
	bool isColliding(const Circle& other) const;

	/*
		Handle the collision and update the object's velocity to bounce off.

		@param other: The velocity vector of the other object involved in the collision.
	*/
	void onCollision(Circle& other);
};

#endif // !CIRCLE_HPP