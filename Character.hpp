#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Bullet.hpp"


class Character
{
	private:
		Bullet **bullets;
		int numberOfBullets;
		Character();
	public:
		Character(int numberOfBullets, Point& startPos, Bullet::Direction direction);
		virtual ~Character();
		void drawBullets();
		void shoot(Point const& pos);
		void moveBullets(Entity **enemies, int n);
		Bullet** getBullets();
		int	getNumBullets();
		// void destroy();
};

#endif