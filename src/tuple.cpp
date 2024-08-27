#include "tuple.h"
#include <iostream>

Tuple::Tuple(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

Tuple Tuple::operator+(const Tuple& other)
{
	return Tuple(this->x + other.x, this->y + other.y, this->z + other.z, this->w + other.w);
}

Tuple Tuple::operator-(const Tuple& other)
{
	return Tuple(this->x - other.x, this->y - other.y, this->z - other.z, this->w - other.w);
}

std::ostream& operator<<(std::ostream& os, const Tuple& self)
{
	os << "Tuple(" << self.x << ", " << self.y << ", " << self.z << ", " << self.w << ")";
	return os;
}

Tuple Point(float x, float y, float z)
{
	return Tuple(x, y, z, 1);
}

Tuple Vector(float x, float y, float z)
{
	return Tuple(x, y, z, 0);
}
