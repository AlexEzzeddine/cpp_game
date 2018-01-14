#include "Game.hpp"

Game::Game() {
	getmaxyx(stdscr, this->rows, this->cols);
	this->draw();

	std::srand(std::time(0));
	this->finished = false;
	this->fps = 60;
}

Game::Game(Game const& obj)
{
	*this = obj;
}

Game::~Game()
{
	return;
}

void Game::draw() {
	clear();
	getmaxyx(stdscr, cols, rows);

	box(stdscr, 0, 0);
	mvprintw(this->rows, 5, "FPS: %d", this->fps); //display frames
	this->drawEntities();
	refresh();
}

void Game::start()
{
	int c;
	int frames = 0;
	clock_t before = 0;
	clock_t now;

	while (!this->finished)
	{
		// HANDLE KEYPRESS
		if ((c = getch()) != ERR)
			this->handleKeyPress(c);
		// UPDATE POSITIONS
		this->moveEntities();
		// DRAW
		this->draw();

		// CALCULATE FPS
		now = clock();
		frames++;
		if (((now - before) / CLOCKS_PER_SEC) == 1)
		{
			before = now;
			this->fps = frames;
			frames = 0;
		}


		// WAIT FOR REST OF 1/60th OF SECOND
		while(clock() / CLOCKS_PER_FRAME == now / CLOCKS_PER_FRAME) {}
	}
}

void    Game::drawEntities() {
	this->player.draw();
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
			this->player.moveLeft();
			break;
		case KEY_RIGHT:
			this->player.moveRight();
			break;
		case KEY_UP:
			this->player.moveUp();
			break;
		case KEY_DOWN:
			this->player.moveDown();
			break;
		case ' ': // 'z'
			//this->_player.shoot();
			break;
		case 27: // exit on 'esc' for now
			this->finished = true;
			break;
	}

}