#include "APFRender.h"

int APFRender::renderSprite(SDL_Surface* sprite, SDL_Surface* screenSurf, SDL_Window* window)
{
	//TODO: Add catch for bad render/errors and return 0 if any encoutered.

	//Apply image
	SDL_BlitSurface(sprite, NULL, screenSurf, NULL);
	//Update surface
	SDL_UpdateWindowSurface(window);
	return 1;
}
