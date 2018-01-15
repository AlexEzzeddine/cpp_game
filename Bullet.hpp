#ifndef BULLET_HPP
#define BULLET_HPP

#include "Entity.hpp"
#include "Rectangle.hpp"

class Bullet : public Entity
{
	public:
		enum Direction {left, right};

		Bullet(Point& startPos, Direction direction);
		Bullet(Bullet const & b);
		~Bullet();
		void shoot(Point const& pos);
		void moveForward();
		void moveRight();
		void moveLeft();
		Direction	getDirection() const;
		static Bullet *getNextAvailableBullet(Bullet **bullets, int size);
		Rectangle	getBoundingRectangle() const;
		static void setBoundingRectangle(Rectangle rectangle);
		Bullet&		operator=(Bullet const & b);
	private:
		Bullet();
		static Rectangle boundingRectangle;
		Direction const direction;
};
#endif
