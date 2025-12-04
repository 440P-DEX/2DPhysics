#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "Circle.hpp"
#include "Utility.hpp"
#include "Quadtree.hpp"

class Circle;
class Quadtree;

// A class representing a window for rendering 2D graphics.
// This class manages an SFML window, handles events, updates the state, and renders a collection of Circle objects.
class Application {
private:
	// Accessors
	std::vector<std::unique_ptr<Circle>>	circles;			// Vector to store unique pointers to Circle objects.
	std::unique_ptr<sf::RenderWindow>		window;				// Unique pointer to SFML RenderWindow object. Manages the lifetime of the window.
	std::unique_ptr<Quadtree>				quadtree;			// Represent a quadtree data structure used for spatial partitioning.
	std::vector<sf::Vector2f>				mouseTrajectory;	// Vector to store mouse trajectory points.
	bool									isRunning = false;	// Is the window gaining focus or not.

	// Method

	// Handle collision, detecting collisions, respond to collisions.
	void handleCollisions() const;

	// Method to handle SFML events.
	// Process incoming events and updates application state.
	void handleEvents();

	// Method to update application state.
	// Update positions, properties, or other game logic tasks.
	void update();

	// Method to render graphics to the SFML RenderWindow.
	// Draw objects, backgrounds, UI elements, etc.
	void render();

	// Method to calculate momentum based on mouse trajectory.
	// Use stored points to determine mouse movement speed and direction.
	sf::Vector2f calculateMomentum();

	/*
		Initialize the SFML RenderWindow with the specified properties.

		@param width: The width of the window.
		@param height: The height of the window.
		@param title: The title of the window displayed in the title bar.
		@param limit: The limit of the window's frames per second.
	*/
	void initWindow(unsigned width, unsigned height, const std::string& title, unsigned limit);

	/*
		Initialize objects in the application.

		@param number: The number of objects to initialize.
		@param radius: The radius of the objects to initialize.
	*/
	void initObject(int number, float radius);

public:
	// Singleton instance of the Application class
	// Allow access to a single instance of the Application class globally.
	static std::unique_ptr<Application> Instance;

	Application();
	~Application();

	/*
		Initialize a window with the specified width, height, and title.

		@param width: The width of the window.
		@param height: The height of the window.
		@param title: The title of the window displayed in the title bar.
		@param limit: The limit of the window's frames per second (default is 60).
		@param number: The number of objects to initialize.
		@param radius: The radius of the objects to initialize.
	*/
	void init(unsigned width, unsigned height, const std::string& title, int number, float radius, unsigned limit = 60);

	/*
		Run the window and render the objects.

		@param circles: A constant reference to a vector of unique pointers to Circle objects.
						These objects will be rendered on the window.
	*/
	void run();
};

#endif // !APPLICATION_HPP