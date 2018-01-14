#ifndef ENEMY_HPP
#define ENEMY_HPP

class Enemy : public Entity, Character
{
	public:
		Enemy();
		static Point& getRandomPlayerStartPos();
};

#endif