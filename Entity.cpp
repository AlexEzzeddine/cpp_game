#include "Entity.hpp"

Entity::Entity(Point const pos, char const symbol, bool display):
	pos(pos), symbol(symbol), display(display), deathCounter(0), dead(false)
{
	this->deathCounter = 0; ////////////////
	return;
}

Entity::Entity(Entity const& entity):
	pos(entity.pos), symbol(entity.symbol), display(entity.display), deathCounter(0), dead(false)
{
	this->deathCounter = 0; //////////////////
	return;
}

Entity& Entity::operator=(Entity const& entity)
{
	this->pos = entity.pos;
	this->display = entity.display;
	return *this;
}

Entity::~Entity()
{
}

// moves Entity to absolute position on the screen
void Entity::move(int x, int y)
{
	pos.setCoords(x, y);
}

// moves Entity to absolute position on the screen
void Entity::move(Point const& point)
{
	pos = point;
}

// moves Entity one position up
void Entity::moveUp()
{
	move(pos.getX(), pos.getY() - 1);
}

// moves Entity one position right
void Entity::moveRight()
{
	move(pos.getX() + 1, pos.getY());
}

// moves Entity one position down
void Entity::moveDown()
{
	move(pos.getX(), pos.getY() + 1);
}

// moves Entity one position left
void Entity::moveLeft()
{
	move(pos.getX() - 1, pos.getY());
}

// retrieves current position
Point const& Entity::getPos() const
{
	return pos;
}

//draws entity on the screen at current position (maybe move this method to other class?)
void Entity::draw()
{
	if (this->display) {
		int y = this->pos.getY();
		int x = this->pos.getX();
		if (!this->dead)
			mvprintw(y, x, "%c", symbol); //show Entity character on the screen
		else {
			if (deathCounter < DEATHCOUNTER1) {
				deathCounter++;
				mvprintw(y-1, x-1, "*");
				mvprintw(y-1, x+1, "*");
				mvprintw(y+1, x-1, "*");
				mvprintw(y+1, x+1, "*");
			}
			else if (deathCounter < DEATHCOUNTER2) {
				deathCounter++;
				mvprintw(y-2, x-2, "*");
				mvprintw(y-2, x+2, "*");
				mvprintw(y+2, x-2, "*");
				mvprintw(y+2, x+2, "*");
			}
			else {
				this->display = false;
			}
		}
	}
}

// checks if this entity collides with other entity
bool Entity::checkCollision(Entity const& entity) const
{
	return this->pos == entity.pos;
}

bool Entity::isDisplayed()
{
	return display;
}

void Entity::show()
{
	this->dead = false;
	display = true;
}

void Entity::hide()
{
	display = false;
}

void Entity::dies()
{
	this->dead = true;
}

bool Entity::isDead()
{
	return (this->dead);
}

int Entity::getDeathCount()
{
	return (this->deathCounter);
}