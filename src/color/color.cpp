#include "color.h"
#include <iostream>

namespace qprt
{
	Color::Color()
	{
		this->red = 0;
		this->green = 0;
		this->blue = 0;
	}
	Color::Color(float red, float green, float blue)
	{
		this->red = red;
		this->green = green;
		this-> blue = blue;
	}

	Color Color::operator+(const Color& other)
	{
		return Color(this->red + other.red, this->green + other.green, this->blue + other.blue);
	}

	Color Color::operator-(const Color& rhs)
	{
		return Color(this->red - rhs.red, this->green - rhs.green, this->blue - rhs.blue);
	}
	Color Color::operator*(const Color& rhs)
	{
		return Color(this->red * rhs.red, this->green * rhs.green, this->blue * rhs.blue);
	}
	std::ostream& operator<<(std::ostream& os, const Color& self)
	{
		os << "Color: (r: " << self.red << ", g: " << self.green << ", b: " << self.blue << ")";
		return os;
	}
	Color Color::operator*(float scalar)
	{
		return Color(this->red * scalar, this->green * scalar, this->blue * scalar);
	}
	Color operator*(float scalar, const Color& color)
	{
		return Color(color.red * scalar, color.green * scalar, color.blue * scalar);
	}
}
