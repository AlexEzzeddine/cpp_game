#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "Point.hpp"
#include <ncurses.h>
#define NUM_BULLETS 100
#define DEATHCOUNTER1 10
#define DEATHCOUNTER2 22

class Entity
{
	private:
		Entity();
	protected:
		Point pos; // current position on the screen
		char const symbol;
		bool display;
		int	deathCounter;
		bool dead;
		
	public:
		Entity(Entity const& entity);
		Entity(Point const pos, char const symbol, bool display);
		Entity& operator=(Entity const& entity);
		~Entity();

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
		bool isDisplayed();

		void show();
		void hide();
		bool isDead();
		void dies();
		int getDeathCount();
};

#endif
