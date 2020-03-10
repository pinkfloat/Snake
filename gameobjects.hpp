﻿#pragma once
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
		
		Direction newDir, oldDir;
		SnakePart(int partX, int partY, Direction newDir, Direction oldDir, Window* window);
		~SnakePart();

		void getImageByDirection ();
};

class SnakeHead : public GameObject {

	std::vector<SnakePart> Parts;

	public:

		Direction newDir;

		SnakeHead(int headX, int headY, Direction newDir, Window* window);
		~SnakeHead();

		void getImageByDirection ();
		bool getKeyInput();
		void moveForward();
};