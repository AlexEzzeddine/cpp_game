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
		Enemy(Enemy const & e);
		Enemy& operator=(Enemy const & e);
		~Enemy();
		void move();
		void moveUp();
		void moveDown();
		void moveLeft();
		static Point getStartPos();
		Rectangle	getBoundingRectangle() const;
		static void setBoundingRectangle(Rectangle rectangle);
		void destroy();

};

#endif
