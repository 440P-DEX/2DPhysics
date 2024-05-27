#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "Circle.hpp"
#include "Utility.hpp"

/*
    A class representing a window for rendering 2D graphics.

    This class manages an SFML window, handles events, updates the state,
    and renders a collection of Circle objects.
*/
class Application
{
private:
    //  Vector to store unique pointers to Circle objects.
    std::vector<std::unique_ptr<Circle>> circles;

    /*
        Unique pointer to SFML RenderWindow object.
        Manages the lifetime of the window.
    */
    std::unique_ptr<sf::RenderWindow> window;

    /*
        Vector to store mouse trajectory points.
        Useful for tracking mouse movement over time.
    */
    std::vector<sf::Vector2f> mouseTrajectory;

    /*
        Method to handle SFML events.
        Processes incoming events and updates application state.
    */
    void handleEvents();

    /*
        Method to update application state.
        Updates positions, properties, or other game logic tasks.
    */
    void update();

    /*
        Method to render graphics to the SFML RenderWindow.
        Draws objects, backgrounds, UI elements, etc.
    */
    void render();

    /*
        Method to calculate momentum based on mouse trajectory.
        Uses stored points to determine mouse movement speed and direction.
    */
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
    /*
        Singleton instance of the Application class.
        Allows access to a single instance of the Application class globally.
    */
    static std::unique_ptr<Application> Instance;

    Application();
    ~Application();

    /*
        Initialize a window with the specified width, height, and title.

        @param width: The width of the window.
        @param height: The height of the window.
        @param title: The title of the window displayed in the title bar.
        @param limit: The limit of the window's frames per second (default is 60).
        @param number: The number of circles to initialize.
        @param radius: The radius of the circles to initialize.
    */
    void init(unsigned width, unsigned height, const std::string& title, int number, float radius, unsigned limit = 60);

    /*
        Run the window and render the circles.

        @param circles: A constant reference to a vector of unique pointers to Circle objects.
                       These circles will be rendered on the window.
    */
    void run();
};

#endif // !APPLICATION_HPP