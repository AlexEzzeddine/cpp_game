#include "Player.hpp"

Rectangle Player::boundingRectangle;

Player::Player():
	Entity(Player::getStartPos(), '>', true), Character(NUM_PLAYER_LIVES, NUM_PLAYER_BULLETS, pos, Bullet::right)
{
	this->dead = false;
	return;
}

Player::Player(Player const & p) : Entity(p), Character(p)
{
	*this = p;
}

Player::~Player()
{
	return;
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

void Player::dies() {
	this->decreaseLives();
	this->dead = true;
}

void Player::show() {
	this->dead = false;
	this->deathCounter = 0;
	this->move(Player::getStartPos());
	this->display = true;
}

Player&	Player::operator=(Player const & p)
{
	this->pos = p.pos;
	this->boundingRectangle = p.getBoundingRectangle();
	this->display = p.display;
	this->deathCounter = p.deathCounter;
	this->dead = p.dead;
	this->lives = p.lives;
	this->numberOfBullets = p.numberOfBullets;
	return (*this);
}