#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Bullet.hpp"


class Character
{
	private:
		Bullet **bullets;
		int lives;
		int numberOfBullets;
		Character();
	public:
		Character(int lives, int numberOfBullets, Point& startPos, Bullet::Direction direction);
		virtual ~Character();
		void drawBullets();
		void shoot(Point const& pos);
		void moveBullets(Entity **enemies, int n);
		Bullet** getBullets();
		int	getNumBullets();
		int getLives();
		void decreaseLives();
		void increaseLives();
		// void destroy();
};

#endif