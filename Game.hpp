#ifndef GAME_HPP
#define GAME_HPP
#include <ncurses.h>
#include <ctime>
#include <cstdlib>
#include <string>
#define FRAMES_PER_SECOND 60
#define CLOCKS_PER_FRAME (CLOCKS_PER_SEC / FRAMES_PER_SECOND)
#define MAX_ENEMIES 10

class Game
{
    private:
        WINDOW*     _win;
        bool        _finished;
        int         _maxHei;
        int         _maxWid;
        int         _fps;
        // Player       _p1;
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
        void    startLoop();
        void    draw();
        void    handleKeyPress(int c);
};

#endif