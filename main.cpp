#include "game.hpp"
#include "gameobjects.hpp"

int main ( ) {

	Game game;
	Player player_one(220, 140, 200, 200, "img/MrCubeHead_green_1.png", game.window);


	while ( game.isRunning ) {

		game.isRunning = player_one.getKeyInput();
		game.update();
		game.window->draw();
	}

	return 0;
}
