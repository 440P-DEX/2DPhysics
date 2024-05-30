#include "Application.hpp"
#include "Constants.hpp"

int main()
{
	// Set `RADIUS` to any non-negative real value you want, and if you want random sizes for each object, set 'RADIUS' to 0. Default value for RADIUS is 50.0.
	// Set 'OBJECTS' to any non-negative integer value you want (0 is valid value as it is non-negative). Default value for OBJECTS is 5.
	// Set 'FPS' to any non-negative integer value you want.
	Application::Instance->init(WINDOW_WIDTH, WINDOW_HEIGHT, "2D Physics", OBJECTS, RADIUS, FPS);

	// Run the instance of Application.
	Application::Instance->run();

	return EXIT_SUCCESS;
}