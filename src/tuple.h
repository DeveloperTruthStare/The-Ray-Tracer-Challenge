#pragma once
#include <iostream>

class Tuple {
 public: 
	 Tuple(float, float, float, float);
	 float x, y, z, w;
	 Tuple operator+(const Tuple&);
	 Tuple operator-(const Tuple&);
 friend std::ostream& operator<<(std::ostream&, const Tuple&);
};


Tuple Point(float, float, float);
Tuple Vector(float, float, float);
