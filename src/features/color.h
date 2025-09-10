#pragma once
#include <iostream>

#define BLACK Color(0, 0, 0)

namespace qprt
{
	class Color
	{
	 public:
		 Color();
		 Color(float, float, float);
		 float red, green, blue;

		 Color operator+(const Color&);
		 Color operator-(const Color&);
		 Color operator*(float);
		 Color operator*(const Color&);
		 friend Color operator*(float lhs, const Color& rhs);
		 friend std::ostream& operator<<(std::ostream&, const Color&);
	};

	Color operator*(float, const Color&);
}
