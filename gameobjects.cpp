#include "gameobjects.hpp"
#include "window.hpp"
#include "image.hpp"

GameObject::GameObject(int x, int y, Window* window)
: x(x), y(y)
{
	imagePosition = TApple;
	updatePosition();
	if (window)
		window->addGameObject( this );
}

GameObject::~GameObject(){
}

void GameObject::updatePosition(){
	this->levelPosition = { calculatePixelPosition(x), calculatePixelPosition(y), 64, 64 };
}

/*____SNAKE_PART____*/

SnakePart::SnakePart(int partX, int partY, Direction dir, Window* window)
: GameObject ( partX, partY, window ), dir(dir)
{} 

SnakePart::~SnakePart(){
}

void SnakePart::getImageByDirection(){
	switch(dir){
		default:
					imagePosition = TApple;	break;
	}
}

/*____SNAKE_HEAD____*/

SnakeHead::SnakeHead(int headX, int headY, Direction dir, Window* window)
: GameObject ( headX, headY, window), dir(dir)
{}

SnakeHead::~SnakeHead(){
	for ( auto actualPart : Parts){
		delete(actualPart);
	}
}

void SnakeHead::getImageByDirection(){
	switch (dir){
			case Direction::UP: 	imagePosition = THeadUp; 	break;
			case Direction::RIGHT: 	imagePosition = THeadRight; break;
			case Direction::DOWN:	imagePosition = THeadDown; 	break;
			case Direction::LEFT: 	imagePosition = THeadLeft;	break;
			default:				imagePosition = TApple; 	break;
	}
}

bool SnakeHead::getKeyInput(){
	bool isRunning = true;
	SDL_Event event;
	while (SDL_PollEvent(&event)){

		switch (event.type) {
			case SDL_QUIT:	isRunning = false;	break;
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym) {
					case SDLK_ESCAPE:	isRunning = false;		break;
					case SDLK_w:		if (dir != Direction::DOWN)
											dir = Direction::UP;
										break;
					case SDLK_a:		if (dir != Direction::RIGHT)
											dir = Direction::LEFT;
										break;
					case SDLK_s:		if (dir != Direction::UP)
											dir = Direction::DOWN;
										break;
					case SDLK_d:		if ( dir != Direction::LEFT)
											dir = Direction::RIGHT;
										break;
					default:			break;
				}
			break;
			default:	break;
		}
	}
	return isRunning;
}

void SnakeHead::moveForward(){
	switch(dir){
		case Direction::UP:		this->y -= 1;		break;
		case Direction::RIGHT:	this->x += 1;		break;
		case Direction::DOWN:	this->y += 1;		break;
		case Direction::LEFT:	this->x -= 1;		break;
	}
}

void SnakeHead::addSnakePart( SnakePart* newPart){
	this->Parts.push_back(newPart);
}

void SnakeHead::letPartsFollow( int old_y, int old_x, Direction old_dir){
	for ( int i = Parts.size()-1; i >= 0; i--){
			//Hinter vorangehendem Teil herlaufen
			int j = i-1;
			if (i > 0){
				Parts[i]->y = Parts[j]->y;
				Parts[i]->x = Parts[j]->x;
				Parts[i]->dir = Parts[j]->dir;
			
		}
		//Hinter dem Kopf herlaufen
		if (i == 0)
		{
			Parts[i]->y = old_y;
			Parts[i]->x = old_x;
			Parts[i]->dir = old_dir;
		}
	}
}