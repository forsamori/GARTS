#ifndef _APPOLLO_H
#define _APPOLLO_H

//Appollo is a lightweight, games development framework created by Samuel Cumming.
//Appollo uses SDL 2.0 as a back-end and was built from the ground up for 'Genetic Algorithm Real-Time Strategy' (GARTS).
// VERSION: 0.0.1

//Includes
#include "SDL.h"
#include "APFRender.h"
#include "APFFileLoader.h"
#include <stdio.h>
#include <string>


class Appollo
{
public:
	int main(int argc, char * argv[]);
	int Init(int screenSizeX, int screenSizeY);
	void Update();
	void Render();
	void Terminate();

	class APFRender* apfRenderer;
	class APFFileLoader* apfFileLoader;

private:
	int screenSizeX;
	int screenSizeY;

	//Render Window
	SDL_Window* gWindow = NULL;

	//Window Surface (The surface we'll draw to)
	SDL_Surface* gScreenSurface = NULL;

	//Image to Render
	SDL_Surface* gHelloWorld = NULL;



};

#endif