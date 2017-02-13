#include "Barracks.h"


Barracks::~Barracks()
{
}

void Barracks::SpawnUnit()
{
}

void Barracks::Update()
{
	if (IsSelected())
	{
		Debug_String("Barracks is now selected");
	}

	GameObject::Update();
}
