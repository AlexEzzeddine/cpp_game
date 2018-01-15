#include "Enemy.hpp"

Rectangle Enemy::boundingRectangle;

EntityRepresentation Enemy::representation("x", 1, 1);

Enemy::Enemy():
	Entity(Enemy::getStartPos(), representation, false), Character(1, 3, rectangle, Bullet::left)
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

Rectangle Enemy::getStartPos()
{
	int rows, cols;
	getmaxyx(stdscr, rows, cols);
	int x = cols - 2;
	int y = rand() % (rows - representation.getHeight() - 2);
	Rectangle rectangle(x, y, representation.getWidth(), representation.getHeight());
	return rectangle;
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
	int n = rand() % 50;
	if (n < 48)
		moveLeft();
	else if (n == 48)
		moveDown();
	else
		moveUp();
}

void Enemy::moveUp()
{
	Rectangle newRect = rectangle.translate(0, -1);
	if (boundingRectangle.contains(newRect))
		Entity::moveUp();
	else
		Entity::moveDown();
}

void Enemy::moveDown()
{
	Rectangle newRect = rectangle.translate(0, 1);
	if (boundingRectangle.contains(newRect))
		Entity::moveDown();
	else
		Entity::moveUp();
}

void Enemy::moveLeft()
{
	Rectangle newRect = rectangle.translate(-1, 0);
	if (boundingRectangle.contains(newRect))
		Entity::moveLeft();
	else
		this->hide();
}

void Enemy::hide()
{
	display = false;
	rectangle = Enemy::getStartPos();
}

Enemy&	Enemy::operator=(Enemy const & e)
{
	this->boundingRectangle = e.getBoundingRectangle();
	this->rectangle = e.getRectangle();
	this->display = e.display;
	return (*this);
}
