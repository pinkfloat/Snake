/*
*   Copyright: (c) 2020 Sabrina Otto. All rights reserved.
*   This work is licensed under the terms of the MIT license.
*/

#include <cstdlib>
#include <ctime>
#include "level.hpp"

#define maxRandomLoops 20

Level::Level(SnakeHead* player, GameObject* apple) {
	for (int x = 0; x < level_width; x++) {
		for (int y = 0; y < level_height; y++) {
			if (x == 0 || x == level_width - 1) //lateral boundary
				field[x][y] = fieldCondition::WALL;
			else if (y == 0 || y == level_height - 1) //upper and lower limit
				field[x][y] = fieldCondition::WALL;
		}
	}
	updateMap(player, apple);
}

void Level::updateMap(SnakeHead* player, GameObject* apple) {
	for (int x = 1; x < level_width - 1; x++) {
		for (int y = 1; y < level_height - 1; y++) {
			field[x][y] = fieldCondition::EMPTY;
		}
	}
	field[apple->x][apple->y] = fieldCondition::APPLE;
	for (auto SnakePart : player->Parts) {
		field[SnakePart->x][SnakePart->y] = fieldCondition::SNAKE;
	}
}

//Game ends if player has collision with wall or body
bool Level::checkCollision( SnakeHead* player, GameObject* apple, Window* window) {
	if (field [player->x][player->y] == fieldCondition::EMPTY)
		return true;
	else if (player->Parts.size() == level_width * level_height-1) {
		printf("Player won, but no one will ever notice...\n");
		return false;
	}		
	else if (field[player->x][player->y] == fieldCondition::APPLE) {
		//resize snake
		SnakePart* newPart = new SnakePart(player->x, player->y, player->dir, window);
		player->addSnakePart(newPart);

		replaceApple(player, apple);
		return true;
	}
	else if (field[player->x][player->y] == fieldCondition::WALL) {
		printf("Player crashes through wall\n");
		return false;
	}
	else if (field[player->x][player->y] == fieldCondition::SNAKE) {
		printf("Player ate himself\n");
		return false;
	}
	else {
		printf("Player managed to came to an uninitialized field aka wormhole\n");
		return false;
	}
}

void Level::replaceApple(SnakeHead* player, GameObject* apple) {
	bool spawnInPlayer;
	int loops = 0;
	std::srand(time(nullptr)); //use actual time in random generator

	do {
		spawnInPlayer = false;	
		apple->x = rand() % 21 + 1;
		apple->y = rand() % 13 + 1;

		//avoid that apple spawns in snake
		if ((player->x == apple->x)&&(player->y == apple->y))
			spawnInPlayer = true;
		else {
			for (auto actualPart : player->Parts) {
				if (actualPart->x == apple->x && actualPart->y == apple->y)
					spawnInPlayer = true;
			}
		}
		loops++;
	} while (spawnInPlayer && loops < maxRandomLoops);

	//if random needs too much time searching for an empty field
	if (loops >= maxRandomLoops) {
		for (int x = 0; x < level_width; x++) {
			for (int y = 0; y < level_height; y++) {
				if (field[x][y] == fieldCondition::EMPTY) {
					apple->x = x;
					apple->y = y;
					spawnInPlayer = false;
					break;
				}
			}
			if (!spawnInPlayer)
				break;
		}
		if (spawnInPlayer)
			fprintf(stderr, "Couldn't find empty place for an apple\n");
	}
}