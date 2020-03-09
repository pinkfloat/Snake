#pragma once
#include "window.hpp"

class Game {

	public:
		Game();
		~Game();
		
		bool isRunning;
		Window* window;

		void update(); //Spiellogik voranbringen, alle non-Player game-objekte updaten
};
