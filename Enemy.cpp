#include "Enemy.hpp"

Rectangle Enemy::boundingRectangle;

EntityRepresentation Enemy::representation("x", 1, 1);

Enemy::Enemy():
	Entity(Enemy::getStartPos(), representation, false), Character(NUM_ENEMY_LIVES, NUM_ENEMY_BULLETS, rectangle, Bullet::left)
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

void Enemy::dies()
{
	this->dead = true;
}

void Enemy::show()
{
	this->deathCounter = 0;
	this->dead = false;
	display = true;
	rectangle = Enemy::getStartPos();
}

void Enemy::chargeShot() {
	this->shotCharge++;
	if (this->shotCharge == this->nextShot) {
		this->shoot(rectangle);
		this->nextShot = rand() % 100 + 100;
		this->shotCharge = 0;
	}
}

Enemy&	Enemy::operator=(Enemy const & e)
{
	this->boundingRectangle = e.getBoundingRectangle();
	this->rectangle = e.getRectangle();
	this->display = e.display;
	this->shotCharge = e.shotCharge;
	this->nextShot = e.nextShot;
	this->moveTimer = e.moveTimer;
	this->deathCounter = e.deathCounter;
	this->dead = e.dead;
	this->lives = e.lives;
	this->numberOfBullets = e.numberOfBullets;
	return (*this);
}