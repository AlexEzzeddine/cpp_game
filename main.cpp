#include "Game.hpp"

int main() 
{
	initscr();
    cbreak();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    
    // start_color();
	// init_pair(1, COLOR_RED, COLOR_BLACK);
	// init_pair(2, COLOR_GREEN, COLOR_BLACK);
	// init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	// init_pair(4, COLOR_BLUE, COLOR_BLACK);
	// init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	// init_pair(6, COLOR_CYAN, COLOR_BLACK);
    // init_pair(7, COLOR_WHITE, COLOR_BLACK);
    Game g;
    g.start();
    
	endwin();

    return 0;
}