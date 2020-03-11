#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "gameobject.hpp"

class Window {
	
	public:
		Window (const char* title, bool fullscreen);
		~Window();

		SDL_Window* window;
		SDL_Renderer* renderer;
		SDL_Surface* image;
		SDL_Texture* snakeBMP;

		void addGameObject( GameObject* newGameObject );		
		void draw();

		std::vector<GameObject*> GameObjectList;
};
