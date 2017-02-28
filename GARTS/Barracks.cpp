#include "Barracks.h"


Barracks::~Barracks()
{
}

void Barracks::SpawnUnit()
{
	//GameObject unit = GameObject("..//media/man.bmp", _renderer, _gameObjects);
	GameObject unit = GameObject("..//media/man.bmp", renderer, gameObjects);
	unit.SetSpeed(0.0f);
	unit.SetX(GetX());
	unit.SetY(GetY());
	//_gameObjects->push_back(&unit); //Problem pushing GameObject into this list.
	gameObjects->push_back(unit);
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
		//if (barracksUnit.IsSelected() == true)
		//{
		static bool do_once = false;
		if (do_once == false)
		{
			SpawnUnit();
			do_once = true;
		}
		//}
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
