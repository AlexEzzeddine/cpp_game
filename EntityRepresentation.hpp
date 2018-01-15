#ifndef ENTITYREPRESENTATION_HPP
#define ENTITYREPRESENTATION_HPP

#include <string>
#include <ncurses.h>

#include "Point.hpp"

class EntityRepresentation
{
	private:
		std::string representation;
		int width;
		int height;
		EntityRepresentation();
	public:
		EntityRepresentation(std::string representation, int width, int height);
		EntityRepresentation(EntityRepresentation const& obj);
		~EntityRepresentation();

		EntityRepresentation& operator=(EntityRepresentation const& obj);
		char operator()(int row, int column) const;

		void draw(Point const& pos) const;
		void draw(int x, int y) const;
		int getWidth();
		int getHeight();
};

#endif