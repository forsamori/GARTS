#ifndef _APFRENDER_H
#define _APFRENDER_H

#include "Appollo.h"

class APFRender
{
public:
	int renderSprite(SDL_Surface* sprite, SDL_Surface* screenSurf, SDL_Window* window);
};

#endif