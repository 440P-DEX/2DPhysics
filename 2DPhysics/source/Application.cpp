#include "Application.hpp"

#define FORLOOPCIRCLE for (const auto& circle : circles)

std::unique_ptr<Application> Application::Instance = std::make_unique<Application>();

Application::Application() = default;
Application::~Application() = default;

sf::Vector2f Application::calculateMomentum()
{
	sf::Vector2f velocity;

	if (mouseTrajectory.size() > 10)
	{
		velocity.x = (mouseTrajectory[mouseTrajectory.size() - 1].x - mouseTrajectory.front().x) / static_cast<float>(mouseTrajectory.size()) * 2;
		velocity.y = (mouseTrajectory[mouseTrajectory.size() - 1].y - mouseTrajectory.front().y) / static_cast<float>(mouseTrajectory.size()) * 2;
	}

	return velocity;
}

void Application::handleEvents()
{
	sf::Event event;

	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			std::cout << "Window closed...!\n";
			window->close();
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

		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				FORLOOPCIRCLE
				{
					circle->onMousePressed(sf::Vector2f(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)));
					if (circle->isBeingDragged()) break;
				}

			}
			break;

		case sf::Event::MouseButtonReleased:
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				FORLOOPCIRCLE circle->onMouseReleased(calculateMomentum());
			}
			break;

		case sf::Event::MouseMoved:
			FORLOOPCIRCLE circle->onMouseMoved(sf::Vector2f(static_cast<float>(event.mouseMove.x), static_cast<float>(event.mouseMove.y)));
			break;

		default:
			break;
		}
	}
}

void Application::update()
{
	mouseTrajectory.push_back(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window)));
	if (mouseTrajectory.size() > 20) { mouseTrajectory.erase(mouseTrajectory.begin()); }

	for (size_t i = 0; i < circles.size(); ++i)
	{
		for (size_t j = i + 1; j < circles.size(); ++j)
		{
			if (circles[i]->isColliding(*circles[j]))
			{
				circles[i]->onCollision(*circles[j]);
			}
		}
	}
}

void Application::render()
{
	window->clear();

	FORLOOPCIRCLE window->draw(circle->getObj());

	window->display();
}

sf::Vector2u Application::getWindowSize() const
{
	return window->getSize();
}

void Application::run()
{
	while (window->isOpen())
	{
		FORLOOPCIRCLE circle->update();

		Application::update();
		Application::handleEvents();
		Application::render();
	}
}

void Application::init(unsigned width, unsigned height, const std::string& title, int number, float radius, unsigned limit)
{
	initWindow(width, height, title, limit);
	initObject(number, radius);

	std::cout << "Subsystem initialized...!\n";
}

void Application::initWindow(unsigned width, unsigned height, const std::string& title, unsigned limit)
{
	window = std::make_unique<sf::RenderWindow>();

	sf::VideoMode mode;
	mode.width = width;
	mode.height = height;

	window->create(mode, title, sf::Style::Close);
	window->setFramerateLimit(limit);
}

void Application::initObject(int number, float radius)
{
	auto size = static_cast<sf::Vector2f>(window->getSize());

	float radiusR;

	for (int i = 0; i < number; ++i)
	{
		if (radius == 0) radiusR = randomFloat(10.f, 100.f);
		else radiusR = radius;
		circles.push_back(std::make_unique<Circle>(radiusR, randomColor(), sf::Vector2f(randomFloat(radiusR, size.x + radiusR), randomFloat(radiusR, size.y + radiusR))));
	}
}