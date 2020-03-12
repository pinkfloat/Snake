#pragma once
#include "snakehead.hpp"
#include "window.hpp"
#include "image.hpp"
#include "level.hpp"

class Game {
	public:
		Game();
		~Game();
		
		bool isRunning;
		Window* window;			//Zum Spielfeld zeichnen

		SnakeHead* player;
		GameObject* apple;
		Level* level;			//Spielfeldarray, beinhaltet Objektplatzierungen

		SnakeHead* initializePlayer();
		GameObject* initializeApple();
		Level* initializeLevel();

		void updateLevelMap();	//Zum aktualisieren der Objektplatzierungen auf dem Spielfeld
		bool update(); 			//Spiellogik voranbringen
};
