#pragma once
#include "gameobjects.hpp"
#include "window.hpp"
#include "image.hpp"
#include "level.hpp"

class Game {

	public:
		Game();
		~Game();
		
		bool isRunning;
		Window* window;

		Level level;

		SnakeHead* player;
		GameObject* apple;

		SnakeHead* initializePlayer();
		GameObject* initializeApple();
		void initializeGame();

		void updateLevelMap();
		bool update(); //Spiellogik voranbringen, alle non-Player game-objekte updaten
};
