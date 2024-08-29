#include <string>
#include <fstream>
#include <gtest/gtest.h>
#define EPSILON 0.000001

#include "canvas.h"

using namespace qprt;

TEST(Canvas, CreateCanvas) {
	// GIVEN
	Canvas canvas(10, 20);

	// THEN
	ASSERT_EQ(canvas.width, 10);
	ASSERT_EQ(canvas.height, 20);
}

TEST(Canvas, WritePixelToCanvas) {
	// GIVEN
	Canvas canvas(10, 20);
	Color red = Color(1, 0, 0);

	// WHEN
	canvas.write_pixel(red, 2, 3);

	// THEN
	Color pixel = canvas.pixel_at(2, 3);
	ASSERT_NEAR(pixel.red, red.red, EPSILON);
	ASSERT_NEAR(pixel.green, red.green, EPSILON);
	ASSERT_NEAR(pixel.blue, red.blue, EPSILON);
}

TEST(Canvas, SaveCanvasToPPMFile) {
	// GIVEN
	Canvas canvas(100, 200);

	// WHEN
	canvas.write_to_file("test.ppm");

	// THEN
	std::ifstream file("test.ppm");
	if(!file.is_open()) {
		ASSERT_EQ(1, 0);
	}
	std::string text;
	file >> text;
	ASSERT_EQ(text, "P3");
	
	file >> text;
	ASSERT_EQ(text, "100");

	file >> text;
	ASSERT_EQ(text, "200");


	file.close();
}
