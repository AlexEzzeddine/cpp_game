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
		Character(Character const & c);
		virtual ~Character();

		void drawBullets();
		void shoot(Point const& pos);
		void moveBullets(Entity **enemies, int n);
		Bullet	**getBullets() const;
		int	getNumBullets() const;

		int getLives();
		void setLives(int n);
		void decreaseLives();
		void increaseLives();
		
		Character&	operator=(Character const & c);
};

#endif
