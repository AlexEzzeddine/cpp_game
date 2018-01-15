#include "Bullet.hpp"

Rectangle Bullet::boundingRectangle;

EntityRepresentation Bullet::representation("-", 1, 1);

Bullet::Bullet(Rectangle &rectangle, Direction direction):
	Entity(rectangle, representation, false), direction(direction)
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

void Bullet::shoot(Rectangle const& rectangle)
{
	if (direction == left)
		this->rectangle = Rectangle(rectangle.left - 1, rectangle.top + rectangle.height / 2, 1, 1);
	else
		this->rectangle = Rectangle(rectangle.left + rectangle.width + 1, rectangle.top + rectangle.height / 2, 1, 1);
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
	Rectangle newRect = rectangle.translate(1,0);
	if (boundingRectangle.contains(newRect))
		Entity::moveRight();
	else
		display = false;
}

void Bullet::moveLeft()
{
	Rectangle newRect = rectangle.translate(1,0);
	if (boundingRectangle.contains(newRect))
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
	(Entity&)(*this) = (Entity&)b;
	return (*this);
}
