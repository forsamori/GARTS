#include "Appollo.h"

//BUG0001: So we have a pretty big issue here.
//Appollo needs to interact with SDL_main correctly.
//SDL_main expects a particular signature to latch onto (int main(int argc, char *argv[]))
//otherwise it will throw: LNK2019	unresolved external symbol _SDL_main referenced in function _main_utf8

//For appollo to work as a framework, it looks like we need to tap into appollo's main loop
//and force it to wait for GARTS commands. Anyway, a little bit of reading into a class-based, engine-like
//sdl implementation may be necessary.

int Appollo::main(int argc, char *argv[])
{
	//Success Flag
	bool success = true;
	screenSizeX = 640;
	screenSizeY = 480;

	//Initialise SDL 
	if (SDL_Init(SDL_INIT_VIDEO) < 0) //Init fail
	{
		printf("SDL could not initialize! SDL_ERROR: %s\n", SDL_GetError());
		success = false;
	}
	else //INIT SUCCESS
	{
		//Create window
		gWindow = SDL_CreateWindow("GARTS", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenSizeX, screenSizeY, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get Window Surface so we can draw on the window.
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}
	return success;
}

int Appollo::Init(int screenSizeX_, int screenSizeY_)
{
	//Success Flag
	bool success = true;
	screenSizeX = screenSizeX_;
	screenSizeY = screenSizeY_;

	//Initialise SDL 
	if (SDL_Init(SDL_INIT_VIDEO) < 0) //Init fail
	{
		printf("SDL could not initialize! SDL_ERROR: %s\n", SDL_GetError());
		success = false;
	}
	else //INIT SUCCESS
	{
		//Create window
		gWindow = SDL_CreateWindow("GARTS", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenSizeX, screenSizeY, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get Window Surface so we can draw on the window.
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}
	return success;
	
}

void Appollo::Update()
{
}

void Appollo::Render()
{
	//apfRenderer->renderSprite()
}

void Appollo::Terminate()
{
}
