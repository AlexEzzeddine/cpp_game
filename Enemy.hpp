#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "Entity.hpp"
#include "Character.hpp"

class Enemy : public Entity, Character
{
	public:
		Enemy();
};

#endif