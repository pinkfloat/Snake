#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "gameobject.hpp"

class SnakePart : public GameObject {
	public:
		Direction dir, oldDir;
		SnakePart(int partX, int partY, Direction dir, Window* window);

		void getBodyImage();
		void getTailImage();
};