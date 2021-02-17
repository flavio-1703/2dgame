#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Entity.h"

class RenderWindow
{
public:
	RenderWindow(const char*, int, int);
	void clean_window();
	SDL_Texture* load_texture(const char* filePath);
	void clear();
	void render(Entity& _entity);
	void display();
	int getRefreshrate();
	~RenderWindow();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};

