#pragma once
#include <SDL2/SDL.h>

/* GameObject dient der Erstellung des Apfels im Spiel und bildet
die Basisklasse fuer die Koerperelemente und den Kopf der Schlange */

class Window;

//Blickrichtung der Schlange
enum class Direction {
	UP, RIGHT, DOWN, LEFT
};

class GameObject {
	public:
		int x, y;
		SDL_Rect levelPosition;
		SDL_Rect imagePosition;

		GameObject(int x, int y, Window* window);
		
		inline int calculatePixelPosition(int tile) { return tile * 64; }
		void updatePosition();
};