#include "main.h"

//Main function
int main(int argc, char* args[])
{
	//Start SDL
	init();
	
	//Load media
	loadMedia();

	//setup title
	gTitle = Texture("..//media/title.bmp", gRenderer);
	gTitle.SetX(SCREEN_WIDTH / 2);
	gTitle.SetY(50);

	tBackground = Texture("..//media/background.bmp", gRenderer);
	
	
	//Assign each AI their own barracks, townhall, worker and associated resource
	//AI1---------------------------
	//Position and assign Townhall
	Townhall townhall = Townhall("..//media/townhall.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	townhall.SetX(0.0f);
	townhall.SetY(0.0f);
	townhall.owner = Owner::OWN_AI1;
	gameObjects.push_back(townhall);
	gameObjectsRef.push_back(&townhall);


	//Position and assign Barracks
	Barracks barracks = Barracks("..//media/barracks.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	barracks.SetSpeed(0.0f);
	barracks.SetX(0.0f);
	barracks.SetY(150.0f);
	barracks.owner = Owner::OWN_AI1;
	gameObjects.push_back(barracks);
	gameObjectsRef.push_back(&barracks);


	//Position resource
	Resource resource = Resource("..//media/resource.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	resource.SetX(200.0f);
	resource.SetY(100.0f);
	gameObjects.push_back(resource);
	gameObjectsRef.push_back(&resource);

	//Position and assign Worker
	Worker worker = Worker("..//media/worker.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	worker.SetX(0.0f);
	worker.SetY(150.0f);
	worker.owner = Owner::OWN_AI1;
	gameObjects.push_back(worker);
	gameObjectsRef.push_back(&worker);

	//-------------------------------
	//AI2----------------------------
	Townhall townhall2 = Townhall("..//media/townhall.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	townhall2.SetX(SCREEN_WIDTH - townhall2.GetWidth());
	townhall2.SetY(0.0f);
	townhall2.owner = Owner::OWN_AI2;
	gameObjects.push_back(townhall2);
	gameObjectsRef.push_back(&townhall2);


	Barracks barracks2 = Barracks("..//media/barracks.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	barracks2.SetSpeed(0.0f);
	barracks2.SetX(SCREEN_WIDTH - barracks2.GetWidth());
	barracks2.SetY(150.0f);
	barracks2.owner = Owner::OWN_AI2;
	gameObjects.push_back(barracks2);
	gameObjectsRef.push_back(&barracks2);


	Resource resource2 = Resource("..//media/resource.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	resource2.SetX(SCREEN_WIDTH - 200.0f);
	resource2.SetY(100.0f);
	gameObjects.push_back(resource2);
	gameObjectsRef.push_back(&resource2);

	Worker worker2 = Worker("..//media/worker.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	worker2.SetX(SCREEN_WIDTH - barracks2.GetWidth());
	worker2.SetY(150.0f);
	worker2.owner = Owner::OWN_AI2;
	gameObjects.push_back(worker2);
	gameObjectsRef.push_back(&worker2);

	//-------------------------------
	//AI3----------------------------
	Townhall townhall3 = Townhall("..//media/townhall.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	townhall3.SetX(0.0f);
	townhall3.SetY(SCREEN_HEIGHT - townhall3.GetHeight());
	townhall3.owner = Owner::OWN_AI3;
	gameObjects.push_back(townhall3);
	gameObjectsRef.push_back(&townhall3);


	Barracks barracks3 = Barracks("..//media/barracks.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	barracks3.SetSpeed(0.0f);
	barracks3.SetX(0.0f);
	barracks3.SetY(SCREEN_HEIGHT - barracks3.GetHeight() - 150.0f);
	barracks3.owner = Owner::OWN_AI3;
	gameObjects.push_back(barracks3);
	gameObjectsRef.push_back(&barracks3);


	Resource resource3 = Resource("..//media/resource.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	resource3.SetX(200.0f);
	resource3.SetY(SCREEN_HEIGHT - 100.0f);
	gameObjects.push_back(resource3);
	gameObjectsRef.push_back(&resource3);

	Worker worker3 = Worker("..//media/worker.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	worker3.SetX(0.0f);
	worker3.SetY(SCREEN_HEIGHT - barracks3.GetHeight() - 150.0f);
	worker3.owner = Owner::OWN_AI3;
	gameObjects.push_back(worker3);
	gameObjectsRef.push_back(&worker3);

	//-------------------------------
	//AI4----------------------------

	Townhall townhall4 = Townhall("..//media/townhall.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	townhall4.SetX(SCREEN_WIDTH - townhall4.GetWidth());
	townhall4.SetY(SCREEN_HEIGHT - townhall4.GetHeight());
	townhall4.owner = Owner::OWN_AI4;
	gameObjects.push_back(townhall4);
	gameObjectsRef.push_back(&townhall4);


	Barracks barracks4 = Barracks("..//media/barracks.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	barracks4.SetSpeed(0.0f);
	barracks4.SetX(SCREEN_WIDTH - barracks4.GetWidth());
	barracks4.SetY(SCREEN_HEIGHT - barracks4.GetHeight() - 150.0f);
	barracks4.owner = Owner::OWN_AI4;
	gameObjects.push_back(barracks4);
	gameObjectsRef.push_back(&barracks4);


	Resource resource4 = Resource("..//media/resource.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	resource4.SetX(SCREEN_WIDTH - 200.0f);
	resource4.SetY(SCREEN_HEIGHT - 100.0f);
	gameObjects.push_back(resource4);
	gameObjectsRef.push_back(&resource4);

	Worker worker4 = Worker("..//media/worker.bmp", gRenderer, &gameObjectsRef, &gameObjects);
	worker4.SetX(SCREEN_WIDTH - barracks4.GetWidth());
	worker4.SetY(SCREEN_HEIGHT - barracks4.GetHeight() - 150.0f);
	worker4.owner = Owner::OWN_AI4;
	gameObjects.push_back(worker4);
	gameObjectsRef.push_back(&worker4);

	fitness_ai1 = 0;
	fitness_ai2 = 0;
	fitness_ai3 = 0;
	fitness_ai4 = 0;

	GA_TIMER = 10000.0f;

	//-------------------------------

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
			//StoreRenderer(gRenderer);

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

	return success;
}

void Update()
{
	int vecSize = gameObjectsRef.size();
	for (int i = 0; i < vecSize; i++)
	{
		//Update all gameobjects that are still active.
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

	//Animate the title
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
	//Update all AIs.
	ai1.Update();
	ai2.Update();
	ai3.Update();
	ai4.Update();

	//Countdown to recombination.
	GA_TIMER--;
	if (GA_TIMER <= 0)
		CalcFitness();

}

//Calculate the Fitness of a candidate
//Priorities: Resources, then NoOfUnits, then NoOfSuccessfulEngagements
void CalcFitness()
{

	fitness_ai1 = ai1.GetNoOfResources();
	if (ai1.GetNoOfMyUnits() > 0)
		fitness_ai1 *= ai1.GetNoOfMyUnits();
	if (ai1.GetNoOfSuccessEngage() > 0)
		fitness_ai1 *= ai1.GetNoOfSuccessEngage();

	fitness_ai2 = ai2.GetNoOfResources();
	if (ai2.GetNoOfMyUnits() > 0)
		fitness_ai2 *= ai2.GetNoOfMyUnits();
	if (ai2.GetNoOfSuccessEngage() > 0)
		fitness_ai2 *= ai2.GetNoOfSuccessEngage();

	fitness_ai3 = ai3.GetNoOfResources();
	if (ai3.GetNoOfMyUnits() > 0)
		fitness_ai3 *= ai3.GetNoOfMyUnits();
	if (ai3.GetNoOfSuccessEngage() > 0)
		fitness_ai3 *= ai3.GetNoOfSuccessEngage();

	fitness_ai4 = ai4.GetNoOfResources();
	if (ai4.GetNoOfMyUnits() > 0)
		fitness_ai4 *= ai4.GetNoOfMyUnits();
	if (ai4.GetNoOfSuccessEngage() > 0)
		fitness_ai4 *= ai4.GetNoOfSuccessEngage();

	std::string s = "AI1 Fitness: ";
	s.append(std::to_string(fitness_ai1).c_str());
	char* debugOut = (char*)s.c_str();
	Debug_String(debugOut);

	PlotRoulette(2);
	
}

//Calculate each candidate's percentage share of the overall fitness
//and select a candidate using Roulette Wheel method.
void PlotRoulette(int noOfPicks)
{
	//Plot on Roulette wheel based on fitness

	AI* candidates[2];

	float fitnessSum = fitness_ai1 + fitness_ai2 + fitness_ai3 + fitness_ai4;
	
	float percentShare_ai1;
	float percentShare_ai2;
	float percentShare_ai3;
	float percentShare_ai4;

	percentShare_ai1 = (fitness_ai1 / fitnessSum) * 100;
	percentShare_ai2 = (fitness_ai2 / fitnessSum) * 100;
	percentShare_ai3 = (fitness_ai3 / fitnessSum) * 100;
	percentShare_ai4 = (fitness_ai4 / fitnessSum) * 100;

	for (int i = 0; i < noOfPicks; i++)
	{
		float selection = randf_ext(0.0f, 100.0f);
		if (selection < percentShare_ai1 && candidates[0] != &ai1)
		{
			//Select AI1
			candidates[i] = &ai1;
		}
		else if (selection < (percentShare_ai1 + percentShare_ai2) && candidates[0] != &ai2)
		{
			//Select AI2
			candidates[i] = &ai2;
		}
		else if (selection < (percentShare_ai1 + percentShare_ai2 + percentShare_ai3) && candidates[0] != &ai3)
		{
			//Select AI3
			candidates[i] = &ai3;
		}
		else if (selection < (percentShare_ai1 + percentShare_ai2 + percentShare_ai3 + percentShare_ai4) && candidates[0] != &ai4)
		{
			//Select AI4
			candidates[i] = &ai4;
		}
	}
	
	Recombine(candidates);
}

//Grab chromosome for each successful candidate and recombine them.
//Uses two-point crossover.
void Recombine(AI* _candidates[])
{
	std::vector<float> chromosome_cand1;
	std::vector<float> chromosome_cand2;

	chromosome_cand1 = _candidates[0]->WrapChromosome();
	chromosome_cand2 = _candidates[1]->WrapChromosome();

	int chromosomeLength = chromosome_cand1.size();
	int firstPoint = rand_range(0, chromosomeLength - 1);
	int secondPoint = rand_range(firstPoint, chromosomeLength - 1);


	std::vector<float> temp_chromosome_cand1;
	std::vector<float> temp_chromosome_cand2;

	//Get crossover points and snip genes.
	for (int i = firstPoint; i < secondPoint; i++)
	{
		temp_chromosome_cand1.push_back(chromosome_cand1.at(i));
		temp_chromosome_cand2.push_back(chromosome_cand2.at(i));
	}

	//Cross snipped genes into the other candidate.
	for (int j = firstPoint; j < secondPoint; j++)
	{
		chromosome_cand1.at(j) = temp_chromosome_cand2.at(j - firstPoint);
		chromosome_cand2.at(j) = temp_chromosome_cand1.at(j - firstPoint);
	}

	//Insert new genes into candidates.
	_candidates[0]->RAID_CHANCE = chromosome_cand1.at(0);
	_candidates[0]->RAID_COOLDOWN = chromosome_cand1.at(1);
	_candidates[0]->NO_OF_RAIDERS = chromosome_cand1.at(2);
	_candidates[0]->DECISION_CHANCE = chromosome_cand1.at(3);
	_candidates[0]->RETREAT_THRESHOLD = chromosome_cand1.at(4);
	_candidates[0]->NEWTARGET_CHANCE = chromosome_cand1.at(5);
	_candidates[0]->SPAWN_CHANCE_ARCHER = chromosome_cand1.at(6);
	_candidates[0]->SPAWN_CHANCE_KNIGHT = chromosome_cand1.at(7);
	_candidates[0]->SPAWN_CHANCE_SPEARMAN = chromosome_cand1.at(8);

	_candidates[1]->RAID_CHANCE = chromosome_cand2.at(0);
	_candidates[1]->RAID_COOLDOWN = chromosome_cand2.at(1);
	_candidates[1]->NO_OF_RAIDERS = chromosome_cand2.at(2);
	_candidates[1]->DECISION_CHANCE = chromosome_cand2.at(3);
	_candidates[1]->RETREAT_THRESHOLD = chromosome_cand2.at(4);
	_candidates[1]->NEWTARGET_CHANCE = chromosome_cand2.at(5);
	_candidates[1]->SPAWN_CHANCE_ARCHER = chromosome_cand2.at(6);
	_candidates[1]->SPAWN_CHANCE_KNIGHT = chromosome_cand2.at(7);
	_candidates[1]->SPAWN_CHANCE_SPEARMAN = chromosome_cand2.at(8);

	Mutate(_candidates);
}

//Mutate each candidate to prevent stale genetics.
//Mutation is controlled here because it could
//cause the AI to become unstable if a number is
//too high/low which would detract from the gameplay
//and may crash.
void Mutate(AI* _candidates[])
{
	std::vector<float> chromosome_cand1 = _candidates[0]->WrapChromosome();
	std::vector<float> chromosome_cand2 = _candidates[1]->WrapChromosome();

	int geneToMutate = rand_range(0, chromosome_cand1.size() - 1);
	switch (geneToMutate)
	{
	case 0:
	{
		//RAID_CHANCE
		chromosome_cand1.at(geneToMutate) = randf_ext(10.0f, 90.0f);
		chromosome_cand2.at(geneToMutate) = randf_ext(10.0f, 90.0f);
		break;
	}
	case 1:
	{
		//RAID_COOLDOWN
		chromosome_cand1.at(geneToMutate) = randf_ext(1000.0f, 5000.0f);
		chromosome_cand2.at(geneToMutate) = randf_ext(1000.0f, 5000.0f);
		break;
	}
	case 2:
	{
		//NO_OF_RAIDERS
		chromosome_cand1.at(geneToMutate) = randf_ext(2.0f, 10.0f);
		chromosome_cand2.at(geneToMutate) = randf_ext(2.0f, 10.0f);
		break;
	}
	case 3:
	{
		//DECISION_CHANCE
		chromosome_cand1.at(geneToMutate) = randf_ext(0.001f, 0.010f);
		chromosome_cand2.at(geneToMutate) = randf_ext(0.001f, 0.010f);
		break;
	}
	case 4:
	{
		//RETREAT_THRESHOLD
		chromosome_cand1.at(geneToMutate) = randf_ext(chromosome_cand1.at(2) + 1, chromosome_cand1.at(2) + 4);
		chromosome_cand2.at(geneToMutate) = randf_ext(chromosome_cand2.at(2) + 1, chromosome_cand2.at(2) + 4);
		break;
	}
	case 5:
	{
		//NEWTARGET_CHANCE
		chromosome_cand1.at(geneToMutate) = randf_ext(25.0f, 75.0f);
		chromosome_cand2.at(geneToMutate) = randf_ext(25.0f, 75.0f);
		break;
	}
	default:
		break;
	}

	_candidates[0]->RAID_CHANCE = chromosome_cand1.at(0);
	_candidates[0]->RAID_COOLDOWN = chromosome_cand1.at(1);
	_candidates[0]->NO_OF_RAIDERS = chromosome_cand1.at(2);
	_candidates[0]->DECISION_CHANCE = chromosome_cand1.at(3);
	_candidates[0]->RETREAT_THRESHOLD = chromosome_cand1.at(4);
	_candidates[0]->NEWTARGET_CHANCE = chromosome_cand1.at(5);
	_candidates[0]->SPAWN_CHANCE_ARCHER = chromosome_cand1.at(6);
	_candidates[0]->SPAWN_CHANCE_KNIGHT = chromosome_cand1.at(7);
	_candidates[0]->SPAWN_CHANCE_SPEARMAN = chromosome_cand1.at(8);

	_candidates[1]->RAID_CHANCE = chromosome_cand2.at(0);
	_candidates[1]->RAID_COOLDOWN = chromosome_cand2.at(1);
	_candidates[1]->NO_OF_RAIDERS = chromosome_cand2.at(2);
	_candidates[1]->DECISION_CHANCE = chromosome_cand2.at(3);
	_candidates[1]->RETREAT_THRESHOLD = chromosome_cand2.at(4);
	_candidates[1]->NEWTARGET_CHANCE = chromosome_cand2.at(5);
	_candidates[1]->SPAWN_CHANCE_ARCHER = chromosome_cand2.at(6);
	_candidates[1]->SPAWN_CHANCE_KNIGHT = chromosome_cand2.at(7);
	_candidates[1]->SPAWN_CHANCE_SPEARMAN = chromosome_cand2.at(8);

	GA_TIMER = 10000.0f;
	//Select a random gene and mutate it within safe limits.
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
		//Render all active gameobjects.
		if (gameObjectsRef.at(i)->GetActive() == true)
		{
			gameObjectsRef.at(i)->Render();
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

//Get Keyboard and Mouse input and operate logic
//based on input. Handles unit selection.
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

