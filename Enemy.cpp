#include "Enemy.hpp"

Rectangle Enemy::boundingRectangle;

Enemy::Enemy():
	Entity(Enemy::getStartPos(), 'x', false), Character(1, 3, pos, Bullet::left)
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
		this->hide();
}

void Enemy::hide()
{
	display = false;
	pos = Enemy::getStartPos();
}
