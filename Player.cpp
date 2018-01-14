#include "Player.hpp"

Player::Player():
	Entity(Player::getRandomPlayerStartPos(), '>')
{
	getmaxyx(stdscr, rows, cols);
	return;
}

Point Player::getRandomPlayerStartPos()
{
	int rows, cols;
	getmaxyx(stdscr, rows, cols);
	int x = cols / 10;
	int y = rows / 2;
	Point pos(x, y);
	return pos;
}