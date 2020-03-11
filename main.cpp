#include "game.hpp"

#define FRAMERATE 180

int main ( ) {

	Game game;
	game.initializeGame();

	for ( ; ; ) {

		Uint32 ticks_start = SDL_GetTicks();
		
		game.isRunning = game.player->getKeyInput();

		if ( !game.isRunning )
			break;
		
		game.isRunning = game.update();
		
			
		game.window->draw();

		Uint32 time = SDL_GetTicks() - ticks_start;

		if ( time < FRAMERATE)
			SDL_Delay(FRAMERATE - time);

		if ( !game.isRunning )
			break;
	}

	printf("Your apples: %ld\n", game.player->Parts.size()-2);

	return 0;
}
