#include <gtest/gtest.h>

#include "../src/features/color.h"

#define EPSILON 0.000001

using namespace qprt;

TEST(Color, CreateColor) {
	// GIVEN
	Color color = Color(-0.5, 0.4, 1.7);

	// THEN
	ASSERT_NEAR(color.red, -0.5, EPSILON);
	ASSERT_NEAR(color.green, 0.4, EPSILON);
	ASSERT_NEAR(color.blue, 1.7, EPSILON);
}

TEST(Color, AddColorColor) {
	// GIVEN
	Color a = Color(0.9, 0.6, 0.75);
	Color b = Color(0.7, 1, 0.25);

	// WHEN
	Color sum = a + b;

	// THEN
	ASSERT_NEAR(sum.red, 1.6, EPSILON);
	ASSERT_NEAR(sum.green, 1.6, EPSILON);
	ASSERT_NEAR(sum.blue, 1, EPSILON);
}

TEST(Color, SubtractColorColor) {
	// GIVEN
	Color a = Color(0.9, 0.6, 0.75);
	Color b = Color(0.7, 0.1, 0.25);

	// WHEN
	Color diff = a - b;

	// THEN
	ASSERT_NEAR(diff.red, 0.2, EPSILON);
	ASSERT_NEAR(diff.green, 0.5, EPSILON);
	ASSERT_NEAR(diff.blue, 0.5, EPSILON);
}

TEST(Color, MultiplyColorScalar) {
   // GIVEN	
	float scalar = 2;
	Color color = Color(0.2, 0.3, 0.4);

	// WHEN
	Color output = color * scalar;

	// THEN
	ASSERT_NEAR(output.red, 0.4, EPSILON);
	ASSERT_NEAR(output.green, 0.6, EPSILON);
	ASSERT_NEAR(output.blue, 0.8, EPSILON);
}


TEST(Color, MultiplyScalarColor) {
   // GIVEN	
	float scalar = 2;
	Color color = Color(0.2, 0.3, 0.4);

	// WHEN
	Color output = scalar * color;

	// THEN
	ASSERT_NEAR(output.red, 0.4, EPSILON);
	ASSERT_NEAR(output.green, 0.6, EPSILON);
	ASSERT_NEAR(output.blue, 0.8, EPSILON);
}

TEST(Color, MultiplyColorColot) {
	// GIVEN
	Color a = Color(1, 0.2, 0.4);
	Color b = Color(0.9, 1, 0.1);

	// WHEN
	Color output = a * b;

	// THEN
	ASSERT_NEAR(output.red, 0.9, EPSILON);
	ASSERT_NEAR(output.green, 0.2, EPSILON);
	ASSERT_NEAR(output.blue, 0.04, EPSILON);
}
