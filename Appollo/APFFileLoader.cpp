#include "APFFileLoader.h"

SDL_Surface* APFFileLoader::LoadBMP(char* filePath)
{
	SDL_Surface* sdlSurface = SDL_LoadBMP(filePath);
	if (sdlSurface == NULL) //Unable to load image
	{
		printf("Unable to load image %s! SDL_ERROR: %s\n", filePath, SDL_GetError());
		return 0;
	}
	return sdlSurface; //Complete
}
