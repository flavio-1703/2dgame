#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Entity
{
public:
	Entity(float, float, SDL_Texture* );
	float getX();
	float getY();
	SDL_Texture* getText();
	//Lol :)
	SDL_Rect getRect();
	~Entity();
private:
	float x, y;
	SDL_Rect currFrame;
	SDL_Texture* texture;
};

