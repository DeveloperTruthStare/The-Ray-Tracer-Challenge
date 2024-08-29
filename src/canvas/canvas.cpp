#include <fstream>
#include <string>
#include <sstream>
#include "canvas.h"
#include "../color/color.h"

qprt::Canvas::Canvas(int width, int height)
{
	this->width = width;
	this->height = height;
	this->pixels = new Color[width * height];
}

namespace qprt
{

	Color Canvas::pixel_at(int x, int y)
	{
		return pixels[y * this->width + x];
	}

	void Canvas::write_pixel(Color color, int x, int y)
	{
		this->pixels[y * this->width + x] = color;
	}
	void check_new_line(std::ofstream &file, std::stringstream& ss, std::string text)
	{
		if (ss.str().size() + text.size() >= 70)
		{
			file << ss.str() << "\n";
			ss.str("");
			ss.clear();
		}
		else
		{
			ss << " ";
		}
		ss << text;
	}
	void Canvas::write_to_file(std::string filename)
	{
		std::ofstream file(filename);
		if(!file.is_open()) {
			std::cout << "Error opening file\n";
		}
		file << "P3\n" << this->width << " " << this->height << "\n255\n";
		
		std::stringstream ss;
		ss.str("");
		ss.clear();
	
		for(int y = 0; y < this->height; ++y)
		{

			Color* pixel = &this->pixels[y * this->width];
			
			int redValue = (int)(pixel->red  * 255);
			std::string redStr = std::to_string(redValue);

			int greenValue = (int)(pixel->green * 255);
			std::string greenStr = std::to_string(greenValue);

			int blueValue = (int)(pixel->blue * 255);
			std::string blueStr = std::to_string(blueValue);
			
			ss << redStr << " " << greenStr << " " << blueStr;

			for(int x = 1; x < this->width; ++x)
			{
				Color* pixel = &this->pixels[y * this->width + x];
				
				int redValue = (int)(pixel->red  * 255);
				std::string redStr = std::to_string(redValue);
				check_new_line(file, ss, redStr);

				int greenValue = (int)(pixel->green * 255);
				std::string greenStr = std::to_string(greenValue);
				check_new_line(file, ss, greenStr);

				int blueValue = (int)(pixel->blue * 255);
				std::string blueStr = std::to_string(blueValue);
				check_new_line(file, ss, blueStr);
			}
			file << ss.str();
			ss.str("");
			ss.clear();
			file << "\n";
		}
		file << ss.str() << "\n";

		file.close();
	}
}
