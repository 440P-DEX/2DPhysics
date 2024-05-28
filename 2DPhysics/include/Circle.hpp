#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <SFML/Graphics.hpp>

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
	bool isDragged = false;

public:
	/*
		Construct a circle with the specified radius, color, and position.

		@param radius: The radius of the circle.
		@param color: The color of the circle.
		@param initialPosition: The initial position of the circle
	*/
	Circle(float radius, const sf::Color& corlor, const sf::Vector2f& initialPosition);

	Circle();
	~Circle();

	/*
		Initialize a circle with the specified radius, color, and position.

		@param radius: The radius of the circle.
		@param color: The color of the circle.
		@param position: The initial position of the circle
	*/
	void init(float radius, const sf::Color& corlor, const sf::Vector2f& initialPosition);

	/*
		Update the position of the circle using basic physics calculations.

		This method applies basic physics principles to update the position of the circle.
		It adjusts the circle's position based on its velocity and the passage of time.
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

		@param momentum: The momentum of the circle after being thrown.
	*/
	void onMouseReleased(const sf::Vector2f& momentum);

	/*
		Handle the mouse moved event.

		@param mousePosition: The current position of the mouse.
	*/
	void onMouseMoved(const sf::Vector2f& mousePosition);

	/*
		Check if the circle is being dragged.

		@return Return true if the circle is being dragged, otherwise.
	*/
	bool isBeingDragged() const { return isDragged; }
};

#endif // !CIRCLE_HPP