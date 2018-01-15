#include "Player.hpp"

Rectangle Player::boundingRectangle;

Player::Player():
	Entity(Player::getStartPos(), '>', true), Character(5, NUM_BULLETS, pos, Bullet::right)
{
	return;
}

Player::Player(Player const & p) : Entity(p), Character(p)
{
	*this = p;
}

Point Player::getStartPos()
{
	int rows, cols;
	getmaxyx(stdscr, rows, cols);
	int x = cols / 10;
	int y = rows / 2;
	Point pos(x, y);
	return pos;
}

void Player::moveUp()
{
	if (boundingRectangle.contains(pos.getX(), pos.getY() - 1))
		Entity::moveUp();
}

void Player::moveRight()
{
	if (boundingRectangle.contains(pos.getX() + 1, pos.getY()))
		Entity::moveRight();
}

void Player::moveDown()
{
	if (boundingRectangle.contains(pos.getX(), pos.getY() + 1))
		Entity::moveDown();
}

void Player::moveLeft()
{
	if (boundingRectangle.contains(pos.getX() - 1, pos.getY()))
		Entity::moveLeft();
}

Rectangle	Player::getBoundingRectangle() const
{
	return (this->boundingRectangle);
}

void Player::setBoundingRectangle(Rectangle rectangle)
{
	boundingRectangle = rectangle;
}

Player&	Player::operator=(Player const & p)
{
	this->pos = p.pos;
	this->boundingRectangle = p.getBoundingRectangle();
	this->display = p.display;
	return (*this);
}
