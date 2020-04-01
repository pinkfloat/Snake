/*
*   Copyright: (c) 2020 Sabrina Otto. All rights reserved.
*   This work is licensed under the terms of the MIT license.
*/

#pragma once
#include <SDL2/SDL.h>
#include "gameobject.hpp"

/* Every element of the snake, except the head */

class SnakePart : public GameObject {
	public:
		Direction dir, oldDir;
		SnakePart(int partX, int partY, Direction dir, Window* window);

		void getBodyImage();
		void getTailImage();
};