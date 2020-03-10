#include "game.hpp"
#include "gameobjects.hpp"
#include <cstdio>

Game::Game(){
	if( (SDL_Init(SDL_INIT_VIDEO) == 0) && (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG)) ){
		printf("Subsystem Initialised!\n");

		this->window = new Window("Snake", false);

		this->isRunning = true;
	}
	else
		this->isRunning = false;
}

Game::~Game(){
	delete(apple);
	delete(player);
	IMG_Quit();
	SDL_Quit();
	printf("Game cleaned!\n");
}

SnakeHead* Game::initializePlayer(){
	player = new SnakeHead(14, 12, Direction::RIGHT, window);
	SnakePart* part1 = new SnakePart(13, 12, Direction::LEFT, window);
	SnakePart* part2 = new SnakePart(12, 12, Direction::LEFT, window);
	player->addSnakePart(part1);
	player->addSnakePart(part2);
	return player;
}

GameObject* Game::initializeApple(){
//ToDo: Random-File erstellen -> Funktion hier einfügen
	apple = new GameObject(6,6,window);
	return apple;
}

void Game::initializeGame(){
	initializePlayer();
	initializeApple();
}

void Game::update(){
	for( auto actualObj : window->GameObjectList){
		actualObj->updatePosition();
	}
	int old_x = player->x;
	int old_y = player->y;
	Direction old_dir = player->dir;
	this->player->moveForward();
	this->player->letPartsFollow(old_y, old_x, old_dir);
	this->player->getImageByDirection();
}
