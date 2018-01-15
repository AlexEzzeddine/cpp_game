#include "Entity.hpp"

Entity::Entity(Rectangle rectangle, EntityRepresentation const& representation, bool display):
	rectangle(rectangle), representation(representation), display(display)
{
	return;
}

Entity::Entity(Entity const& entity):
	rectangle(entity.rectangle), representation(entity.representation), display(entity.display)
{
	return;
}

Entity& Entity::operator=(Entity const& entity)
{
	this->rectangle = entity.rectangle;
	this->display = entity.display;
	return *this;
}

Entity::~Entity()
{
	return;
}

// moves Entity to absolute position on the screen
void Entity::move(int x, int y)
{
	rectangle.setCoords(x, y);
}

// moves Entity to absolute position on the screen
void Entity::move(Point const& point)
{
	rectangle.setCoords(point);
}

// moves Entity one position up
void Entity::moveUp()
{
	move(rectangle.left, rectangle.top - 1);
}

// moves Entity one position right
void Entity::moveRight()
{
	move(rectangle.left + 1, rectangle.top);
}

// moves Entity one position down
void Entity::moveDown()
{
	move(rectangle.left, rectangle.top + 1);
}

// moves Entity one position left
void Entity::moveLeft()
{
	move(rectangle.left - 1, rectangle.top);
}

void Entity::setRectangle(Rectangle& rectangle)
{
	this->rectangle = rectangle;
}

Rectangle const& Entity::getRectangle() const // retrieves current position
{
	return rectangle;
}

//draws entity on the screen at current position (maybe move this method to other class?)
void Entity::draw()
{
	if (this->display)
		representation.draw(rectangle.left, rectangle.top);
}

// checks if this entity collides with other entity
bool Entity::checkCollision(Entity const& entity) const
{
	return rectangle.overlaps(entity.getRectangle());
}

bool Entity::isDisplayed()
{
	return display;
}

void Entity::show()
{
	display = true;
}

void Entity::hide()
{
	display = false;
}
