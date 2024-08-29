#include <gtest/gtest.h>
#define EPSILON 0.000001

#include "tuple.h"

using namespace qprt;

TEST(Tuple, CreatePoint) {
	Tuple point = Point(4.3, -4.2, 3.1);
	EXPECT_NEAR(point.x, 4.3, EPSILON);
	EXPECT_NEAR(point.y, -4.2, EPSILON);
	EXPECT_NEAR(point.z, 3.1, EPSILON);
	EXPECT_NEAR(point.w, 1, EPSILON);
}

TEST(Tuple, CreateVector) {
	// GIVEN
	Tuple vector = Vector(4.3, -4.2, 3.1);

	// THEN
	EXPECT_NEAR(vector.x, 4.3, EPSILON);
	EXPECT_NEAR(vector.y, -4.2, EPSILON);
	EXPECT_NEAR(vector.z, 3.1, EPSILON);
	EXPECT_NEAR(vector.w, 0, EPSILON);
}

TEST(Tuple, AddVectorPoint) {
	// GIVEN
	Tuple point = Point(4.3, -4.2, 3.1);
	Tuple vector = Vector(4.3, -4.2, 3.1);

	// WHEN
	Tuple sum = vector + point;

	// THEN
	ASSERT_NEAR(sum.x, 8.6, EPSILON);
	ASSERT_NEAR(sum.y, -8.4, EPSILON);
	ASSERT_NEAR(sum.z, 6.2, EPSILON);
	ASSERT_NEAR(sum.w, 1, EPSILON);
}

TEST(Tuple, SubtractPointPoint) {
	// GIVEN
	Tuple p1 = Point(3, 2, 1);
	Tuple p2 = Point(5, 6, 7);

	// WHEN
	Tuple diff = p2 - p1;
	
	// THEN
	ASSERT_NEAR(diff.x, 2, EPSILON);
	ASSERT_NEAR(diff.y, 4, EPSILON);
	ASSERT_NEAR(diff.z, 6, EPSILON);
	ASSERT_NEAR(diff.w, 0, EPSILON);
}

TEST(Tuple, SubtractPointVector) {
	// GIVEN
	Tuple point = Point(3, 2, 1);
	Tuple vector = Vector(5, 6, 7);

	// WHEN
	Tuple diff = point - vector;

	// THEN
	ASSERT_NEAR(diff.x, -2, EPSILON);
	ASSERT_NEAR(diff.y, -4, EPSILON);
	ASSERT_NEAR(diff.z, -6, EPSILON);
	ASSERT_NEAR(diff.w, 1, EPSILON);
}

TEST(Tuple, NegateVector) {
	// GIVEN
	Tuple v = Vector(1, -2, 3);

	// WHEN
	Tuple output = - v;

	// THEN
	ASSERT_NEAR(output.x, -1, EPSILON);
	ASSERT_NEAR(output.y, 2, EPSILON);
	ASSERT_NEAR(output.z, -3, EPSILON);
	ASSERT_NEAR(output.w, 0, EPSILON);
}

TEST(Tuple, MultiplyTupleScalar) {
	// GIVEN
	float scalar = 3.5;
	Tuple tuple = Tuple(1, -2, 3, -4);

	// WHEN
	Tuple output = tuple * scalar;

	// THEN
	ASSERT_NEAR(output.x, 3.5, EPSILON);
	ASSERT_NEAR(output.y, -7, EPSILON);
	ASSERT_NEAR(output.z, 10.5, EPSILON);
	ASSERT_NEAR(output.w, -14, EPSILON);
}

TEST(Tuple, MultiplyScalarTuple) {
	// GIVEN
	float scalar = 3.5;
	Tuple tuple = Tuple(1, -2, 3, -4);

	// WHEN
	Tuple output = scalar * tuple;

	// THEN
	ASSERT_NEAR(output.x, 3.5, EPSILON);
	ASSERT_NEAR(output.y, -7, EPSILON);
	ASSERT_NEAR(output.z, 10.5, EPSILON);
	ASSERT_NEAR(output.w, -14, EPSILON);
}


TEST(Tuple, DivideTupleScalar) {
	// GIVEN
	float scalar = 2;
	Tuple tuple = Tuple(1, -2, 3, -4);

	// WHEN
	Tuple output = tuple / scalar;

	// THEN
	ASSERT_NEAR(output.x, 0.5, EPSILON);
	ASSERT_NEAR(output.y, -1, EPSILON);
	ASSERT_NEAR(output.z, 1.5, EPSILON);
	ASSERT_NEAR(output.w, -2, EPSILON);
}

TEST(Tuple, Magnitude) {
	// GIVEN
	Tuple vectorX = Vector(1, 0, 0);
	Tuple vectorY = Vector(0, 1, 0);
	Tuple vectorZ = Vector(0, 0, 1);

	// WHEN
	float magnitudeX = vectorX.Magnitude();
	float magnitudeY = vectorY.Magnitude();
	float magnitudeZ = vectorZ.Magnitude();

	// THEN
	ASSERT_NEAR(magnitudeX, 1, EPSILON);
	ASSERT_NEAR(magnitudeY, 1, EPSILON);
	ASSERT_NEAR(magnitudeZ, 1, EPSILON);
}

TEST(Tuple, Normalize) {
	// GIVEN
	Tuple vector = Vector(4, 0, 0);

	// WHEN
	Tuple normal = vector.normal();

	// THEN
	ASSERT_NEAR(normal.x, 1, EPSILON);
}

TEST(Tuple, DotProduct) {
	// GIVEN
	Tuple a = Vector(1, 2, 3);
	Tuple b = Vector(2, 3, 4);

	// WHEN
	float dotProduct = dot_product(a, b);

	// THEN
	ASSERT_NEAR(dotProduct, 20, EPSILON);
}

TEST(Tuple, CrossProduct) {
	// GIVEN
	Tuple a = Vector(1, 2, 3);
	Tuple b = Vector(2, 3, 4);

	// WHEN
	Tuple crossA = cross_product(a, b);
	Tuple crossB = cross_product(b, a);
	
	// THEN
	//
}
