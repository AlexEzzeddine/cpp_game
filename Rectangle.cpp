#include "Rectangle.hpp"

Rectangle::Rectangle()
{
	return;
}

Rectangle::Rectangle(Rectangle const& obj)
{
	*this = obj;
	return;
}

Rectangle::Rectangle(int left, int top, int width, int height):
	left(left), top(top), width(width), height(height)
{
	return;
}

Rectangle::Rectangle(Point& topLeft, Point& bottomRight):
	left(topLeft.getX()), top(topLeft.getY()),
	width(bottomRight.getX() - left), height(bottomRight.getY() - top)
{
	return;
}

Rectangle::Rectangle(Point& topLeft, int width, int height):
	left(topLeft.getX()), top(topLeft.getY()),
	width(width), height(height)
{
	return;
}

Rectangle::~Rectangle()
{
	return;
}

Rectangle& Rectangle::operator=(Rectangle const& obj)
{
	this->left = obj.left;
	this->top = obj.top;
	this->width = obj.width;
	this->height = obj.height;
	return *this;
}

bool Rectangle::contains(int x, int y)
{
	if (x >= left && x <= left + width
		&& y >= top && y <= top + height)
		return true;
	return false;
}

bool Rectangle::contains(Point& point)
{
	int x = point.getX();
	int y = point.getY();
	return contains(x, y);
}