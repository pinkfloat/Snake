#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Window;

//Blickrichtung der Schlange
enum class Direction {
	UP, RIGHT, DOWN, LEFT
};

class GameObject {

	public:
		
		int x, y;
		SDL_Rect levelPosition;
		SDL_Rect imagePosition;


		GameObject(int x, int y, Window* window);
		~GameObject();
		
		inline int calculatePixelPosition( int tile ) { return tile * 64; }
		void updatePosition();
		
};