#include "Barracks.h"


Barracks::~Barracks()
{
}

//Spawn a unit and add it to this AI's units.
void Barracks::SpawnUnit(ObjectType ot, std::vector<GameObject*>* aiUnits)
{
	bool dontSpawn = false;
	//GameObject unit = GameObject("..//media/man.bmp", _renderer, _gameObjects);
	GameObject* newUnit = nullptr;
	for (int i = 0; i < gameObjectsRef->size(); i++)
	{
		if (gameObjectsRef->at(i)->OT == ObjectType::OT_BARRACKS)
		{
			if (gameObjectsRef->at(i)->currentlySpawning == true)
			{
				dontSpawn = true;
			}
		}
	}
	if (dontSpawn == false)
	{
		currentlySpawning = true;
		switch (ot)
		{
		case ObjectType::OT_UNIT_SPEARMAN:
		{
			std::string unitArt;
			if (owner == Owner::OWN_AI1)
			{
				unitArt = "..//media/spearman_red.bmp";
			}
			else if (owner == Owner::OWN_AI2)
			{
				unitArt = "..//media/spearman_blue.bmp";
			}
			else if (owner == Owner::OWN_AI3)
			{
				unitArt = "..//media/spearman_green.bmp";
			}
			else if (owner == Owner::OWN_AI4)
			{
				unitArt = "..//media/spearman_yellow.bmp";
			}
			else if (owner == Owner::OWN_P1)
			{
				unitArt = "..//media/spearman_black.bmp";
			}
			gameObjects->push_back(Spearman(unitArt, renderer, gameObjectsRef, gameObjects));
			//newUnit = &gameObjects->back();
			//gameObjects->push_back(Spearman(unitArt, renderer, gameObjectsRef, gameObjects));
			//newUnit = gameObjects->back();
			break;
		}
		case ObjectType::OT_UNIT_ARCHER:
		{
			gameObjects->push_back(GameObject("..//media/archer.bmp", renderer, gameObjectsRef, gameObjects));
			//newUnit = &gameObjects->back();
			//newUnit = Archer("..//media/archer.bmp", renderer, gameObjectsRef, gameObjects);
			break;
		}
		case ObjectType::OT_UNIT_KNIGHT:
		{
			gameObjects->push_back(GameObject("..//media/knight.bmp", renderer, gameObjectsRef, gameObjects));
			//newUnit = &gameObjects->back();
			//newUnit = Knight("..//media/knight.bmp", renderer, gameObjectsRef, gameObjects);
			break;
		}

		}
		
		gameObjects->back().SetSpeed(0.1f);
		gameObjects->back().SetX(GetX() + randf_ext(0.0f, 50.0f));
		gameObjects->back().SetY(GetY() + randf_ext(0.0f, 50.0f));
		gameObjects->back().owner = owner;
		gameObjects->back().unitHome = this;
		gameObjects->back().SetActive();
		gameObjectsRef->push_back(&gameObjects->back());
		aiUnits->push_back(&gameObjects->back());

		currentlySpawning = false;
		Debug_String("Spawning!");
	}
}

//Called by baseclass (GameObject)
void Barracks::Update()
{


	if (IsSelected() || spawnButton.IsSelected())
	{
		//spawnButton.SetX(GetX());
		//spawnButton.SetY(GetY());
		//spawnButton.Update();
		//Debug_String("Barracks is now selected");
		if (beginSpawn)
		{
			//SpawnUnit(); <---This one.
			beginSpawn = false;
		}
		//SpawnUnit();
	}

	//Execute generic GameObject update
	GameObject::Update();
}

//Called by baseclass (GameObject)
void Barracks::Render()
{
	//Execute generic GameObject render
	GameObject::Render();

	if (IsSelected() || spawnButton.IsSelected())
	{
		barracksUnit.Render();
	}

	
}
