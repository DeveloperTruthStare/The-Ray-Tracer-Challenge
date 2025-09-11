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
#include <chrono>
#include <cstdlib>
#include <ctime>

#define pi 3.1415

using namespace qprt;

float radToDeg(float radians)
{
	return radians * 180 / pi;
}
float degToRad(float degrees)
{
	return degrees * pi / 180;
}

void makeSphere();
void makeWorleyNoise();
float timeFuncRuntime(void (*)());

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	float timeToComplete = timeFuncRuntime(makeWorleyNoise);
	std::cout << "Worley noise generated in " << timeToComplete << " ms" << std::endl;

	return 0;
}

float timeFuncRuntime(void (*func)())
{
	auto start = std::chrono::high_resolution_clock::now();
	func();
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float, std::milli> duration = end - start;
	return duration.count();
}

void makeWorleyNoise()
{
	Canvas canvas = Canvas(400, 400);

	int featurePoints = 10;
	std::vector<Tuple> points;

	for (int i = 0; i < featurePoints; ++i)
	{
		float x = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * canvas.width;
		float y = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * canvas.height;
		points.push_back(Point(x, y, 0));
	}

	for (int y = 0; y < canvas.height; ++y)
	{
		for (int x = 0; x < canvas.width; ++x)
		{
			Tuple currentPoint = Point(x, y, 0);
			float closestDistance = INFINITY;
			for (const auto &p : points)
			{
				float distance = (p - currentPoint).Magnitude();
				if (distance < closestDistance)
				{
					closestDistance = distance;
				}
			}
			float intensity = closestDistance / 400.0f;
			if (intensity > 1)
				intensity = 1;
			Color color = Color(intensity, intensity, intensity);
			canvas.write_pixel(color, x, y);
		}
	}

	canvas.write_to_file("worley_noise.ppm");
}

void makeSphere()
{
	World world = World();

	auto cameraPosition = Point(0, 0, -5);

	float wallSize = 10;
	float wallZ = 10;

	auto canvas_pixels = 1000;
	float half = wallSize / 2;
	float pixelSize = wallSize / canvas_pixels;

	auto canvas = Canvas(canvas_pixels, canvas_pixels);

	for (auto y = 0; y < canvas_pixels; ++y)
	{
		float worldY = half - pixelSize * y;
		for (auto x = 0; x < canvas_pixels; ++x)
		{
			float worldX = -half + pixelSize * x;
			auto position = Point(worldX, worldY, wallZ);

			Ray ray = Ray(cameraPosition, (position - cameraPosition).normal());
			auto color = world.color_at(ray);
			canvas.write_pixel(color, x, y);
		}
	}

	canvas.write_to_file("sphere.ppm");
}