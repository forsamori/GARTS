//#include "SDL.h"
#include "main.h"

int main(int argc, char* args[])
{
	//Start SDL
	//if (!appollo.Init(SCREEN_WIDTH, SCREEN_HEIGHT))
	//{
	//	printf("FAILED TO INITIALIZE!\n");
	//}
	
	//else
	//{
		//Load media
		gHelloWorld = appollo.apfFileLoader->LoadBMP("C:/Users/Sam/Pictures/lol.bmp");
		appollo.apfRenderer->renderSprite(gHelloWorld, gScreenSurface, gWindow);
	
			//Apply image
			//SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
			//Update surface
			//SDL_UpdateWindowSurface(gWindow);
			//Wait two secs
			SDL_Delay(2000);
		
	//}
	
	close();
	return 0;
}

bool init()
{
	//Success Flag
	bool success = true;

	//Initialise SDL 
	if (SDL_Init(SDL_INIT_VIDEO) < 0) //Init fail
	{
		printf("SDL could not initialize! SDL_ERROR: %s\n", SDL_GetError());
		success = false;
	}
	else //INIT SUCCESS
	{
		//Create window
		gWindow = SDL_CreateWindow("GARTS", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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

bool loadMedia()
{
	//Loading success
	bool success = true;

	

	//Load splash image
	gHelloWorld = SDL_LoadBMP("C:/Users/Sam/Pictures/lol.bmp");
	if (gHelloWorld == NULL) //Unable to load image
	{
		printf("Unable to load image %s! SDL_ERROR: %s\n", "C:/Users/Sam/Pictures/lol.bmp", SDL_GetError());
		success = false;
	}
	return success;
}

void close()
{
	//Deallocate surface
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}