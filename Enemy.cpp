#include "Enemy.hpp"

Rectangle Enemy::boundingRectangle;

Enemy::Enemy():
	Entity(Enemy::getStartPos(), 'x', true), Character(3, pos, Bullet::left)
{
	return;
}

Enemy::Enemy(Enemy const & e) : Entity(e), Character(e)
{
	*this = e;
}

Enemy::~Enemy()
{
	return;
}

Point Enemy::getStartPos()
{
	int rows, cols;
	getmaxyx(stdscr, rows, cols);
	int x = cols - 2;
	int y = rand() % rows;
	Point pos(x, y);
	return pos;
}

Rectangle	Enemy::getBoundingRectangle() const
{
	return (this->boundingRectangle);
}

void Enemy::setBoundingRectangle(Rectangle rectangle)
{
	boundingRectangle = rectangle;
}

void Enemy::move()
{
	Enemy::Direction direction = (Direction)(rand() % 4);
	if (direction == up)
		moveUp();
	else if (direction == down)
		moveDown();
	else
		moveLeft();
}

void Enemy::moveUp()
{
	if (boundingRectangle.contains(pos.getX(), pos.getY() - 1))
		Entity::moveUp();
	else
		Entity::moveDown();
}

void Enemy::moveDown()
{
	if (boundingRectangle.contains(pos.getX(), pos.getY() + 1))
		Entity::moveDown();
	else
		Entity::moveUp();
}

void Enemy::moveLeft()
{
	if (boundingRectangle.contains(pos.getX() - 1, pos.getY()))
		Entity::moveLeft();
	else
		pos = Enemy::getStartPos();
}

Enemy&	Enemy::operator=(Enemy const & e)
{
	this->boundingRectangle = e.getBoundingRectangle();
	this->pos = e.getPos();
	this->display = e.display;
	return (*this);
}
