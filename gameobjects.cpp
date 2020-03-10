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

void GameObject::followElement(GameObject* previousElement){
	if ( previousElement->x < this->x)
		--x;
	else if ( previousElement->x > this->x)
		++x;
	else if ( previousElement->y < this->y)
		--y;
	else if ( previousElement->y > this->y)
		++y;
}

SnakePart::SnakePart(int partX, int partY, Direction newDir, Window* window)
: GameObject ( partX, partY, window ), newDir(newDir), oldDir(newDir)
{} 

SnakePart::~SnakePart(){
}



void SnakePart::getImageByDirection(){
	switch(newDir){
		default:
					imagePosition = TApple;	break;
	}
}

SnakeHead::SnakeHead(int headX, int headY, Direction newDir, Window* window)
: GameObject ( headX, headY, window), newDir(newDir), oldDir(newDir)
{}

SnakeHead::~SnakeHead(){
	for ( auto actualPart : Parts){
		delete(actualPart);
	}
}

void SnakeHead::getImageByDirection(){
	switch (newDir){
			case Direction::UP: 	imagePosition = THeadUp; 	break;
			case Direction::RIGHT: 	imagePosition = THeadRight; break;
			case Direction::DOWN:	imagePosition = THeadDown; 	break;
			case Direction::LEFT: 	imagePosition = THeadLeft;	break;
			default:				imagePosition = TApple; 	break;
	}
}

bool SnakeHead::getKeyInput(){
	bool isRunning = true;
	const uint8_t* keystate = SDL_GetKeyboardState(NULL);

	//Bewegungssteuerung Spieler
	if (keystate[ SDL_SCANCODE_W ] && newDir != Direction::DOWN){
		newDir = Direction::UP;
	}
	if (keystate[ SDL_SCANCODE_A ] && newDir != Direction::RIGHT){
		newDir = Direction::LEFT;
	}
	if (keystate[ SDL_SCANCODE_S ] && newDir != Direction::UP){
		newDir = Direction::DOWN;
	}
	if (keystate[ SDL_SCANCODE_D ] && newDir != Direction::LEFT){
		newDir = Direction::RIGHT;
	}

	//Spieler moechte Spiel verlassen
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
		case SDL_QUIT:	isRunning = false;	break;
		case SDL_KEYDOWN:
			switch(event.key.keysym.sym) {
				case SDLK_ESCAPE:	isRunning = false;		break;
				default:									break;
			} 		break;
		default:	break;
	}
	return isRunning;
}

void SnakeHead::moveForward(){
	switch(newDir){
		case Direction::UP:		this->y -= 1;		break;
		case Direction::RIGHT:	this->x += 1;		break;
		case Direction::DOWN:	this->y += 1;		break;
		case Direction::LEFT:	this->x -= 1;		break;
	}
}

void SnakeHead::addSnakePart( SnakePart* newPart){
	this->Parts.push_back(newPart);
}

void SnakeHead::letPartsFollow(){
	int i = 0;
	Direction oldDirFromLastPart;
	SnakePart* previousElement = NULL;

	for( auto actualPart : Parts ){
		if ( i == 0){
			actualPart->newDir = this->oldDir;
			oldDirFromLastPart = actualPart->oldDir;
			this->oldDir = this->newDir;

			actualPart->followElement(this);
		}

		else{
        	actualPart->newDir = oldDirFromLastPart;
			oldDirFromLastPart = actualPart->oldDir;
			actualPart->oldDir = actualPart->newDir;

			actualPart->followElement(previousElement);
		}
		previousElement = actualPart;
		i++;
	}
}
