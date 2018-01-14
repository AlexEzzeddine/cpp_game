#include "Game.hpp"

int main() 
{
	initscr();
    cbreak();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    
    Game g;
    g.start();
    
	endwin();

    return 0;
}