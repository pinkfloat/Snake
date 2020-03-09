#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class Window;

class GameObject {

	public:
		
		SDL_Rect myFigure; 
		SDL_Texture* myTexture;	//Textur von RAM -> Grafikkarte
		
		GameObject(int pos_x, int pos_y, int width, int height, const char* img_path, Window* window);
		~GameObject();
		
		const char* getImagePath() { return img_path; }	
		void update();

	protected:
		const char* img_path;

};

class Player : public GameObject {

	public:
		Player(int pos_x, int pos_y, int width, int height, const char* img_path, Window* window);
		~Player();
		bool getKeyInput();
};
