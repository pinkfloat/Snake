#include "gameobjects.hpp"
#include "window.hpp"

GameObject::GameObject(int pos_x, int pos_y, int width, int height, const char* img_path, Window* window)
: img_path(img_path)
{
	this->myFigure = { pos_x, pos_y, width, height };
	window->addGameObject( this );
	window->addTextureToObject( this );
}

GameObject::~GameObject(){
}



Player::Player(int pos_x, int pos_y, int width, int height, const char* img_path, Window* window)
: GameObject ( pos_x, pos_y, width, height, img_path, window)
{}

Player::~Player(){}

bool Player::getKeyInput(){
	bool isRunning = true;
	const uint8_t* keystate = SDL_GetKeyboardState(NULL);

	//Bewegungssteuerung Spieler

	if (keystate[ SDL_SCANCODE_W ] ){
		this->myFigure.y -= 5;
	}
	if (keystate[ SDL_SCANCODE_A ] ){
		this->myFigure.x -= 5;
	}
	if (keystate[ SDL_SCANCODE_S ] ){
		this->myFigure.y += 5;
	}
	if (keystate[ SDL_SCANCODE_D ] ){
		this->myFigure.x += 5;
	}

	//Für 2. Spieler bzw. alternative Tasten
	/*
	if (keystate[ SDL_SCANCODE_UP ] ){
		this->myFigure.y -= 10;
	}
	if (keystate[ SDL_SCANCODE_LEFT ] ){
		this->myFigure.x -= 10;
	}
	if (keystate[ SDL_SCANCODE_DOWN ] ){
		this->myFigure.y += 10;
	}
	if (keystate[ SDL_SCANCODE_RIGHT ] ){
		this->myFigure.x += 10;
	}
	*/

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
