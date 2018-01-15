#include "Entity.hpp"

Entity::Entity(Point const pos, char const symbol, bool display):
	pos(pos), symbol(symbol), display(display)
{
	return;
}

Entity::Entity(Entity const& entity):
	pos(entity.pos), symbol(entity.symbol), display(entity.display)
{
	return;
}

Entity& Entity::operator=(Entity const& entity)
{
	this->pos = entity.pos;
	this->display = entity.display;
	return *this;
}

// moves Entity to absolute position on the screen
void Entity::move(int x, int y)
{
	pos.setCoords(x, y);
}

// moves Entity to absolute position on the screen
void Entity::move(Point const& point)
{
	pos = point;
}

// moves Entity one position up
void Entity::moveUp()
{
	move(pos.getX(), pos.getY() - 1);
}

// moves Entity one position right
void Entity::moveRight()
{
	move(pos.getX() + 1, pos.getY());
}

// moves Entity one position down
void Entity::moveDown()
{
	move(pos.getX(), pos.getY() + 1);
}

// moves Entity one position left
void Entity::moveLeft()
{
	move(pos.getX() - 1, pos.getY());
}

// retrieves current position
Point const& Entity::getPos() const
{
	return pos;
}

//draws entity on the screen at current position (maybe move this method to other class?)
void Entity::draw()
{
	if (this->display)
		mvprintw(pos.getY(), pos.getX(), "%c", symbol); //show Entity character on the screen
}

// checks if this entity collides with other entity
bool Entity::checkCollision(Entity const& entity) const
{
	return this->pos == entity.pos;
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