#include "Enemy.hpp"

Rectangle Enemy::boundingRectangle;

Enemy::Enemy():
	Entity(Enemy::getStartPos(), 'x', false), Character(1, 3, pos, Bullet::left)
{
	shotCharge = 0;
	this->nextShot = rand() % 100 + 100;
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
	this->moveTimer++;
	if (this->moveTimer == SPEED) {
		int n = rand() % 50;
		if (n < 48)
			moveLeft();
		else if (n == 48)
			moveDown();
		else
			moveUp();
		this->moveTimer = 0;
	}
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

void Enemy::dies()
{
	this->dead = true;
}

Enemy&	Enemy::operator=(Enemy const & e)
{
	this->boundingRectangle = e.getBoundingRectangle();
	this->pos = e.getPos();
	this->display = e.display;
	this->shotCharge = e.shotCharge;
	this->nextShot = e.nextShot;
	return (*this);
}

void Enemy::show()
{
	this->deathCounter = 0;
	this->dead = false;
	display = true;
	pos = Enemy::getStartPos();
}

void Enemy::chargeShot() {
	this->shotCharge++;
	if (this->shotCharge == this->nextShot) {
		this->shoot(this->getPos());
		this->nextShot = rand() % 100 + 100;
		this->shotCharge = 0;
	}
}