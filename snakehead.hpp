#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "snakepart.hpp"

/* Der Kopf der Schlange wird vom Spieler gesteuert,
er ist also folglich die eigentliche Spielfigur */

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