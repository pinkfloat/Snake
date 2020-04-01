#include "snakehead.hpp"
#include "image.hpp"

SnakeHead::SnakeHead(int headX, int headY, Direction dir, Window* window)
: GameObject (headX, headY, window), dir(dir), oldDir(dir)
{}

SnakeHead::~SnakeHead() {
	for (auto actualPart : Parts) {
		delete(actualPart);
	}
}

void SnakeHead::getHeadImage() {
	switch (dir) {
		case Direction::UP: 	imagePosition = THeadUp; 	break;
		case Direction::RIGHT: 	imagePosition = THeadRight; break;
		case Direction::DOWN:	imagePosition = THeadDown; 	break;
		case Direction::LEFT: 	imagePosition = THeadLeft;	break;
		default:				imagePosition = TApple; 	break;
	}
}

bool SnakeHead::getKeyInput() {
	bool isRunning = true;
	bool firstKeyInput = true;
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:	isRunning = false;	break;
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym) {
					case SDLK_ESCAPE:	isRunning = false;	break;
					case SDLK_w:		if (dir != Direction::DOWN && firstKeyInput)
											dir = Direction::UP;
										firstKeyInput = false;
										break;
					case SDLK_a:		if (dir != Direction::RIGHT && firstKeyInput)
											dir = Direction::LEFT;
										firstKeyInput = false;
										break;
					case SDLK_s:		if (dir != Direction::UP && firstKeyInput)
											dir = Direction::DOWN;
										firstKeyInput = false;
										break;
					case SDLK_d:		if (dir != Direction::LEFT && firstKeyInput)
											dir = Direction::RIGHT;
										firstKeyInput = false;
										break;
					default:			break;
				}
			break;
			default:	break;
		}
	}
	return isRunning;
}

void SnakeHead::moveForward() {
	oldX = x;
	oldY = y;
	oldDir = dir;	
	switch(dir) {
		case Direction::UP:		this->y -= 1;		break;
		case Direction::RIGHT:	this->x += 1;		break;
		case Direction::DOWN:	this->y += 1;		break;
		case Direction::LEFT:	this->x -= 1;		break;
	}
	getHeadImage();
}

void SnakeHead::addSnakePart(SnakePart* newPart) {
	this->Parts.push_back(newPart);
}

void SnakeHead::letPartsFollow() {
	for (int i = Parts.size()-1; i >= 0; i--) {
		//Hinter vorangehendem Teil herlaufen
		int j = i-1;
		if (i > 0) {
			Parts[i]->y = Parts[j]->y;
			Parts[i]->x = Parts[j]->x;
			Parts[i]->oldDir = Parts[i]->dir;
			Parts[i]->dir = Parts[j]->dir;
			//Wenn Tail
			if (i == Parts.size()-1) {
				Parts[i]->getTailImage();
			}
			else
				Parts[i]->getBodyImage();
		}
		//Hinter dem Kopf herlaufen
		if (i == 0) {
			Parts[i]->y = oldY;
			Parts[i]->x = oldX;
			Parts[i]->oldDir = Parts[i]->dir;
			Parts[i]->dir = oldDir;
			Parts[i]->getBodyImage();
		}
	}
}