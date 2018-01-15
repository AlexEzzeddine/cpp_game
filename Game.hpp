#ifndef GAME_HPP
#define GAME_HPP

#include <ncurses.h>
#include <ctime>
#include <cstdlib>
#include <string>

#include "Player.hpp"
#include "Enemy.hpp"

#define FRAMES_PER_SECOND 30
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
        Enemy       **enemies;
        int         time;
        int         timer;
        int         spawnTimer;
        int         spawnTime;

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
        void    checkEnemyCollision();
        void    checkBulletCollision(Bullet & b);
        void    spawnEnemy();
};

#endif