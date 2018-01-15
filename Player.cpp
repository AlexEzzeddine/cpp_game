#include "Player.hpp"

Rectangle Player::boundingRectangle;

EntityRepresentation Player::representation(">>>", 3, 1);

Player::Player():
	Entity(Player::getStartPos(), representation, true), Character(NUM_PLAYER_LIVES, NUM_BULLETS, rectangle, Bullet::right)
{
	this->dead = false;
	return;
}

Player::Player(Player const& p) : Entity(p), Character(p)
{
	*this = p;
}

Player::~Player()
{
	return;
}

Rectangle Player::getStartPos()
{
	int rows, cols;
	getmaxyx(stdscr, rows, cols);
	int x = cols / 10;
	int y = rows / 2 - representation.getHeight() / 2;
	Rectangle rectangle(x, y, representation.getWidth(), representation.getHeight());
	return rectangle;
}

void Player::moveUp()
{
	Rectangle newRect = rectangle.translate(0, -1);
	if (boundingRectangle.contains(newRect))
		Entity::moveUp();
}

void Player::moveRight()
{
	Rectangle newRect = rectangle.translate(1, 0);
	if (boundingRectangle.contains(newRect))
		Entity::moveRight();
}

void Player::moveDown()
{
	Rectangle newRect = rectangle.translate(0, 1);
	if (boundingRectangle.contains(newRect))
		Entity::moveDown();
}

void Player::moveLeft()
{
	Rectangle newRect = rectangle.translate(-1, 0);
	if (boundingRectangle.contains(newRect))
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
	Rectangle newPlayerPosition = Player::getStartPos();
	this->rectangle = newPlayerPosition;
	this->display = true;
}

Player&	Player::operator=(Player const & p)
{
	this->boundingRectangle = p.getBoundingRectangle();
	this->rectangle = p.getRectangle();
	this->display = p.display;
	this->deathCounter = p.deathCounter;
	this->dead = p.dead;
	this->lives = p.lives;
	this->numberOfBullets = p.numberOfBullets;
	return (*this);
}