#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"
#include "Character.hpp"

class Player : public Entity, public Character
{
	private:
		static Rectangle boundingRectangle;
	public:
		Player();

		void moveUp();
		void moveRight();
		void moveDown();
		void moveLeft();
		static Point getStartPos();
		static void setBoundingRectangle(Rectangle rectangle);

};

#endif