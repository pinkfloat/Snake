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

	level.field[14][12] = fieldCondition::SNAKE;
	level.field[13][12] = fieldCondition::SNAKE;
	level.field[12][12] = fieldCondition::SNAKE;

	return player;
}

GameObject* Game::initializeApple(){
//ToDo: Random-File erstellen -> Funktion hier einfügen
	apple = new GameObject(6,6,window);
	level.field[6][6] = fieldCondition::APPLE;
	return apple;
}

void Game::initializeGame(){
	initializePlayer();
	initializeApple();
}

void Game::updateLevelMap(){
	for ( int x = 0; x < level_width-1; x++){
		for ( int y = 0; y < level_height-1; y++){
			level.field[x][y] = fieldCondition::EMPTY;
		}
	}
	for ( auto SnakePart : player->Parts ){
			level.field[SnakePart->x][SnakePart->y] = fieldCondition::SNAKE;
	}
	level.field[apple->x][apple->y] = fieldCondition::APPLE;
}

bool Game::update(){
	int old_x = player->x;
	int old_y = player->y;
	Direction old_dir = player->dir;
	player->moveForward();
	player->letPartsFollow(old_y, old_x, old_dir);
	player->getImageByDirection();
	updateLevelMap();
	for( auto actualObj : window->GameObjectList){
		actualObj->updatePosition();
	}
	return level.checkCollision(player);
}
