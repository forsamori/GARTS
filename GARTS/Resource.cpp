#include "Resource.h"

Resource::~Resource()
{
}

int Resource::Harvest()
{
	resourceRemaining -= harvestAmount;
	return harvestAmount;
}

void Resource::Update()
{
	
	/*for (int i = 0; i < gameObjectsRef->size(); i++)
	{
		if (AABBCollision(this, gameObjectsRef->at(i)))
		{
			if (gameObjectsRef->at(i)->OT == OT_RESOURCE)

		}
	}*/
	//Execute generic GameObject update
	GameObject::Update();
}


void Resource::Render()
{

	if (resourceRemaining >= 0)
	{//HACK
	//Execute generic GameObject render
		GameObject::Render();
	}
}

int Resource::GetResourcesRemaining()
{
	return resourceRemaining;
}
