#include "Application.hpp"
#include "Constants.hpp"

int main()
{
	Application::Instance->init(WINDOW_WIDTH, WINDOW_HEIGHT, "2D Physics", 5U, RADIUS, 60);

	Application::Instance->run();

	return EXIT_SUCCESS;
}