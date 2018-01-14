#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "Point.hpp"
#include <ncurses.h>

class Entity
{
	private:
		Entity();
	protected:
		Point pos; // current position on the screen
		char const symbol;
		Point topLeftCorner;
		Point bottomRightCorner;
	public:
		Entity(Entity const& entity);
		Entity(Point const& pos, char const symbol);

		Entity& operator=(Entity const& entity);

		void move(int x, int y); // moves Entity to absolute position on the screen
		void move(Point const& point); // moves Entity to absolute position on the screen
		void moveUp(); // moves Entity one position up
		void moveRight(); // moves Entity one position right
		void moveDown(); // moves Entity one position down
		void moveLeft(); // moves Entity one position left

		Point const& getPos() const; // retrieves current position
		void setPos(Point const& point); // sets current position

		void draw(); //draws entity on the screen at current position (maybe move this method to other class?)

		bool checkCollision(Entity const& entity) const; // checks if this entity collides with other entity
};

#endif