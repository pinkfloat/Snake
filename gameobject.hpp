#pragma once
#include <SDL2/SDL.h>

/* 'GameObject' is to create the apple in game and also
	the base class of body parts and head of the snake */

class Window;

//snake viewing direction
enum class Direction {
	UP, RIGHT, DOWN, LEFT
};

class GameObject {
	public:
		int x, y;
		SDL_Rect levelPosition;
		SDL_Rect imagePosition;

		GameObject(int x, int y, Window* window);
		
		inline int calculatePixelPosition(int tile) { return tile * 64; }
		void updatePosition();
};