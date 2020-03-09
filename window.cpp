#include "window.hpp"

Window::Window(const char* title, bool fullscreen){
    int flags = 0;
	if(fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;

		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, fullscreen);
		
		if(window)
			printf("Window created!\n");

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

		if(renderer)
			printf("Renderer created!\n");
}

Window::~Window(){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void Window::addGameObject( GameObject* newGameObject ){
	this->GameObjectList.push_back( newGameObject );
}

void Window::addTextureToObject( GameObject* newGameObject ){
	SDL_Surface* image = IMG_Load(newGameObject->getImagePath());
	newGameObject->myTexture = SDL_CreateTextureFromSurface(this->renderer, image);
	SDL_FreeSurface(image);	
}

void Window::draw(){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);	//Weiß
	SDL_RenderClear(renderer);								//Bild  mit letzter Farbe überschreiben

	for( auto actualObj : this->GameObjectList ){
		SDL_RenderCopy(renderer, actualObj->myTexture, NULL, &actualObj->myFigure);
	}

	SDL_RenderPresent(renderer);							//Gezeichnetes auf Screen bringen
	SDL_Delay(20);											//20ms warten
}
