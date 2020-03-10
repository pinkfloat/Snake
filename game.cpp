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
	IMG_Quit();
	SDL_Quit();
	printf("Game cleaned!\n");
}

SnakeHead* Game::initializePlayer(){
	player = new SnakeHead(14,12,THeadRight,window);
	return player;
}

GameObject* Game::initializeApple(){
//ToDo: Random-File erstellen -> Funktion hier einfügen
	apple = new GameObject(6,6,TApple,window);
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
}
