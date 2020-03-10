#include "game.hpp"

int main ( ) {

	Game game;
	game.initializeGame();

	while ( game.isRunning ) {

		game.isRunning = game.player->getKeyInput();
		game.update();
		game.window->draw();
	}

	return 0;
}
