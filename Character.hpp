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
		Character(Character const & c);
		virtual ~Character();
		void drawBullets();
		void shoot(Point const& pos);
		void moveBullets(Entity **enemies, int n);
		Bullet	**getBullets() const;
		int	getNumBullets() const;

		Character&	operator=(Character const & c);
};

#endif
