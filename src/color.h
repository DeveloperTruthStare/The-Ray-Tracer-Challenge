#pragma once
#include <iostream>

namespace qprt
{
	class Color
	{
	 public:
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
