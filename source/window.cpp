#include "window.hpp"
#include <stdexcept>

#define IMG_PATH "../img/snake-graphics.bmp"

Window::Window(const char* title, bool fullscreen) {
    int flags = 0;
	if (fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;

	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1472, 960, fullscreen);
		
	if (!window)
		goto err0;

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (!renderer)
		goto err1;

	image = SDL_LoadBMP(IMG_PATH);
	
	if (!image)
		goto err2;

	snakeBMP = SDL_CreateTextureFromSurface(renderer, image);
	
	if (!snakeBMP)
		goto err3;

	return;

	err3:
	SDL_FreeSurface(image);
	image = NULL;
	err2:
	SDL_DestroyRenderer(renderer);
	renderer = NULL;
	err1:
	SDL_DestroyWindow(window);
	window = NULL;
	err0:
	throw std::runtime_error(SDL_GetError());
}

Window::~Window() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_FreeSurface(image);
	SDL_DestroyTexture(snakeBMP);
}

void Window::addGameObject(GameObject* newGameObject) {
	this->GameObjectList.push_back(newGameObject);
}

void Window::draw() {
	//draws border and centre
    SDL_SetRenderDrawColor(renderer, 0x1F, 0x1F, 0, 255);	//edge: brown
	SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 170, 255, 160, 255);	//centre: green
	SDL_Rect mitte = {64, 64, 21*64, 13*64};
	SDL_RenderFillRect(renderer, &mitte);

	//draws objects (apple and snake)
	for (auto actualObj : this->GameObjectList) {
    	SDL_RenderCopy(renderer, snakeBMP, &actualObj->imagePosition, &actualObj->levelPosition);
	}
	SDL_RenderPresent(renderer);
}
