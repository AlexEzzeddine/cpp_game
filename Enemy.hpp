#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <cstdlib>

#include "Entity.hpp"
#include "Character.hpp"

class Enemy : public Entity, public Character
{
	private:
		static Rectangle boundingRectangle;
	public:
		enum Direction {left, right, up, down};
		Enemy();
		void move();
		void moveUp();
		void moveDown();
		void moveLeft();
		static Point getStartPos();
		static void setBoundingRectangle(Rectangle rectangle);
		void destroy();

};

#endif