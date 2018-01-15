#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Point.hpp"

class Rectangle
{
	private:
	public:
		int left;
		int top;
		int width;
		int height;
		Rectangle();
		Rectangle(int left, int top, int width, int height);
		Rectangle(Point& topLeft, Point& bottomRight);
		Rectangle(Point& topLeft, int width, int height);
		Rectangle(Rectangle const& obj);
		~Rectangle();

		Rectangle& operator=(Rectangle const& obj);

		bool contains(int x, int y);
		bool contains(Point& point);
		bool contains(Rectangle& rectangle);

		Rectangle translate(int x, int y);
		void setCoords(int x, int y);
		void setCoords(Point const& point);
		bool overlaps(Rectangle const& rectangle) const;
};

#endif