#include "TextureManager.h"



TextureManager::TextureManager()
{
}

SDL_Texture * TextureManager::loadTexture(const char * fileName)
{
	SDL_Surface* tempSurface = IMG_Load(fileName);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	return tex;
}

void TextureManager::Draw(SDL_Texture * tex, SDL_Rect src, SDL_Rect dst)
{
	SDL_RenderCopy(Game::renderer, tex, &src, &dst);
}


TextureManager::~TextureManager()
{
}
