#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "Point.hpp"
#include "Rectangle.hpp"
#include "EntityRepresentation.hpp"

#include <ncurses.h>

#define NUM_BULLETS 100
#define DEATHCOUNTER1 10
#define DEATHCOUNTER2 22
#define PLAYERCOLOR 2
#define ENEMYCOLOR 1

class Entity
{
	private:
		Entity();
	protected:
		Rectangle rectangle; // current position on the screen
		EntityRepresentation const& representation;
		bool display;
		int	deathCounter;
		bool dead;
		
	public:
		Entity(Entity const& entity);
		Entity(Rectangle rectangle, EntityRepresentation const& representation, bool display);
		Entity& operator=(Entity const& entity);
		~Entity();

		void move(int x, int y); // moves Entity to absolute position on the screen
		void move(Point const& point); // moves Entity to absolute position on the screen
		void moveUp(); // moves Entity one position up
		void moveRight(); // moves Entity one position right
		void moveDown(); // moves Entity one position down
		void moveLeft(); // moves Entity one position left

		Rectangle const& getRectangle() const; // retrieves current position
		void setRectangle(Rectangle& rectangle); // sets current position

		void draw(int color); //draws entity on the screen at current position (maybe move this method to other class?)

		bool checkCollision(Entity const& entity) const; // checks if this entity collides with other entity
		bool isDisplayed();

		void show();
		void hide();
		bool isDead();
		void dies();
		int getDeathCount();
};

#endif
