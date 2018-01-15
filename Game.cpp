#include "Game.hpp"

Game::Game() {
	getmaxyx(stdscr, this->rows, this->cols);
	this->enemies = new Enemy*[MAX_ENEMIES];
	for (int i = 0; i < MAX_ENEMIES; i++)
		this->enemies[i] = new Enemy();
	this->draw();
	std::srand(std::time(0));
	this->finished = false;
	this->fps = 60;
	Bullet::setBoundingRectangle(Rectangle(1, 1, this->cols - 2, this->rows - 3));
	Player::setBoundingRectangle(Rectangle(1, 1, this->cols / 5, this->rows - 3));
	Enemy::setBoundingRectangle(Rectangle(1, 1, this->cols - 2, this->rows - 3));
}

Game::Game(Game const& obj)
{
	*this = obj;
}

Game::~Game()
{
	for(int i = 0; i < MAX_ENEMIES; i++)
		delete enemies[i];
	delete [] enemies;
	return;
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

void Game::draw() {
	clear();
	getmaxyx(stdscr, rows, cols);

	box(stdscr, 0, 0);
	mvprintw(this->rows - 1, 5, "FPS: %d", this->fps); //display frames
	mvprintw(this->rows - 1, 50, "ROWS: %d COLS: %d", rows, cols); //display frames
	this->drawEntities();
	refresh();
}

void    Game::drawEntities() {
	this->player.draw();
	this->player.drawBullets();
	for (int i = 0; i < MAX_ENEMIES; i++)
		if (enemies[i]->isDisplayed())
			enemies[i]->draw();
	//     this->_enemies[i].drawBullets();
}

void    Game::moveEntities() {
	for (int i = 0; i < MAX_ENEMIES; i++) {
		enemies[i]->move();
		//this->_enemies[i].moveBullets();
	}
	this->player.moveBullets((Entity **)enemies, MAX_ENEMIES);
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
			this->player.shoot(player.getPos());
			break;
		case 27: // exit on 'esc' for now
			this->finished = true;
			break;
	}

}

WINDOW*	Game::getWin() const {
	return (this->win);
}

bool	Game::getFinished() const {
	return (this->finished);
}

int		Game::getCols() const {
	return (this->cols);
}

int		Game::getRows() const {
	return (this->rows);
}

int		Game::getFPS() const {
	return (this->fps);
}

Player	Game::getPlayer() const {
	return (this->player);
}
Enemy**	Game::getEnemies() const {
	return (this->enemies);
}

Game&	Game::operator=(Game const & rhs)
{
	this->win = rhs.getWin();
	this->finished = rhs.getFinished();
	this->cols = rhs.getCols();
	this->rows = rhs.getRows();
	this->fps = rhs.getFPS();
	this->player = rhs.getPlayer();
	this->enemies = rhs.getEnemies();
	return (*this);
}
