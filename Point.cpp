#include "Point.hpp"

Point::Point(): x(0), y(0)
{
	return;
}

Point::Point(Point const& point)
{
	*this = point;
	return;
}

Point::Point(int x, int y): x(x), y(y)
{
	return;
}

Point::~Point()
{
	return;
}

int Point::getX()
{
	return x;
}

int Point::getY()
{
	return y;
}

void Point::setX(int x)
{
	this->x = x;
}

void Point::setY(int y)
{
	this->y = y;
}

void Point::setCoords(int x, int y)
{
	setX(x);
	setY(y);
}

Point& Point::operator=(Point const& point)
{
	this->x = point.x;
	this->y = point.y;
	return *this;
}

bool Point::operator==(Point const& point) const
{
	return (this->x == point.x && this->y == point.y);
}