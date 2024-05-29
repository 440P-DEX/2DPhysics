#include "Application.hpp"
#include "Constants.hpp"

int main()
{
	// Set `RADIUS` to any (non-negative) value you want, and if you want random sizes for each object, set 'RADIUS' to 0.
	Application::Instance->init(WINDOW_WIDTH, WINDOW_HEIGHT, "2D Physics", 5U, RADIUS, 60);

	// Run the instance of Application.
	Application::Instance->run();

	return EXIT_SUCCESS;
}