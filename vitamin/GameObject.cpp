#include "GameObject.h"
#include "TextureManager.h"


GameObject::GameObject(const char * textureSheet, int x, int y)
{
	objTex = TextureManager::loadTexture(textureSheet);

	xpos = x;
	ypos = y;
}

void GameObject::objUpdate()
{
	xpos++;
	ypos++;
	
	//source
	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;
	//destination
	dstRect.x = xpos;
	dstRect.y = ypos;
	dstRect.w = srcRect.w * 2;
	dstRect.h = srcRect.h * 2;

}

void GameObject::objRender()
{
	SDL_RenderCopy(Game::renderer, objTex, &srcRect, &dstRect);
}

GameObject::~GameObject()
{
}
