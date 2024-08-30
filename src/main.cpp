#include "features/canvas.h"
#include "features/color.h"
#include "features/tuple.h"

using namespace qprt;


int main()
{
	auto position = Point(0, 1, 0);
	auto velocity = Vector(1, 1.8, 0).normal() * 11.25;
	auto gravity = Vector(0, -0.1, 0);
	auto canvas = Canvas(900, 550);
	auto wind = Vector(-0.01, 0, 0);

	std::cout << position << std::endl;
	std::cout << velocity << std::endl;
	std::cout << gravity << std::endl;


	while(position.y > 0)
	{
		canvas.write_pixel(Color(1, 0.2, 0), (int)position.x, canvas.height - (int)position.y);
		position = position + velocity; 
		velocity = velocity + gravity + wind;
	}
	canvas.write_to_file("projectile.ppm");
	return 0;
}
