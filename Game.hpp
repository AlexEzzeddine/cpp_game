#ifndef GAME_HPP
#define GAME_HPP
#include <ncurses.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include "Player.hpp"
#define FRAMES_PER_SECOND 60
#define CLOCKS_PER_FRAME (CLOCKS_PER_SEC / FRAMES_PER_SECOND)
#define MAX_ENEMIES 10

class Game
{
    private:
        WINDOW*     win;
        bool        finished;
        int         cols;
        int         rows;
        int         fps;
        Player      player;
        // Enemy        _enemies[MAX_ENEMIES];

    public:
        Game();
        Game(Game const & src);
        ~Game();
        // Game & operator=(Game const & rhs);
        void    initScreen();
        void    handleInput(char c);
        void    drawEntities();
        void    moveEntities();
        void    start();
        void    draw();
        void    handleKeyPress(int c);
};

#endif