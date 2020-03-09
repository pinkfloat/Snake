#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "gameobjects.hpp"

class Window {
	
	public:
		Window (const char* title, bool fullscreen);
		~Window();

		SDL_Window* window;
		SDL_Renderer* renderer;

		void addGameObject( GameObject* newGameObject );		
		void addTextureToObject( GameObject* newGameObject );
		void draw();

	private:
		std::vector<GameObject*> GameObjectList;
};
