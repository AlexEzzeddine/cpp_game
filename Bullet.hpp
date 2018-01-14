#ifndef BULLET_HPP
#define BULLET_HPP

#include "Entity.hpp"
#include "Rectangle.hpp"

class Bullet : public Entity
{
	public:
		enum Direction {left, right};

		Bullet(Point& startPos, Direction direction);
		void shoot(Point const& pos);
		void moveForward();
		void moveRight();
		void moveLeft();
		static Bullet *getNextAvailableBullet(Bullet **bullets, int size);
		static void setBoundingRectangle(Rectangle rectangle);
	private:
		Bullet();
		static Rectangle boundingRectangle;
		Direction const direction;
};
#endif
