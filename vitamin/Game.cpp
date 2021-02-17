#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include <iostream>


GameObject* player;
Map* map;
SDL_Renderer* Game::renderer = nullptr;

Game::Game()
{
}


Game::~Game()
{
}

void Game::init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{  
		//d
		std::cout << "SDL initialized " << std::endl;

		//create window
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (window)
		{
			std::cout << "Window successfully created-" << std::endl;
		}

		//create renderer
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

		if (renderer)
		{
			std::cout << "Renderer successfully created-" << std::endl;
		}

		isRunning = true;
	}
	else
	{
		isRunning = false;
	}

	player = new GameObject("../gfx/character.png", 0, 0);
	map = new Map();
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
	{
		isRunning = false;
		break;
	}
	default:
		break;
	}
}

void Game::update()
{
	player->objUpdate();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	map->draw_map();
	player->objRender();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}
