#include "Entity.h"

Entity::Entity(float xpos, float ypos, SDL_Texture * text)
:x(xpos), y(ypos), texture(text)
{
	currFrame.x = 0;
	currFrame.y = 0;
	currFrame.w = 32;
	currFrame.h = 32;
}

float Entity::getX()
{
	return this->x;
}

float Entity::getY()
{
	return this->y;
}

SDL_Texture * Entity::getText()
{
	return this->texture;
}

SDL_Rect Entity::getRect()
{
	return this->currFrame;
}

Entity::~Entity()
{
}
