#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"
#include "Character.hpp"
#define NUM_PLAYER_BULLETS 100
#define NUM_PLAYER_LIVES 3

class Player : public Entity, public Character
{
	private:
		static Rectangle boundingRectangle;
	public:
		Player();
		Player(Player const & p);
		virtual ~Player();

		void moveUp();
		void moveRight();
		void moveDown();
		void moveLeft();
		static Point getStartPos();
		Rectangle	getBoundingRectangle() const;
		static void setBoundingRectangle(Rectangle rectangle);
		void dies();
		void show();
		Player&	operator=(Player const & p);
};

#endif
