#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "Game.h"

int main(int argc, char *argv[])
{
	//values for frame limiter
	const int FPS = 60; 
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	Game* game = nullptr;
	game = new Game();

	//init sdl
	game->init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false);
	
	while (game->running())
	{
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		//framerate limiter
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->clean();

	return 0;
}