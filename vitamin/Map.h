#pragma once
#include "Game.h"

class Map
{
public:
	Map();
	~Map();

	void load_map(int arrp[20][25]);
	void draw_map();

private:
	SDL_Rect src, dst;

	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;

	int map[20][25];
};

