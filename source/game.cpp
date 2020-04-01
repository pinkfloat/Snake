/*
*   Copyright: (c) 2020 Sabrina Otto. All rights reserved.
*   This work is licensed under the terms of the MIT license.
*/

#include <cstdio>
#include <stdexcept>
#include "game.hpp"

Game::Game() {
	if (SDL_Init(SDL_INIT_VIDEO))
		throw std::runtime_error(SDL_GetError());

	printf("Subsystem Initialised!\n");

	this->window = new Window("Snake", false);
	initializeApple();
	initializePlayer();
	initializeLevel();

	this->isRunning = true;
}

Game::~Game() {
	delete(level);
	delete(player);
	delete(apple);
	delete(window);
	SDL_Quit();
	printf("Game cleaned!\n");
}

SnakeHead* Game::initializePlayer() {
	player = new SnakeHead(14, 12, Direction::RIGHT, window);
	SnakePart* part1 = new SnakePart(13, 12, Direction::RIGHT, window);
	SnakePart* part2 = new SnakePart(12, 12, Direction::RIGHT, window);
	player->addSnakePart(part1);
	player->addSnakePart(part2);
	return player;
}

GameObject* Game::initializeApple() {
	apple = new GameObject(0,0,window);
	level->replaceApple(player, apple);
	return apple;
}

Level* Game::initializeLevel() {
	return level = new Level(player, apple);
}

bool Game::update() {
	player->moveForward();
	player->letPartsFollow();
	level->updateMap(player, apple);
	for (auto actualObj : window->GameObjectList) {
		actualObj->updatePosition();
	}
	return level->checkCollision(player, apple, window);
}
