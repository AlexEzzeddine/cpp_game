#include "Game.hpp"

Game::Game() {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    this->_win = initscr();
    this->_win = subwin(stdscr, WIN_HEI, WIN_WID, 0, 0);
    this->draw();

    std::srand(std::time(0));
    this->_finished = false;
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
    int y = 1;

    wborder(this->_win, '|', '|', '-', '-', 0, 0, 0, 0);
    for (int i = 1; i < WIN_HEI - 1; i++) {
        mvaddch(y++, RIGHT_WIN_WID, '|');
    }
}

void    Game::startLoop() {
    int c;
    int fps = 0;
    clock_t before = 0;
    clock_t now;

    while (!this->_finished) {
        // CALCULATE FPS
        now = clock();
        fps++;
        if (((now - before) / CLOCKS_PER_SEC) == 1) {
            before = now;
            mvprintw(2, RIGHT_WIN_WID + 4, "FPS: %d", fps); //display fps
            fps = 0;
        }

        // DRAW
        // this->drawEntities();
        // this->moveEntities();
        wrefresh(this->_win);
        
        // HANDLE KEYPRESS
        c = getch();
        this->handleKeyPress(c);

        // WAIT FOR REST OF 1/60th OF SECONDd
        while(clock() / CLOCKS_PER_FRAME == now / CLOCKS_PER_FRAME) {}
    }
}

void    Game::drawEntities() {
    // this->_p1->draw();
    // this->_p1->drawBullets();
    // for (int i = 0; i < MAX_ENEMIES; i++) {
    //     this->_enemies[i].draw();
    //     this->_enemies[i].drawBullets();
    // }
}

void    Game::moveEntities() {
    // this->_p1->moveBullets();
    // for (int i = 0; i < MAX_ENEMIES; i++) {
    //     this->_enemies[i].move();
    //     this->_enemies[i].moveBullets();
    // }
}

void    Game::handleKeyPress(int c) {
    switch(c) {
        case KEY_LEFT:
            // this->_p1->moveLeft();
            break;
        case KEY_RIGHT:
            // this->_p1->moveRight();
            break;
        case KEY_UP:
            // this->_p1->moveUp();
            break;
        case KEY_DOWN:
            // this->_p1->moveDown();
            break;
        case 90: // 'z'
            // this->_p1->shoot();
            break;
        case 27: // exit on 'esc' for now
            this->_finished = true;
            break;
    }

}