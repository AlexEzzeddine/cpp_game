#include "Enemy.hpp"

Enemy::Enemy():
	Entity(Enemy::getRandomPlayerStartPos(), 'X')
{
	return;
}

Point& Enemy::getRandomPlayerStartPos()
{
	int x = 0 // should be random x in right part of the screen
	int y = 0 // should be random y in right part of the screen
	return Point(x, y);
}