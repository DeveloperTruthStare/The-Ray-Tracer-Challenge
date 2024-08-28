#include <iostream>
#include "tuple.h"
#include "tuple_tests.h"

namespace qprt::test
{

	void print_tuple(Tuple tuple)
	{
		std::cout << tuple << std::endl;
	}

	void create_point()
	{
		Tuple point = Point(4.3, -4.2, 3.1);
		std::cout << point << std::endl;
	}

	void create_vector()
	{
		Tuple vector = Vector(4.3, -4.2, 3.1);
		std::cout << vector << std::endl;
	}

	void add_vector_point()
	{
		Tuple point = Point(4.3, -4.2, 3.1);
		Tuple vector = Vector(4.3, -4.2, 3.1);
		Tuple sum = vector + sum;
		std::cout << sum << std::endl;
	}

	void subtract_point_point()
	{
		Tuple p1 = Point(3, 2, 1);
		Tuple p2 = Point(5, 6, 7);
		Tuple diff = p2 - p1;
		std::cout << diff << std::endl;
	}

	void subtract_point_vector()
	{
		Tuple point = Point(3, 2, 1);
		Tuple vector = Vector(5, 6, 7);
		Tuple diff = point - vector;
		std::cout << diff << std::endl;
	}

	void negate_tuple() {
		Tuple v = Vector(1, -2, 3);
		Tuple output = - v;
		std::cout << output << std::endl;
	}

	void multiply_tuple_scalar() {
		float scalar = 3.5;
		Tuple tuple = Tuple(1, -2, 3, -4);
		Tuple output = tuple * scalar;
		std::cout << output << std::endl;
	}

	void multiply_scalar_tuple() {
		float scalar = 3.5;
		Tuple tuple = Tuple(1, -2, 3, -4);
		Tuple output = scalar * tuple;
		std::cout << output << std::endl;
	}

	void divide_tuple_scalar()
	{
		float scalar = 2;
		Tuple tuple = Tuple(1, -2, 3, -4);
		Tuple output = tuple / scalar;
		std::cout << output << std::endl;
	}

	void magnitude(Tuple vector)
	{
		float magnitude = vector.Magnitude();
		std::cout << "Magnitude of " << vector << ": " << magnitude << std::endl;
	}

	void normalize()
	{
		Tuple vector = Vector(4, 0, 0);
		Tuple normal = vector.normal();
		std::cout << normal << std::endl;
	}

	void dot_test()
	{
		Tuple a = Vector(1, 2, 3);
		Tuple b = Vector(2, 3, 4);
		float dotProduct = dot_product(a, b);
		std::cout << dotProduct << std::endl;
	}

	void cross_test()
	{
		Tuple a = Vector(1, 2, 3);
		Tuple b = Vector(2, 3, 4);
		Tuple cross = cross_product(a, b);
		print_tuple(cross);
		cross = cross_product(b, a);
		print_tuple(cross);
	}

	void run_all_tests_tuple() {
		std::cout << "\tRunning Tuple, Point and Vector Tests\n\n";
		create_point();
		create_vector();
		add_vector_point();
		subtract_point_point();
		subtract_point_vector();

		negate_tuple();
		multiply_tuple_scalar();
		multiply_scalar_tuple();
		divide_tuple_scalar();

		magnitude(Vector(1, 0, 0));
		magnitude(Vector(0, 1, 0));
		magnitude(Vector(0, 0, 1));
		magnitude(Vector(1, 2, 3));
		magnitude(Vector(-1, -2, -3));

		normalize();

		dot_test();
		cross_test();
	}
}
