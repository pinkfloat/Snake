#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

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

class SnakePart : public GameObject {
	public:
		
		Direction dir, oldDir;
		SnakePart(int partX, int partY, Direction dir, Window* window);
		~SnakePart();

		void getBodyImage ();
		void getTailImage ();
};

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
		void addSnakePart ( SnakePart* newPart );
		void letPartsFollow();
};