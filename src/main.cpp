#include "features/canvas.h"
#include "features/color.h"
#include "features/tuple.h"
#include "features/translation.h"
#include "features/sphere.h"
#include "features/ray.h"
#include "features/light.h"
#include "features/world.h"

#include <memory>
#include <cmath>

#define pi 3.1415

using namespace qprt;

float radToDeg(float radians) {
	return radians * 180 / pi;
}
float degToRad(float degrees) {
	return degrees * pi / 180;
}

void makeSphere();

int main()
{
	makeSphere();
	return 0;
}

void makeSphere() {
	World world = World();

	auto cameraPosition = Point(0, 0, -5);

	float wallSize = 10;
	float wallZ = 10;

	auto canvas_pixels = 1000;
	float half = wallSize / 2;
	float pixelSize = wallSize/canvas_pixels;

	auto canvas = Canvas(canvas_pixels, canvas_pixels);

	for(auto y = 0; y < canvas_pixels; ++y) {
		float worldY = half - pixelSize * y;
		for(auto x = 0; x < canvas_pixels; ++x) {
			float worldX = -half + pixelSize * x;
			auto position = Point(worldX, worldY, wallZ);

			Ray ray = Ray(cameraPosition, (position - cameraPosition).normal());
			auto color = world.color_at(ray);
			canvas.write_pixel(color, x, y);
		}
	}

	canvas.write_to_file("sphere.ppm");
}