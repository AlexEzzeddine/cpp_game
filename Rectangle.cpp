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

bool Rectangle::contains(Rectangle& rectangle)
{
	if(this->left <= rectangle.left
		&& this->top <= rectangle.top
		&& this->left + this->width >= rectangle.left + rectangle.width
		&& this->top + this->height >= rectangle.top + rectangle.height)
		return true;
	return false;
}

bool Rectangle::overlaps(Rectangle const& rectangle) const
{
	if (this->left > rectangle.left + rectangle.width || rectangle.left > this->left + this->width)
		return false;

	if (this->top > rectangle.top + rectangle.height || rectangle.top > this->top + this->height)
		return false;
 
	return true;
}

Rectangle Rectangle::translate(int x, int y)
{
	return Rectangle(this->left + x, this->top + y, this->width, this->height);
}

void Rectangle::setCoords(int x, int y)
{
	left = x;
	top = y;
}

void Rectangle::setCoords(Point const& point)
{
	left = point.getX();
	top = point.getY();
}