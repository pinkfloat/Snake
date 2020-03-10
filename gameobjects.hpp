#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

class Window;

class GameObject {

	public:
		
		int x, y;
		SDL_Rect levelPosition;
		SDL_Rect imagePosition;

		GameObject(int x, int y, SDL_Rect imgPart, Window* window);
		~GameObject();
		
		inline int calculatePixelPosition( int tile ) { return tile * 64; }
		void updatePosition();
};

//Blickrichtung der Schlange
enum class Direction {
	UP, RIGHT, DOWN, LEFT
};

class SnakePart : public GameObject {
	public:
		
		Direction dir;

		SnakePart(int partX, int partY, SDL_Rect imgPart, Window* window);
		~SnakePart();
};

class SnakeHead : public SnakePart {

	std::vector<SnakePart> Parts;

	public:
		SnakeHead(int headX, int headY, SDL_Rect imgPart, Window* window);
		~SnakeHead();

		bool getKeyInput();
		void moveForward();
};
