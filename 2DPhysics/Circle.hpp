#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

/*
	A class representing a 2D circle with basic physics.

	This class encapsulates a circle shape, its position, and its velocity,
	allowing it to be initialized, updated with basic physics, and rendered.
*/
class Circle
{
private:
	sf::CircleShape circle;
	sf::Vector2f position;
	sf::Vector2f velocity;

public:
	/*
	Constructs a circle with the specified radius, color, and position.

	@param radius: the radius of the circle.
	@param color: the color of the circle.
	@param initialPosition: the initial position of the circle
	*/
	Circle(float radius, const sf::Color& corlor, const sf::Vector2f& initialPosition);

	Circle();
	~Circle();

	/*
		Initializes a circle with the specified radius, color, and position.

		@param radius: the radius of the circle.
		@param color: the color of the circle.
		@param position: the initial position of the circle
	*/
	void init(float radius, const sf::Color& corlor, const sf::Vector2f& initialPosition);

	/*
		Update the position of the circle using basic physics calculations.

		This method applies basic physics principles to update the position of the circle.
		It adjusts the circle's position based on its velocity and the passage of time.
	*/
	void update();

	/*
		Gets the SFML circle shape object.

		@return: A const reference to the SFML circle shape object.
	*/
	const sf::CircleShape& getObj() const;
};

#endif // !CIRCLE_HPP