#include "gameobject.hpp"
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