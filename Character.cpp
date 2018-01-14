#include "Character.hpp"

Character::Character()
{
	return;
}

Character::~Character()
{
	for(int i = 0; i < numberOfBullets; i++)
		delete bullets[i];
	delete [] bullets;
	return;
}

Character::Character(int numberOfBullets, Point& startPos, Bullet::Direction direction):
	numberOfBullets(numberOfBullets)
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
	for (int i = 0; i < numberOfBullets; i++)
		if (bullets[i]->isDisplayed())
		{
			for (int j = 0; j < n && bullets[i]->isDisplayed(); j++)
				if(enemies[j]->isDisplayed() && bullets[i]->checkCollision(*(enemies[j])))
				{
					enemies[j]->hide();
					bullets[i]->hide();
				}
			bullets[i]->moveForward();
		}
}

void Character::drawBullets()
{
	for (int i = 0; i < numberOfBullets; i++)
		if (bullets[i]->isDisplayed())
			bullets[i]->draw();
}
