#include "Worker.h"

Worker::~Worker()
{
}

void Worker::Update()
{

	//CONTINUE WORKING ON RESOURCE ALLOCATION AND BASIC AI

	for (int i = 0; i < gameObjectsRef->size(); i++)
	{
		if (AABBCollision(this, gameObjectsRef->at(i)))
		{
			if (gameObjectsRef->at(i)->OT == OT_RESOURCE && hasResources == false)
			{
				Resource* resource = (Resource*)gameObjectsRef->at(i);
				resourceCarrying = resource->Harvest();
				hasResources = true;
			}

			if (gameObjectsRef->at(i)->OT == OT_TOWNHALL)
			{
				if (hasResources == true)
				{
					//ADD RESOURCES TO PLAYER'S COUNT
					//hasResources = false;
				}
			}

		}
	}
	//Execute generic GameObject update
	GameObject::Update();
}


void Worker::Render()
{


	//Execute generic GameObject render
	GameObject::Render();
}

