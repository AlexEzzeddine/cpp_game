#include "Entity.hpp"

Entity::Entity(Point const& pos, char const symbol);

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
	move(pos.x, pos.y + 1)
}


// moves Entity one position right
void Entity::moveRight()
{
	move(pos.x + 1, pos.y)
}


// moves Entity one position down
void Entity::moveDown()
{
	move(pos.x, pos.y - 1)
}


// moves Entity one position left
void Entity::moveLeft()
{
	move(pos.x - 1, pos.y)
}


// retrieves current position
Point& Entity::getPos() const
{
	return pos;
}

//draws entity on the screen at current position (maybe move this method to other class?)
void Entity::draw()
{
    mvprintw(y, x, "%c", symbol); //show Entity character on the screen
}


// checks if this entity collides with other entity
bool Entity::checkCollision(Entity const& entity) const
{
	return this->pos == entity.pos;
}

