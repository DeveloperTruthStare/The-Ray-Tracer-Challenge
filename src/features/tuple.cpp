#include "tuple.h"
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <sstream>

namespace qprt
{

	Tuple::Tuple() {
		this->x = this->y = this->z = this->w = 0;
	}
	Tuple::Tuple(float x, float y, float z, float w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	float Tuple::SqrMagnitude() const {
		return (this->x * this->x) + (this->y * this->y) + (this->z * this->z) + (this->w * this->z);
	}

	float Tuple::Magnitude() const
	{
		return std::sqrt(this->SqrMagnitude());
	}

	Tuple Tuple::normal()
	{
		float magnitude = Magnitude();
		return *this / magnitude;
	}

	Tuple Tuple::operator+(const Tuple& other) const
	{
		return Tuple(this->x + other.x, this->y + other.y, this->z + other.z, this->w + other.w);
	}

	Tuple Tuple::operator-(const Tuple& other) const
	{
		return Tuple(this->x - other.x, this->y - other.y, this->z - other.z, this->w - other.w);
	}

	Tuple Tuple::operator-()
	{
		return Tuple(-this->x, -this->y, -this->z, -this->w);
	}

	Tuple operator*(float scalar, const Tuple& tuple)
	{
		return Tuple(tuple.x * scalar, tuple.y * scalar, tuple.z * scalar, tuple.w * scalar);
	}

	Tuple Tuple::operator*(float scalar)
	{
		return Tuple(this->x * scalar, this->y * scalar, this->z * scalar, this->w * scalar);
	}

	Tuple Tuple::operator/(float scalar)
	{
		return Tuple(this->x / scalar, this->y / scalar, this->z / scalar, this->w / scalar);
	}

	std::ostream& operator<<(std::ostream& os, const Tuple& self)
	{
		if (self.w == 1) {
			os << "Point(";
		} else if (self.w == 0) {
			os << "Vector(";
		} else {
			os << "Tuple(";
		}
		os << self.x << ", " << self.y << ", " << self.z << ", " << self.w << ")";
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

	float dot_product(Tuple a, Tuple b)
	{
		return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
	}
	Tuple cross_product(Tuple a, Tuple b)
	{
		return Vector(a.y * b.z - a.z * b.y,
					  a.z * b.x - a.x * b.z,
					  a.x * b.y - a.y * b.x);
	}
    float& Tuple::operator[](size_t index)
    {
        if (index == 0) return x;
        if (index == 1) return y;
        if (index == 2) return z;
        if (index == 3) return w;
        throw new std::invalid_argument("Index out of range for tuple, ensure range is between (0, 3)");
    }
    float Tuple::operator[](size_t index) const
    {
        if (index == 0) return x;
        if (index == 1) return y;
        if (index == 2) return z;
        if (index == 3) return w;
        throw new std::out_of_range("Index out of range");
    }
	Tuple Tuple::copy() const {
		return Tuple(this->x, this->y, this->z, this->w);
	}

	std::string Tuple::to_string() const {
		std::ostringstream oss;
		oss << "(" << this->x << ", " << this->y << ", " << this->z << ", " << this->w << ")";
		return oss.str();
	}
}
