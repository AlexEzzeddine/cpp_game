#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"
#include "Character.hpp"

class Player : public Entity, public Character
{
	private:
		static Rectangle boundingRectangle;
		static EntityRepresentation representation;
	public:
		Player();
		Player(Player const & p);
		virtual ~Player();

		void moveUp();
		void moveRight();
		void moveDown();
		void moveLeft();
		static Rectangle getStartPos();
		Rectangle	getBoundingRectangle() const;
		static void setBoundingRectangle(Rectangle rectangle);
		Player&	operator=(Player const & p);
};

#endif
