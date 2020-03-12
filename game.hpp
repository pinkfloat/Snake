#pragma once
#include "snakehead.hpp"
#include "window.hpp"
#include "image.hpp"
#include "level.hpp"

/* Game dient der Initialisierung der Startwerte fuer Schlange, Apfel und Level
und aktualisiert die Spiellogik in Geschwindigkeit der Framerate */

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
