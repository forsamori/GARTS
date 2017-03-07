#include "Worker.h"

Worker::~Worker()
{
}

void Worker::Update()
{

	//Worker is getting stuck on rock. Check states, debug.

	if (worker_state == WS_COLLECT_GOTO || worker_state == WS_COLLECT_RETURN)
	{
		for (int i = 0; i < gameObjectsRef->size(); i++)
		{
			if (AABBCollision(this, gameObjectsRef->at(i)))
			{
				if (worker_state == WS_COLLECT_GOTO)
				{
					if (gameObjectsRef->at(i)->OT == OT_RESOURCE && hasResources == false)
					{
						Resource* resource = (Resource*)gameObjectsRef->at(i);
						resourceCarrying = resource->Harvest();
						hasResources = true;
						//SetSprite(defaultSprite);
						worker_state = WS_COLLECT_RETURN;
						
					}
				}
				else if (worker_state == WS_COLLECT_RETURN)
				{
					//SetSprite(&carrySprite);
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
		}
	}
	CollectCycle();
	//Execute generic GameObject update
	GameObject::Update();
}


void Worker::Render()
{


	//Execute generic GameObject render
	GameObject::Render();
}

void Worker::CollectCycle()
{
	switch (worker_state)
	{
	case WS_IDLE:
	{
		break;
	}
	case WS_COLLECT_INIT:
	{
		std::vector<GameObject*> resources;
		float closestDistance = 999999;
		GameObject* closestResource = nullptr;
		for (int i = 0; i < gameObjectsRef->size(); i++)
		{
			if (gameObjectsRef->at(i)->OT == OT_RESOURCE)
			{
				resources.push_back(gameObjectsRef->at(i));
			}
		}
		for (int j = 0; j < resources.size(); j++)
		{
			int resourcePosX = resources.at(j)->GetX();
			int resourcePosY = resources.at(j)->GetY();
			float yDist = resourcePosY - GetY();
			float xDist = resourcePosX - GetX();

			float distance = sqrt((yDist*yDist) + (xDist*xDist));
			if (distance < closestDistance)
			{
				closestDistance = distance;
				closestResource = resources.at(j);
			}

		}
		resourceTarget = closestResource;
		worker_state = WS_COLLECT_GOTO;
		break;
	}
	case WS_COLLECT_GOTO:
	{
		MoveToPoint(resourceTarget->GetX(), resourceTarget->GetY());
		break;
	}
	case WS_COLLECT_RETURN:
	{
		MoveToPoint(resourceHome->GetX(), resourceHome->GetY());
		break;
	}
	default:
		break;
	}
	

}

