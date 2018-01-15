#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Point.hpp"

class Rectangle
{
	private:
		int left;
		int top;
		int width;
		int height;
	public:
		Rectangle();
		Rectangle(int left, int top, int width, int height);
		Rectangle(Point& topLeft, Point& bottomRight);
		Rectangle(Point& topLeft, int width, int height);
		Rectangle(Rectangle const& obj);
		~Rectangle();

		Rectangle& operator=(Rectangle const& obj);

		bool contains(int x, int y);
		bool contains(Point& point);
};

#endif