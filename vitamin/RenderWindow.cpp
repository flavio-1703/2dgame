#include "RenderWindow.h"
#include "Entity.h"
#include <iostream>


RenderWindow::RenderWindow(const char* title, int width, int height)
{
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		std::cout << "Window failed to init" << SDL_GetError() << std::endl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture * RenderWindow::load_texture(const char * filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, filePath);

	if (texture == NULL)
	{
		std::cout << "Error (Failed to load texture): " << SDL_GetError() << std::endl;
	}

	return texture;
		
}

void RenderWindow::clear()
{
	SDL_RenderClear(renderer);
}

void RenderWindow::render(Entity& _entity)
{
	//texture position and size
	SDL_Rect src;
	src.x = _entity.getRect().x;
	src.y = _entity.getRect().y;
	src.w = _entity.getRect().w;
	src.h = _entity.getRect().h;

	SDL_Rect dst;
	dst.x = _entity.getX();
	dst.y = _entity.getY();
	dst.w = _entity.getRect().w;
	dst.h = _entity.getRect().h;

	SDL_RenderCopy(renderer, _entity.getText(), &src, &dst);
}

void RenderWindow::display()
{
	SDL_RenderPresent(renderer);
}

int RenderWindow::getRefreshrate()
{
	int displayIndex = SDL_GetWindowDisplayIndex(window);
	SDL_DisplayMode mode;
	SDL_GetDisplayMode(displayIndex, 0, &mode);
	return mode.refresh_rate;
}


void RenderWindow::clean_window()
{
	SDL_DestroyWindow(window);
}

RenderWindow::~RenderWindow()
{
}
