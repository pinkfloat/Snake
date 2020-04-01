/*
*   Copyright: (c) 2020 Sabrina Otto. All rights reserved.
*   This work is licensed under the terms of the MIT license.
*/

#pragma once
#include "snakehead.hpp"
#include "window.hpp"
#include "image.hpp"
#include "level.hpp"

/* 'Game' initialises the start values for snake, apple and level
   and refreshes game logic in speed of framerate */

class Game {
	public:
		Game();
		~Game();
		
		bool isRunning;
		Window* window;			//draws the game

		SnakeHead* player;
		GameObject* apple;
		Level* level;			//the array where every object is placed in (snakes, apples, walls and empty spaces)

		SnakeHead* initializePlayer();
		GameObject* initializeApple();
		Level* initializeLevel();

		void updateLevelMap();	//to refresh the placement of every object
		bool update(); 			//pushes game forward
};
