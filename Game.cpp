#include "Game.hpp"

Game::Game() {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    this->_win = initscr();
    // this->_win = subwin(stdscr, WIN_HEI, WIN_WID, 0, 0);
    getmaxyx(this->_win, this->_maxHei, this->_maxWid);
    this->draw();

    std::srand(std::time(0));
    this->_finished = false;
    this->_fps = 60;
    this->startLoop();
}

Game::Game(Game const & src) {
    *this = src;
}

Game::~Game() {
    delwin(this->_win);
    endwin();
}

// Game & Game::operator=(Game const & rhs) {
//     // not sure what to do here
// }

void    Game::draw() {
    clear();
    getmaxyx(this->_win, this->_maxHei, this->_maxWid);
    int x = 1;

    wborder(this->_win, '|', '|', '-', '-', 0, 0, 0, 0);
    for (int i = 1; i < this->_maxWid - 1; i++) {
        mvaddch(this->_maxHei - this->_maxHei / 5, x++, '-');
    }
    mvprintw(this->_maxHei - 5, 5, "FPS: %d", this->_fps); //display frames
    // this->drawEntities();
    // this->moveEntities();
    wrefresh(this->_win);
}

void    Game::startLoop() {
    int c;
    int frames = 0;
    clock_t before = 0;
    clock_t now;

    while (!this->_finished) {
        // DRAW
        this->draw();

        // CALCULATE FPS
        now = clock();
        frames++;
        if (((now - before) / CLOCKS_PER_SEC) == 1) {
            before = now;
            this->_fps = frames;
            frames = 0;
        }
        
        // HANDLE KEYPRESS
        c = getch();
        this->handleKeyPress(c);

        // WAIT FOR REST OF 1/60th OF SECOND
        while(clock() / CLOCKS_PER_FRAME == now / CLOCKS_PER_FRAME) {}
    }
}

void    Game::drawEntities() {
    // this->_p1.draw();
    // this->_p1.drawBullets();
    // for (int i = 0; i < MAX_ENEMIES; i++) {
    //     this->_enemies[i].draw();
    //     this->_enemies[i].drawBullets();
    // }
}

void    Game::moveEntities() {
    // this->_p1.moveBullets();
    // for (int i = 0; i < MAX_ENEMIES; i++) {
    //     this->_enemies[i].move();
    //     this->_enemies[i].moveBullets();
    // }
}

void    Game::handleKeyPress(int c) {
    switch(c) {
        case KEY_LEFT:
            // this->_p1.moveLeft();
            break;
        case KEY_RIGHT:
            // this->_p1.moveRight();
            break;
        case KEY_UP:
            // this->_p1.moveUp();
            break;
        case KEY_DOWN:
            // this->_p1.moveDown();
            break;
        case 90: // 'z'
            // this->_p1.shoot();
            break;
        case 27: // exit on 'esc' for now
            this->_finished = true;
            break;
    }

}