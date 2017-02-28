#include "Barracks.h"


Barracks::~Barracks()
{
}

void Barracks::SpawnUnit()
{
	
	//GameObject unit = GameObject("..//media/man.bmp", _renderer, _gameObjects);
	GameObject unit = GameObject("..//media/man.bmp", renderer, gameObjects, unitManager);
	unit.SetSpeed(0.0f);
	unit.SetX(GetX());
	unit.SetY(GetY());
	unitManager->SpawnUnit(unit);
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
