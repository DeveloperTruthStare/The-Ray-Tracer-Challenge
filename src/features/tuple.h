#pragma once
#include <iostream>

namespace qprt
{
	class Tuple
	{
	 public: 
		Tuple(float, float, float, float);
		float x, y, z, w;

		float Magnitude();
		Tuple normal();

		Tuple operator+(const Tuple&);
		Tuple operator-(const Tuple&);
		Tuple operator-();
		friend Tuple operator*(float lhs, const Tuple& rhs);
		Tuple operator*(float);
		Tuple operator/(float);
		friend std::ostream& operator<<(std::ostream&, const Tuple&);
        float& operator[](size_t);
        float operator[](size_t) const;
	};


	Tuple Point(float, float, float);
	Tuple Vector(float, float, float);
	float dot_product(Tuple, Tuple);
	Tuple cross_product(Tuple, Tuple);
	Tuple operator*(float, const Tuple&);
}
