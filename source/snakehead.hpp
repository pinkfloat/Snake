/*
*   Copyright: (c) 2020 Sabrina Otto. All rights reserved.
*   This work is licensed under the terms of the MIT license.
*/

#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include "snakepart.hpp"

/* 'SnakeHead' is controlled by player */

class SnakeHead : public GameObject {
	public:
		std::vector<SnakePart*> Parts;

		int oldX, oldY;
		Direction dir, oldDir;

		SnakeHead(int headX, int headY, Direction dir, Window* window);
		~SnakeHead();

		void getHeadImage();
		bool getKeyInput();
		void moveForward();
		void addSnakePart(SnakePart* newPart);
		void letPartsFollow();
};