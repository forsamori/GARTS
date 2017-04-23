#include "main.h"

//TODO: FutureSam: The mouse is crashing the game
//When you select anywhere, it corrupts a unit.
//Fix it. Fix it now. Pretty please.

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
	
	
	//AI1---------------------------
	Townhall townhall = Townhall("..//media/townhall.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	townhall.SetX(0.0f);
	townhall.SetY(0.0f);
	gameObjects.push_back(townhall);
	gameObjectsRef.push_back(&townhall);
	townhall.owner = OWN_AI1;

	Barracks barracks = Barracks("..//media/barracks.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	barracks.SetSpeed(0.0f);
	barracks.SetX(0.0f);
	barracks.SetY(150.0f);
	gameObjects.push_back(barracks);
	gameObjectsRef.push_back(&barracks);
	barracks.owner = OWN_AI1;

	Resource resource = Resource("..//media/resource.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	resource.SetX(200.0f);
	resource.SetY(100.0f);
	gameObjects.push_back(resource);
	gameObjectsRef.push_back(&resource);

	Worker worker = Worker("..//media/worker.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	worker.SetX(0.0f);
	worker.SetY(150.0f);
	gameObjects.push_back(worker);
	gameObjectsRef.push_back(&worker);
	worker.owner = OWN_AI1;
	//-------------------------------
	//AI2----------------------------
	Townhall townhall2 = Townhall("..//media/townhall.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	townhall2.SetX(SCREEN_WIDTH - townhall2.GetWidth());
	townhall2.SetY(0.0f);
	gameObjects.push_back(townhall2);
	gameObjectsRef.push_back(&townhall2);
	townhall2.owner = OWN_AI2;

	Barracks barracks2 = Barracks("..//media/barracks.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	barracks2.SetSpeed(0.0f);
	barracks2.SetX(SCREEN_WIDTH - barracks2.GetWidth());
	barracks2.SetY(150.0f);
	gameObjects.push_back(barracks2);
	gameObjectsRef.push_back(&barracks2);
	barracks2.owner = OWN_AI2;

	Resource resource2 = Resource("..//media/resource.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	resource2.SetX(SCREEN_WIDTH - 200.0f);
	resource2.SetY(100.0f);
	gameObjects.push_back(resource2);
	gameObjectsRef.push_back(&resource2);

	Worker worker2 = Worker("..//media/worker.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	worker2.SetX(SCREEN_WIDTH - barracks2.GetWidth());
	worker2.SetY(150.0f);
	gameObjects.push_back(worker2);
	gameObjectsRef.push_back(&worker2);
	worker2.owner = OWN_AI2;
	//-------------------------------
	//AI3----------------------------
	Townhall townhall3 = Townhall("..//media/townhall.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	townhall3.SetX(0.0f);
	townhall3.SetY(SCREEN_HEIGHT - townhall3.GetHeight());
	gameObjects.push_back(townhall3);
	gameObjectsRef.push_back(&townhall3);
	townhall3.owner = OWN_AI3;

	Barracks barracks3 = Barracks("..//media/barracks.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	barracks3.SetSpeed(0.0f);
	barracks3.SetX(0.0f);
	barracks3.SetY(SCREEN_HEIGHT - barracks3.GetHeight() - 150.0f);
	gameObjects.push_back(barracks3);
	gameObjectsRef.push_back(&barracks3);
	barracks3.owner = OWN_AI3;

	Resource resource3 = Resource("..//media/resource.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	resource3.SetX(200.0f);
	resource3.SetY(SCREEN_HEIGHT - 100.0f);
	gameObjects.push_back(resource3);
	gameObjectsRef.push_back(&resource3);

	Worker worker3 = Worker("..//media/worker.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	worker3.SetX(0.0f);
	worker3.SetY(SCREEN_HEIGHT - barracks3.GetHeight() - 150.0f);
	gameObjects.push_back(worker3);
	gameObjectsRef.push_back(&worker3);
	worker3.owner = OWN_AI3;
	//-------------------------------
	//AI4----------------------------

	Townhall townhall4 = Townhall("..//media/townhall.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	townhall4.SetX(SCREEN_WIDTH - townhall4.GetWidth());
	townhall4.SetY(SCREEN_HEIGHT - townhall4.GetHeight());
	gameObjects.push_back(townhall4);
	gameObjectsRef.push_back(&townhall4);
	townhall4.owner = OWN_AI4;

	Barracks barracks4 = Barracks("..//media/barracks.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	barracks4.SetSpeed(0.0f);
	barracks4.SetX(SCREEN_WIDTH - barracks4.GetWidth());
	barracks4.SetY(SCREEN_HEIGHT - barracks4.GetHeight() - 150.0f);
	gameObjects.push_back(barracks4);
	gameObjectsRef.push_back(&barracks4);
	barracks4.owner = OWN_AI4;

	Resource resource4 = Resource("..//media/resource.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	resource4.SetX(SCREEN_WIDTH - 200.0f);
	resource4.SetY(SCREEN_HEIGHT - 100.0f);
	gameObjects.push_back(resource4);
	gameObjectsRef.push_back(&resource4);

	Worker worker4 = Worker("..//media/worker.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	worker4.SetX(SCREEN_WIDTH - barracks4.GetWidth());
	worker4.SetY(SCREEN_HEIGHT - barracks4.GetHeight() - 150.0f);
	gameObjects.push_back(worker4);
	gameObjectsRef.push_back(&worker4);
	worker4.owner = OWN_AI4;
	//-------------------------------
	//ai1 = AI(&gameObjectsRef, &gameObjects, OWN_AI1);








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

	int vecSize = gameObjectsRef.size();
	for (int i = 0; i < vecSize; i++)
	{
		if (gameObjectsRef.at(i)->GetActive() == true)
		{
			gameObjectsRef.at(i)->Update();
		}
		//Check if the size of the array has changed
		int newVecSize = gameObjectsRef.size();
		if (newVecSize != vecSize)
		{
			vecSize = newVecSize;
		}
	}

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
	ai1.Update();
	ai2.Update();
	ai3.Update();
	ai4.Update();
}

void Render()
{
	//Clear screen
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(gRenderer);

	//Assets to render
	tBackground.Render();

	gTitle.Render();

	int vecSize = gameObjectsRef.size();
	for (int i = 0; i < vecSize; i++)
	{
		if (gameObjectsRef.at(i)->GetActive() == true)
		{
			gameObjectsRef.at(i)->Render(/*Put a pointer to SDL_Renderer here to save memory (Harry said so)*/);
		}
	}
	//----

	if (mouseDown == true)
	{
		SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_Rect mouseRect;
		mouseRect.x = clickStart.x;
		mouseRect.y = clickStart.y;
		mouseRect.w = clickCurrent.x - clickStart.x;
		mouseRect.h = clickCurrent.y - clickStart.y;
		SDL_RenderDrawRect(gRenderer, &mouseRect);
		SDL_RenderPresent(gRenderer);
	}




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
				//sMan.SetY(sMan.GetY() - 1);
				if (!selection.GetSelection()->empty())
				{	
					GameObject* obj = selection.GetSelection()->front();
					obj->SetY(obj->GetY() - 1);
				}
				break;
			case SDLK_DOWN:
				Debug_String("Pressed: ARROW_DOWN");
				//sMan.SetY(sMan.GetY() + 1);
				if (!selection.GetSelection()->empty())
				{
					GameObject* obj = selection.GetSelection()->front();
					obj->SetY(obj->GetY() + 1);
				}
				break;
			case SDLK_LEFT:
				Debug_String("Pressed: ARROW_LEFT");
				//sMan.SetX(sMan.GetX() - 1);
				if (!selection.GetSelection()->empty())
				{
					GameObject* obj = selection.GetSelection()->front();
					obj->SetX(obj->GetX() - 1);
				}
				break;
			case SDLK_RIGHT:
				Debug_String("Pressed: ARROW_RIGHT");
				//sMan.SetX(sMan.GetX() + 1);
				if (!selection.GetSelection()->empty())
				{
					GameObject* obj = selection.GetSelection()->front();
					obj->SetX(obj->GetX() + 1);
				}
				break;
			case SDLK_s:
				if (!selection.GetSelection()->empty())
				{
					GameObject* obj = selection.GetSelection()->front();
					obj->beginSpawn = true;
				}
				break;
			}
		}
		else if (_event.type == SDL_MOUSEBUTTONDOWN)
		{
			if (mouseDown == false)
			{
				clickStart.x = _event.button.x;
				clickStart.y = _event.button.y;
			}
			mouseDown = true;
			
			clickCurrent.x = _event.button.x;
			clickCurrent.y = _event.button.y;
			//selection.Select(_event.button.x, _event.button.y, &gameObjects);
			//test_object.MoveToPoint(_event.button.x, _event.button.y);
		}
		else if (_event.type == SDL_MOUSEBUTTONUP)
		{
			mouseDown = false;
			if (mouseDownTime > MOUSE_DOWN_THRESHOLD)
			{
				selection.BoxSelect(clickStart, clickCurrent, &gameObjectsRef);
			}
			else
				selection.Select(_event.button.x, _event.button.y, &gameObjectsRef);
			Debug_String("Releasing MOUSE1");
			mouseDownTime = 0.0f;
		}

		if (mouseDown == true)
		{
			mouseDownTime += 0.1f;
			
			std::string s = "MouseDownTime: ";
			s.append(std::to_string(mouseDownTime).c_str());
			char* debugOut = (char*)s.c_str();
			
			Debug_String(debugOut);
			if (_event.type == SDL_MOUSEMOTION)
			{
				clickCurrent.x = _event.button.x;
				clickCurrent.y = _event.button.y;
			}
		}
	}
}

/*void SpawnUnit(GameObject spawnObject)
{
	gameObjects.push_back(spawnObject);
	gameObjectsRef.push_back(&spawnObject);
}*/