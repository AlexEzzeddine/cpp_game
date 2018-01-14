#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Bullets.hpp"

#define MAX_BULLETS 10

class Character
{
	private:
		Bullets bullets[MAX_BULLETS];
	public:
		Character();
		void shoot();
		void updateBulletsState();
};

#endif