#include "main.h"

int main(int argc, char* args[])
{
	//Start SDL
	init();
	
	//Load media
	loadMedia();


	//Main loop
	while (!quit)
	{
		//REMEMBER: Have the update and input functions act sensibly. Take input before...
		//...update, which must be called second last before draw.
		//TODO: Add input polling here
		//Poll for events
		//While events available
		while (SDL_PollEvent(&_event) != 0)
		{
			if (_event.type == SDL_QUIT)
			{
				quit = true;
				Debug_String("Quitting");
			}
		}


		//TODO: Add draw function, add relevant draws there
		//Apply image
		SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
		//Update surface
		SDL_UpdateWindowSurface(gWindow);
		//Wait two secs
		//SDL_Delay(2000);

		//Do necessary clean-up (shouldn't be done often, but keeping it all...
		//...in one place will be easier for maintenance.
	}
	close();
	return 0;
}

bool init()
{

	//Control vars
	quit = false;

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

void Debug_String(char* string)
{
	std::wostringstream out_stream;
	out_stream << string;
	out_stream << "\n\n";
	OutputDebugStringW(out_stream.str().c_str());
}