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
	this->time = 0;
	this->spawnTimer = 0;
	this->spawnTime = rand() % 4 + 1;
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
		// ATTEMPT TO SPAWN ENEMY
		this->spawnEnemy();
		// UPDATE POSITIONS
		this->moveEntities();
		// DRAW
		this->draw();

		// CALCULATE TIME AND FPS
		now = clock();
		frames++;
		if (((now - before) / CLOCKS_PER_SEC) == 1) // 1 second elapsed
		{
			this->time++;
			this->spawnTimer++;
			before = now;
			this->fps = frames;
			frames = 0;
		}


		// WAIT FOR REST OF 1/60th OF SECOND (or 1/fps'th of a second)
		while(clock() / CLOCKS_PER_FRAME == now / CLOCKS_PER_FRAME) {}
	}
}

void Game::draw() {
	clear();
	getmaxyx(stdscr, rows, cols);

	box(stdscr, 0, 0);
	mvprintw(this->rows - 1, 5, "FPS: %d", this->fps); //display frames
	mvprintw(this->rows - 1, 50, "ROWS: %d COLS: %d", rows, cols); //display row/cols
	mvprintw(this->rows - 1, 30, "TIME: %0.2d:%0.2d", this->time / 60, this->time%60);
	mvprintw(this->rows - 1, 17, "NEXT: %d", this->spawnTime - this->spawnTimer);
	this->drawEntities();
	refresh();
}

void    Game::drawEntities() {
	this->player.draw();
	this->player.drawBullets();
	for (int i = 0; i < MAX_ENEMIES; i++)
		if (enemies[i]->isDisplayed())
			enemies[i]->draw();
}

void    Game::moveEntities() {
	Bullet** b = this->player.getBullets();
	for (int j = 0; j < this->player.getNumBullets(); j++) {
		if (b[j]->isDisplayed()) {
			b[j]->moveForward();
			this->checkBulletCollision(*b[j]);
		}
	}
	for (int i = 0; i < MAX_ENEMIES; i++) {
		if (enemies[i]->isDisplayed()) {
			enemies[i]->move();
			if (enemies[i]->isDisplayed() && enemies[i]->checkCollision(this->player))
				this->player.hide();
		}
	}
	for (int m = 0; m < this->player.getNumBullets(); m++) {
		if (b[m]->isDisplayed()) {
			this->checkBulletCollision(*b[m]);
		}
	}
}

void	Game::checkBulletCollision(Bullet & b) {
	for (int k = 0; k < MAX_ENEMIES; k++) {
		if (enemies[k]->checkCollision(b)) {
			enemies[k]->hide();
			b.hide();
		}
	}
}

void    Game::handleKeyPress(int c) {
	switch(c) {
		case KEY_LEFT:
			this->player.moveLeft();
			this->checkEnemyCollision();
			break;
		case KEY_RIGHT:
			this->player.moveRight();
			this->checkEnemyCollision();
			break;
		case KEY_UP:
			this->player.moveUp();
			this->checkEnemyCollision();
			break;
		case KEY_DOWN:
			this->player.moveDown();
			this->checkEnemyCollision();
			break;
		case ' ':
			this->player.shoot(player.getPos());
			break;
		case 27: // exit on 'esc' for now
			this->finished = true;
			break;
	}
}

void	Game::checkEnemyCollision() {
	for (int i = 0; i < MAX_ENEMIES; i++) {
		if (this->enemies[i]->isDisplayed() && this->enemies[i]->checkCollision(this->player))
			this->player.hide();
	}
}

void	Game::spawnEnemy() {
	int i = 0;

	if (this->spawnTime == this->spawnTimer) {
		this->spawnTimer = 0;
		this->spawnTime = rand() % 4 + 1;
		while (this->enemies[i]->isDisplayed())
			i++;
		this->enemies[i]->show();
	}
}