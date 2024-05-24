#include "Window.hpp"
#include "Circle.hpp"
#include "Constants.hpp"

sf::Vector2f Window::calculateMomentum()
{
	sf::Vector2f velocity;

	if (mouseTrajectory.size() > 10)
	{
		velocity.x = (mouseTrajectory[mouseTrajectory.size() - 1].x - mouseTrajectory.front().x) / static_cast<float>(mouseTrajectory.size()) * 2;
		velocity.y = (mouseTrajectory[mouseTrajectory.size() - 1].y - mouseTrajectory.front().y) / static_cast<float>(mouseTrajectory.size()) * 2;
	}

	return velocity;
}

Window::Window(unsigned width, unsigned height, const std::string& title, unsigned limit) : window(sf::VideoMode(width, height), title)
{
	window.setFramerateLimit(limit);
	std::cout << "Subsystem initialized...!\n";
}

Window::Window() = default;
Window::~Window() = default;

void Window::handleEvents(const std::vector<std::unique_ptr<Circle>>& circles)
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			std::cout << "Window closed...!\n";
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

		case sf::Event::MouseLeft:
			std::cout << "Mouse left the window.\n";
			break;

		case sf::Event::Resized:
			std::cout << "New window size: " << window.getSize().x << "x" << window.getSize().y << "\n";

			std::cerr << "CAUTION: WINDOW SHOULD NOT BE RESIZED, as it may affect program functionality!\n";
			std::cerr << "SUGGESTION: change the window size to " << WINDOW_WIDTH << "x" << WINDOW_HEIGHT << ".\n";
			break;

		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				for (const auto& circle : circles)
				{
					circle->onMousePressed(sf::Vector2f(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)));
					if (circle->isBeingDragged()) break;
				}

			}
			break;

		case sf::Event::MouseButtonReleased:
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				for (const auto& circle : circles)
					circle->onMouseReleased(calculateMomentum());
			}
			break;

		case sf::Event::MouseMoved:
			for (const auto& circle : circles)
				circle->onMouseMoved(sf::Vector2f(static_cast<float>(event.mouseMove.x), static_cast<float>(event.mouseMove.y)));
			break;

		default:
			break;
		}
	}
}

void Window::update()
{
	mouseTrajectory.push_back(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
	if (mouseTrajectory.size() > 20) { mouseTrajectory.erase(mouseTrajectory.begin()); }
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
	Window::handleEvents(circles);
	Window::update();
	Window::render(circles);
}

bool Window::isOpen() const
{
	return window.isOpen();
}