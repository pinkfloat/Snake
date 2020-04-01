/*
*   Copyright: (c) 2020 Sabrina Otto. All rights reserved.
*   This work is licensed under the terms of the MIT license.
*/

#include "gameobject.hpp"
#include "window.hpp"
#include "image.hpp"

GameObject::GameObject(int x, int y, Window* window)
: x(x), y(y)
{
	imagePosition = TApple;
	updatePosition();
	if (window)
		window->addGameObject(this);
}

void GameObject::updatePosition() {
	this->levelPosition = { calculatePixelPosition(x), calculatePixelPosition(y), 64, 64 };
}