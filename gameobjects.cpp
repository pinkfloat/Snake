#include "gameobjects.hpp"
#include "window.hpp"
#include "image.hpp"

GameObject::GameObject(int x, int y, SDL_Rect imgPart, Window* window)
: x(x), y(y), imagePosition(imgPart)
{
	updatePosition();
	window->addGameObject( this );
}

GameObject::~GameObject(){
}

void GameObject::updatePosition(){
	this->levelPosition = { calculatePixelPosition(x), calculatePixelPosition(y), 64, 64 };
}

SnakePart::SnakePart(int partX, int partY, SDL_Rect imgPart, Window* window)
: GameObject ( partX, partY, imgPart, window )
{} 

SnakePart::~SnakePart(){
}

SnakeHead::SnakeHead(int headX, int headY, SDL_Rect imgPart, Window* window)
: SnakePart ( headX, headY, imgPart, window )
{}

SnakeHead::~SnakeHead(){
}

bool SnakeHead::getKeyInput(){
	bool isRunning = true;
	const uint8_t* keystate = SDL_GetKeyboardState(NULL);

	//Bewegungssteuerung Spieler
	if (keystate[ SDL_SCANCODE_W ] ){
		this->y -= 1;
	}
	if (keystate[ SDL_SCANCODE_A ] ){
		this->x -= 1;
	}
	if (keystate[ SDL_SCANCODE_S ] ){
		this->y += 5;
	}
	if (keystate[ SDL_SCANCODE_D ] ){
		this->x += 5;
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

}