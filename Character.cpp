#include "Character.hpp"

Character::Character()
{
	return;
}

void Character::shoot()
{
	return;
}

void Character::updateBulletsState()
{
	for(int i = 0; i < MAX_BULLETS; i++)
	{
		bullets[i].moveForward();
	}
}