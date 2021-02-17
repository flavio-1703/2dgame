#pragma once
#include "Game.h"

class TextureManager
{
public:
	TextureManager();
	static SDL_Texture* loadTexture(const char* fileName);
	static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dst);
	~TextureManager();
};

