#include "game.hpp"
#include "gameobjects.hpp"
#include <cstdio>

Game::Game(){
	if( (SDL_Init(SDL_INIT_VIDEO) == 0) && (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG)) ){
		printf("Subsystem Initialised!\n");

		this->window = new Window("Title", false);

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

void Game::update(){
}
