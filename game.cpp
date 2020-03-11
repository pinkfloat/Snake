#include <cstdio>
#include "game.hpp"

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
	delete(level);
	delete(player);
	delete(apple);
	delete(window);
	IMG_Quit();
	SDL_Quit();
	printf("Game cleaned!\n");
}

SnakeHead* Game::initializePlayer(){
	player = new SnakeHead(14, 12, Direction::RIGHT, window);
	SnakePart* part1 = new SnakePart(13, 12, Direction::RIGHT, window);
	SnakePart* part2 = new SnakePart(12, 12, Direction::RIGHT, window);
	player->addSnakePart(part1);
	player->addSnakePart(part2);
	return player;
}

GameObject* Game::initializeApple(){
	apple = new GameObject(0,0,window);
	level->replaceApple(player, apple);
	return apple;
}

Level* Game::initializeLevel(){
	return level = new Level(player, apple);
}

void Game::initializeGame(){
	initializeApple();
	initializePlayer();
	initializeLevel();
}

bool Game::update(){
	player->moveForward();
	player->letPartsFollow();
	level->updateMap(player, apple);
	//printf("x = %d, y = %d\n", player->x, player->y); //TEST
	for( auto actualObj : window->GameObjectList){
		actualObj->updatePosition();
	}
	return level->checkCollision(player, apple, window);
}
