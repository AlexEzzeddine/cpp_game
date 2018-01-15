#include "Bullet.hpp"

Rectangle Bullet::boundingRectangle;

Bullet::Bullet(Point& startPos, Direction direction):
	Entity(startPos, '-', false), direction(direction)
{
	return;
}

Bullet::Bullet(Bullet const & b) : Entity(b), direction(b.getDirection())
{
	*this = b;
}

Bullet::~Bullet()
{
}

Bullet *Bullet::getNextAvailableBullet(Bullet **bullets, int size)
{
	for(int i = 0; i < size; i++)
	{
		if (!bullets[i]->display)
			return bullets[i];
	}
	return NULL;
}

void Bullet::shoot(Point const& pos)
{
	this->pos = pos;
	display = true;
	moveForward();
}

void Bullet::moveForward()
{
	if (direction == left)
		moveLeft();
	if (direction == right)
		moveRight();
}

void Bullet::moveRight()
{
	if (boundingRectangle.contains(pos.getX() + 1, pos.getY()))
		Entity::moveRight();
	else
		display = false;
}

void Bullet::moveLeft()
{
	if (boundingRectangle.contains(pos.getX() - 1, pos.getY()))
		Entity::moveLeft();
	else
		display = false;
}

Bullet::Direction	Bullet::getDirection() const
{
	return (this->direction);
}

Rectangle	Bullet::getBoundingRectangle() const
{
	return (this->boundingRectangle);
}

void Bullet::setBoundingRectangle(Rectangle rectangle)
{
	boundingRectangle = rectangle;
}

Bullet&		Bullet::operator=(Bullet const & b)
{
	this->pos = b.pos;
	this->display = b.display;
	this->deathCounter = b.deathCounter;
	this->dead = b.dead;
	return (*this);
}
