#include "main.h"

int main(int argc, char* args[])
{
	//Start SDL
	init();
	
	//Load media
	loadMedia();


	gTitle = Texture("..//media/title.bmp", gRenderer);
	gTitle.SetX(SCREEN_WIDTH / 2);
	gTitle.SetY(50);

	tBackground = Texture("..//media/background.bmp", gRenderer);

	sMan = Sprite("..//media/man.bmp", gRenderer);


	
	//Main loop
	while (!quit)
	{
		//Poll, process input.
		Input();
		
		//Update gameobjects/perform logic.
		Update();

		//Render all renderable textures/sprites/objects.
		Render();

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
			//gScreenSurface = SDL_GetWindowSurface(gWindow);

			//Create a renderer that will use the graphics card.
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
		}
	}
	return success;
}

bool loadMedia()
{
	//Loading success
	bool success = true;

	//Load splash image
	gBackground = SDL_LoadBMP("..//media/background.bmp");
	if (gBackground == NULL) //Unable to load image
	{
		printf("Unable to load image %s! SDL_ERROR: %s\n", "..//media/background.bmp", SDL_GetError());
		success = false;
	}

	//Load title image
	//gTitle = SDL_LoadBMP("..//media/title.bmp");
	//if (gBackground == NULL)
	//{
	//	printf("Unable to load image %s! SDL_ERROR: %s\n", "..//media/title.bmp", SDL_GetError());
	//	success = false;
	//}

	return success;
}

void Update()
{
	sMan.Update();

	//Prevent redeclaration in loop using STATIC
	static float lerpval = 0.0f;
	static bool lerpreverse = false;

	if (lerpval <= 1.0f && lerpreverse == false)
	{
		gTitle.SetAngle(Lerp(lerpval, -10, 10));
		lerpval += 0.001f;
	}
	else
	{
		lerpreverse = true;
	}

	if (lerpval >= 0.0f && lerpreverse == true)
	{
		gTitle.SetAngle(Lerp(lerpval, -10, 10));
		lerpval -= 0.001f;
	}
	else
	{
		lerpreverse = false;
	}
}

void Render()
{
	//Clear screen
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(gRenderer);

	//Assets to render
	tBackground.Render();

	gTitle.Render();

	sMan.Render();
	//----

	//Render using desired renderer
	SDL_RenderPresent(gRenderer);
}

void close()
{
	//Deallocate surface
	SDL_FreeSurface(gBackground);
	gBackground = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

void Input()
{
	//Poll for events
	//While events available
	while (SDL_PollEvent(&_event) != 0)
	{
		if (_event.type == SDL_QUIT)
		{
			quit = true;
			Debug_String("Quitting");
		}
		else if (_event.type == SDL_KEYDOWN)
		{
			switch (_event.key.keysym.sym)
			{
			case SDLK_UP:
				Debug_String("Pressed: ARROW_UP");
				sMan.SetY(sMan.GetY() - 1);
				break;
			case SDLK_DOWN:
				Debug_String("Pressed: ARROW_DOWN");
				sMan.SetY(sMan.GetY() + 1);
				break;
			case SDLK_LEFT:
				Debug_String("Pressed: ARROW_LEFT");
				sMan.SetX(sMan.GetX() - 1);
				break;
			case SDLK_RIGHT:
				Debug_String("Pressed: ARROW_RIGHT");
				sMan.SetX(sMan.GetX() + 1);
				break;
			}
		}
	}
}