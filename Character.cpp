#include "Character.hpp"

Character::Character()
{
	return;
}

Character::Character(Character const & c)
{
	*this = c;
}

Character::~Character()
{
	for(int i = 0; i < numberOfBullets; i++)
		delete bullets[i];
	delete [] bullets;
	return;
}

Character::Character(int lives, int numberOfBullets, Point& startPos, Bullet::Direction direction):
	lives(lives), numberOfBullets(numberOfBullets)
{
	bullets = new Bullet*[numberOfBullets];
	for (int i = 0; i < numberOfBullets; i++)
		bullets[i] = new Bullet(startPos, direction);
}

void Character::shoot(Point const& pos)
{
	Bullet *bullet = Bullet::getNextAvailableBullet(bullets, numberOfBullets);
	if (bullet)
		bullet->shoot(pos);
}

void Character::moveBullets(Entity **enemies, int n)
{
	(void)n;
	(void)enemies;
	for (int i = 0; i < numberOfBullets; i++)
		if (bullets[i]->isDisplayed())
			bullets[i]->moveForward();
}

void Character::drawBullets()
{
	for (int i = 0; i < numberOfBullets; i++)
		if (bullets[i]->isDisplayed())
			bullets[i]->draw();
}

Bullet**	Character::getBullets() const
{
	return (this->bullets);
}

int			Character::getNumBullets() const
{
	return (this->numberOfBullets);
}

int Character::getLives()
{
	return lives;
}

void Character::setLives(int n) {
	this->lives = n;
}

void Character::decreaseLives()
{
	lives--;
}

void Character::increaseLives()
{
	lives++;
}

bool Character::isShooting()
{
	for (int i = 0; i < numberOfBullets; i++)
	{
		if (bullets[i]->isDisplayed())
			return (true);
	}
	return (false);
}

Character&	Character::operator=(Character const & c)
{
	this->bullets = c.getBullets();
	this->numberOfBullets = c.getNumBullets();
	return (*this);
}