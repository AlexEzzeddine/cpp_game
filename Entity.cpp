#include "Entity.hpp"

Entity::Entity(Rectangle rectangle, EntityRepresentation const& representation, bool display):
	rectangle(rectangle), representation(representation), display(display), deathCounter(0), dead(false)
{
	return;
}

Entity::Entity(Entity const& entity):
	rectangle(entity.rectangle), representation(entity.representation), display(entity.display), deathCounter(0), dead(false)
{
	return;
}

Entity& Entity::operator=(Entity const& entity)
{
	this->rectangle = entity.rectangle;
	this->display = entity.display;
	this->deathCounter = entity.deathCounter;
	this->dead = entity.dead;
	return *this;
}

Entity::~Entity()
{
	return;
}

// moves Entity to absolute position on the screen
void Entity::move(int x, int y)
{
	rectangle.setCoords(x, y);
}

// moves Entity to absolute position on the screen
void Entity::move(Point const& point)
{
	rectangle.setCoords(point);
}

// moves Entity one position up
void Entity::moveUp()
{
	move(rectangle.left, rectangle.top - 1);
}

// moves Entity one position right
void Entity::moveRight()
{
	move(rectangle.left + 1, rectangle.top);
}

// moves Entity one position down
void Entity::moveDown()
{
	move(rectangle.left, rectangle.top + 1);
}

// moves Entity one position left
void Entity::moveLeft()
{
	move(rectangle.left - 1, rectangle.top);
}

void Entity::setRectangle(Rectangle& rectangle)
{
	this->rectangle = rectangle;
}

Rectangle const& Entity::getRectangle() const // retrieves current position
{
	return rectangle;
}

//draws entity on the screen at current position (maybe move this method to other class?)
void Entity::draw(int color)
{
	(void)color;
	if (this->display) {
		if (!this->dead) {
			// attron(COLOR_PAIR(color));
			representation.draw(rectangle.left, rectangle.top);
			// attroff(COLOR_PAIR(color));
		}
		else {
			int x = rectangle.left;
			int y = rectangle.top;
			if (deathCounter < DEATHCOUNTER1) {
				deathCounter++;
				// attron(COLOR_PAIR(3));
				mvprintw(y-1, x-1, "*");
				mvprintw(y-1, x+1, "*");
				mvprintw(y+1, x-1, "*");
				mvprintw(y+1, x+1, "*");
				// attroff(COLOR_PAIR(3));
			}
			else if (deathCounter < DEATHCOUNTER2) {
				deathCounter++;
				// attron(COLOR_PAIR(3));
				mvprintw(y-2, x-2, "*");
				mvprintw(y-2, x+2, "*");
				mvprintw(y+2, x-2, "*");
				mvprintw(y+2, x+2, "*");
				// attroff(COLOR_PAIR(3));
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
	return rectangle.overlaps(entity.getRectangle());
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