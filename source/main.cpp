/*
*   Copyright: (c) 2020 Sabrina Otto. All rights reserved.
*   This work is licensed under the terms of the MIT license.
*/

#include "game.hpp"
#include <stdexcept>

#define FRAMERATE 180

int main ( ) try {
	Game game;

	for (;;) {
		Uint32 ticks_start = SDL_GetTicks();
		
		game.isRunning = game.player->getKeyInput();
		if (!game.isRunning)
			break;
		
		game.isRunning = game.update();
		if (!game.isRunning)
			break;	
			
		game.window->draw();

		Uint32 time = SDL_GetTicks() - ticks_start;
		if (time < FRAMERATE)
			SDL_Delay(FRAMERATE - time);	
	}
	printf("Your apples: %ld\n", game.player->Parts.size()-2);
	return 0;
}

catch (std::runtime_error& e) {
	fprintf(stderr, "Error: %s\n", e.what());
	return 1;
}