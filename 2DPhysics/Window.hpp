#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Circle.hpp"

/*
    A class representing a window for rendering 2D graphics.

    This class manages an SFML window, handles events, updates the state,
    and renders a collection of Circle objects.
*/
class Window
{
private:
    int cnt = 0;
	sf::RenderWindow window;

    void handleEvents(const std::vector<std::unique_ptr<Circle>>&);
    void update();
    void render(const std::vector<std::unique_ptr<Circle>>&);

public:
    /*
        Construct a window with the specified width, height, and title.

        @param width: The width of the window.
        @param height: The height of the window.
        @param title: The title of the window displayed in the title bar.
        @param limit: The limit of the window's FPS.
    */
    Window(unsigned width, unsigned height, const std::string& title, unsigned limit = 60);

    Window();
    ~Window();

    /*
        Run the window and render the circles.

        @param circles: A constant reference to a vector of unique pointers to Circle objects.
                       These circles will be rendered on the window.
    */
    void run(const std::vector<std::unique_ptr<Circle>>& circles);

    /*
        Check if the window is currently open.

        @return Returns true if the window is open, false otherwise.
    */
    bool isOpen() const;
};

#endif // !WINDOW_HPP