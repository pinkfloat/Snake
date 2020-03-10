﻿#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <list>

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
		void followElement( GameObject* previousElement);
		
};

class SnakePart : public GameObject {
	public:
		
		Direction newDir, oldDir;
		SnakePart(int partX, int partY, Direction newDir, Window* window);
		~SnakePart();

		void getImageByDirection ();
};

class SnakeHead : public GameObject {

	std::list<SnakePart*> Parts;

	public:

		Direction newDir, oldDir;

		SnakeHead(int headX, int headY, Direction newDir, Window* window);
		~SnakeHead();

		void getImageByDirection ();
		bool getKeyInput();
		void moveForward();
		void addSnakePart ( SnakePart* newPart );
		void letPartsFollow();
};