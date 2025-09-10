#pragma once
#include <string>
#include "color.h"
#include"tuple.h"

namespace qprt
{
	class Canvas
	{
	 public:
		Canvas(int, int);
		int width, height;
		Color pixel_at(int, int);
		Tuple Center();
		void write_pixel(Color, int, int);
		void write_to_file(std::string);
	 private:
		Color* pixels;
	};
}
