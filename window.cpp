#include "window.hpp"
#define IMG_PATH "img/snake-graphics.bmp"

Window::Window(const char* title, bool fullscreen){
    int flags = 0;
	if(fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;

	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1472, 960, fullscreen);
		
	if(window)
		printf("Window created!\n");

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if(renderer)
		printf("Renderer created!\n");

	image = SDL_LoadBMP(IMG_PATH);
	
	if(!image)
		fprintf(stderr, "Error loading %s, SDL Error: %p\n", IMG_PATH, SDL_GetError);

	snakeBMP = SDL_CreateTextureFromSurface(renderer, image);
	
	if(!snakeBMP)
		fprintf(stderr, "SDL_CreateTextureFromSurface() failed, SDL Error: %p\n", SDL_GetError());
}

Window::~Window(){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_FreeSurface(image);	
}

void Window::addGameObject( GameObject* newGameObject ){
	this->GameObjectList.push_back( newGameObject );
}

void Window::draw(){
	//Spielfeld mit Umrandung zeichnen
    SDL_SetRenderDrawColor(renderer, 0x1F, 0x1F, 0, 255);	//Farbe
	SDL_RenderClear(renderer);								//Bild  mit letzter Farbe überschreiben
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);	//Weiß
	SDL_Rect mitte = {64, 64, 21*64, 13*64};
	SDL_RenderFillRect(renderer, &mitte);

	for( auto actualObj : this->GameObjectList ){
    	SDL_RenderCopy(renderer, snakeBMP, &actualObj->imagePosition, &actualObj->levelPosition);
	}

	SDL_RenderPresent(renderer);							//Gezeichnetes auf Screen bringen
}
