#include "color.h"
#include "color_tests.h"

#include <iostream>

namespace qprt::test
{
	void print_color(Color color)
	{
		std::cout << color << std::endl;
	}
	void create_color()
	{
		Color color = Color(-0.5, 0.4, 1.7);
		std::cout << color << std::endl;
	}
	void add_color_color()
	{
		Color a = Color(0.9, 0.6, 0.75);
		Color b = Color(0.7, 1, 0.25);
		Color sum = a + b;
		print_color(sum);
	}
	void subtract_color_color()
	{
		Color a = Color(0.9, 0.6, 0.75);
		Color b = Color(0.7, 0.1, 0.25);
		Color diff = a - b;
		print_color(diff);
	}
	void multiply_color_scalar()
	{
		float scalar = 2;
		Color color = Color(0.2, 0.3, 0.4);
		Color output = color * scalar;
		print_color(output);
	}
	void multiply_scalar_color()
	{
		float scalar = 2;
		Color color = Color(0.2, 0.3, 0.4);
		Color output = scalar * color;
		print_color(output);
	}
	void multiply_color_color()
	{
		Color a = Color(1, 0.2, 0.4);
		Color b = Color(0.9, 1, 0.1);
		Color output = a * b;
		print_color(output);
	}
	void run_all_tests_color()
	{
		std::cout << "\tRunning Color Tests\n\n";
		std::cout << "Creating a color\n\t";
		create_color();
		std::cout << "Adding Colors\n\t";
		add_color_color();
		std::cout << "Subtracting Colors\n\t";
		subtract_color_color();
		std::cout << "Multiply Color x scalar\n\t";
		multiply_color_scalar();
		std::cout << "Multiply Scalar x Color\n\t";
		multiply_scalar_color();
		std::cout << "Multiple Color x Color\n\t";
		multiply_color_color();
	}
}
