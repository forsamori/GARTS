#include "Barracks.h"


Barracks::~Barracks()
{
}

void Barracks::SpawnUnit(ObjectType ot, std::vector<GameObject*>* aiUnits)
{
	
	//GameObject unit = GameObject("..//media/man.bmp", _renderer, _gameObjects);
	
	switch (ot)
	{
		case OT_UNIT_SPEARMAN:
		{
			gameObjects->push_back(Spearman("..//media/spearman.bmp", renderer, gameObjectsRef, gameObjects));
			break;
		}
		case OT_UNIT_ARCHER:
		{
			gameObjects->push_back(GameObject("..//media/archer.bmp", renderer, gameObjectsRef, gameObjects));
			break;
		}
		case OT_UNIT_KNIGHT:
		{
			gameObjects->push_back(GameObject("..//media/knight.bmp", renderer, gameObjectsRef, gameObjects));
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

	//Need to find a way of getting UnitManager to declare correctly. Could possibly use Helper Functions, though not sure.
	//The reason it broke was because of a circular dependency.
	//unitManager->SpawnUnit(unit);
	//_gameObjects->push_back(&unit); //Problem pushing GameObject into this list.
	//gameObjects->push_back(&unit);
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
