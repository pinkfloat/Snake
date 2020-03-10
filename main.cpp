#include "game.hpp"

#define FRAMERATE 100

int main ( ) {

	Game game;
	game.initializeGame();

	while ( game.isRunning ) {

		Uint32 ticks_start = SDL_GetTicks();

		game.isRunning = game.player->getKeyInput();
		game.update();
		game.window->draw();

		Uint32 time = SDL_GetTicks() - ticks_start;

		if ( time < FRAMERATE)
			SDL_Delay(FRAMERATE - time);
	}

	return 0;
}
