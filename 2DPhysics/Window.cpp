#include "Window.hpp"
#include "Circle.hpp"

Window::Window(unsigned width, unsigned height, const std::string& title, unsigned limit) : window(sf::VideoMode(width, height), title)
{
	window.setFramerateLimit(limit);
	std::cout << "Subsystem initialized...!\n";
}

Window::Window() = default;
Window::~Window() = default;

void Window::handleEvents()
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			std::cout << "Window closed.\n";
			window.close();
			break;

		case sf::Event::GainedFocus:
			std::cout << "Window gained focus.\n";
			break;
		
		case sf::Event::LostFocus:
			std::cout << "Window lost focus.\n";
			break;

		case sf::Event::MouseEntered:
			std::cout << "Mouse entered the window.\n";
			break;

		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Left)
				std::cout << "Left mouse button was pressed at (" << event.mouseButton.x << ", " << event.mouseButton.y << ").\n";
			else if (event.mouseButton.button == sf::Mouse::Right)
				std::cout << "Right mouse button was pressed at (" << event.mouseButton.x << ", " << event.mouseButton.y << ").\n";
			else if (event.mouseButton.button == sf::Mouse::Middle)
				std::cout << "Middle mouse button was pressed at (" << event.mouseButton.x << ", " << event.mouseButton.y << ").\n";
			break;

		default:
			break;
		}
	}
}

void Window::update()
{
	++cnt;
}

void Window::render(const std::vector<std::unique_ptr<Circle>>& circles)
{
	window.clear();

	for (const auto& circle : circles)
	{
		window.draw(circle->getObj());
	}

	window.display();
}

void Window::run(const std::vector<std::unique_ptr<Circle>> &circles)
{
	Window::handleEvents();
	Window::update();
	Window::render(circles);
}

bool Window::isOpen() const
{
	return window.isOpen();
}