#include "Barracks.h"


Barracks::~Barracks()
{
}

void Barracks::SpawnUnit()
{
	
	//GameObject unit = GameObject("..//media/man.bmp", _renderer, _gameObjects);
	
	gameObjects->push_back(MilitaryUnit("..//media/man.bmp", renderer, gameObjectsRef, gameObjects));
	gameObjects->back().SetSpeed(0.1f);
	gameObjects->back().SetX(GetX() + randf_ext(0.0f, 25.0f));
	gameObjects->back().SetY(GetY() + randf_ext(0.0f, 25.0f));
	gameObjects->back().owner = owner;
	gameObjectsRef->push_back(&gameObjects->back());

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
			SpawnUnit();
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
