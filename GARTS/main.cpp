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

	test_object = GameObject("..//media/test.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	test_object.SetSpeed(0.02f);
	test_object.SetX(100.0f);
	test_object.SetY(50.0f);
	//Add to GameObject member vector.
	gameObjects.push_back(test_object);
	gameObjectsRef.push_back(&test_object);

	test_object2 = GameObject("..//media/test.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	test_object2.SetSpeed(0.02f);
	test_object2.SetX(500.0f);
	test_object2.SetY(200.0f);
	gameObjects.push_back(test_object2);
	gameObjectsRef.push_back(&test_object2);

	test_object3 = GameObject("..//media/test.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	test_object3.SetSpeed(0.02f);
	test_object3.SetX(300.0f);
	test_object3.SetY(400.0f);
	gameObjects.push_back(test_object3);
	gameObjectsRef.push_back(&test_object3);

	
	Barracks barracks = Barracks("..//media/barracks.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	barracks.SetSpeed(0.0f);
	barracks.SetX(400.0f);
	barracks.SetY(700.0f);
	gameObjects.push_back(barracks);
	gameObjectsRef.push_back(&barracks);
	barracks.owner = OWN_AI1;

	Barracks barracks2 = Barracks("..//media/barracks.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	barracks2.SetSpeed(0.0f);
	barracks2.SetX(400.0f);
	barracks2.SetY(100.0f);
	gameObjects.push_back(barracks2);
	gameObjectsRef.push_back(&barracks2);
	barracks2.owner = OWN_AI2;

	Resource resource = Resource("..//media/resource.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	resource.SetX(200.0f);
	resource.SetY(100.0f);
	gameObjects.push_back(resource);
	gameObjectsRef.push_back(&resource);

	Resource resource2 = Resource("..//media/resource.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	resource2.SetX(500.0f);
	resource2.SetY(100.0f);
	gameObjects.push_back(resource2);
	gameObjectsRef.push_back(&resource2);


	Worker worker = Worker("..//media/worker.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	worker.SetX(100.0f);
	worker.SetY(300.0f);
	gameObjects.push_back(worker);
	gameObjectsRef.push_back(&worker);
	worker.owner = OWN_AI1;

	MilitaryUnit milUnit1 = MilitaryUnit("..//media/workerCarry.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	MilitaryUnit milUnit2 = MilitaryUnit("..//media/workerCarry.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	
	milUnit1.SetX(100.0f);
	milUnit1.SetY(300.0f);
	gameObjects.push_back(milUnit1);
	gameObjectsRef.push_back(&milUnit1);
	milUnit1.currentTarget = &milUnit2;

	milUnit2.SetX(700.0f);
	milUnit2.SetY(300.0f);
	gameObjects.push_back(milUnit2);
	gameObjectsRef.push_back(&milUnit2);
	milUnit2.currentTarget = &milUnit1;
	


	Townhall townhall = Townhall("..//media/townhall.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	townhall.SetX(400.0f);
	townhall.SetY(600.0f);
	gameObjects.push_back(townhall);
	gameObjectsRef.push_back(&townhall);
	townhall.owner = OWN_AI1;

	Worker worker2 = Worker("..//media/worker.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	worker2.SetX(100.0f);
	worker2.SetY(300.0f);
	gameObjects.push_back(worker2);
	gameObjectsRef.push_back(&worker2);
	worker2.owner = OWN_AI2;


	Townhall townhall2 = Townhall("..//media/townhall.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	townhall2.SetX(600.0f);
	townhall2.SetY(200.0f);
	gameObjects.push_back(townhall2);
	gameObjectsRef.push_back(&townhall2);
	townhall2.owner = OWN_AI2;

	Worker worker3 = Worker("..//media/worker.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	worker3.SetX(100.0f);
	worker3.SetY(300.0f);
	gameObjects.push_back(worker3);
	gameObjectsRef.push_back(&worker3);
	worker3.owner = OWN_AI3;


	Townhall townhall3 = Townhall("..//media/townhall.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	townhall3.SetX(800.0f);
	townhall3.SetY(300.0f);
	gameObjects.push_back(townhall3);
	gameObjectsRef.push_back(&townhall3);
	townhall3.owner = OWN_AI3;

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
	sMan.Update();
	//test_object.Update();
	int vecSize = gameObjectsRef.size();
	for (int i = 0; i < vecSize; i++)
	{
		gameObjectsRef.at(i)->Update();
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
	//ai2.Update();
	//ai3.Update();
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

	int vecSize = gameObjectsRef.size();
	for (int i = 0; i < vecSize; i++)
	{
		gameObjectsRef.at(i)->Render(/*Put a pointer to SDL_Renderer here to save memory (Harry said so)*/);
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