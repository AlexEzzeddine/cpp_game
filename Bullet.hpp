#ifndef BULLET_HPP
#define BULLET_HPP

#include "Entity.hpp"
#include "Rectangle.hpp"

class Bullet : public Entity
{
	public:
		enum Direction {left, right};

		Bullet(Rectangle& rectangle, Direction direction);
		Bullet(Bullet const & b);
		~Bullet();
		void shoot(Rectangle const& rectangle);
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
		static EntityRepresentation representation;
		Direction const direction;
};
#endif
