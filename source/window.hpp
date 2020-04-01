/*
*   Copyright: (c) 2020 Sabrina Otto. All rights reserved.
*   This work is licensed under the terms of the MIT license.
*/

#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include "gameobject.hpp"

/* 'Window' communicates with the SDL-library and draws all game elements to the screen */

class Window {
	public:
		Window(const char* title, bool fullscreen);
		~Window();

		SDL_Window* window;
		SDL_Renderer* renderer;
		SDL_Surface* image;
		SDL_Texture* snakeBMP;

		void addGameObject(GameObject* newGameObject);		
		void draw();

		std::vector<GameObject*> GameObjectList;
};
