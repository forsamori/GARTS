#include "Barracks.h"


Barracks::~Barracks()
{
}

void Barracks::SpawnUnit()
{
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
