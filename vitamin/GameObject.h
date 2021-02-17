#pragma once
#include "Game.h"

class GameObject
{
public:
	GameObject(const char* textureSheet, int x, int y);

	void objUpdate();
	void objRender();

	~GameObject();

private:
	int xpos;
	int ypos;
	SDL_Texture* objTex;
	SDL_Rect srcRect, dstRect;
	SDL_Renderer* renderer;
};

