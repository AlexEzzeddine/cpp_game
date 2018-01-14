#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"
//#include "Character.hpp"

class Player : public Entity//, Character
{
	public:
		Player();
		static Point getRandomPlayerStartPos();
};

#endif