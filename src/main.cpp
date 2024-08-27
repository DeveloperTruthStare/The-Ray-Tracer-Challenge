#include <iostream>
#include "tuple.h"

int main() {
	Tuple point = Point(4.3, -4.2, 3.1);
	Tuple vector = Vector(4.3, -4.2, 3.1);
	std::cout << vector.w << std::endl;
	std::cout << point.w << std::endl;

	Tuple sum = vector + point;
	std::cout << sum << std::endl;

	// Given
	Tuple p1 = Point(3, 2, 1);
	Tuple p2 = Point(5, 6, 7);
	Tuple diff = p1 - p2;
	std::cout << diff << std::endl;

	return 0;
}
