#include "EntityRepresentation.hpp"

EntityRepresentation::EntityRepresentation()
{
	return;
}

EntityRepresentation::EntityRepresentation(std::string representation, int width, int height):
	representation(representation), width(width), height(height)
{
	return;
}

EntityRepresentation::EntityRepresentation(EntityRepresentation const& obj)
{
	*this = obj;
}

EntityRepresentation::~EntityRepresentation()
{
	return;
}

EntityRepresentation& EntityRepresentation::operator=(EntityRepresentation const& obj)
{
	this->representation = obj.representation;
	this->width = obj.width;
	this->height = obj.height;
	return *this;
}

char EntityRepresentation::operator()(int row, int col) const
{
	return representation[width * row + col]; 
}

void EntityRepresentation::draw(Point const& pos) const
{
	int x = pos.getX();
	int y = pos.getY();
	draw(x, y);
}

void EntityRepresentation::draw(int x, int y) const
{
	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++)
			mvaddch(y + row, x + col, representation[width * row + col]);
}

int EntityRepresentation::getWidth()
{
	return width;
}

int EntityRepresentation::getHeight()
{
	return height;
}