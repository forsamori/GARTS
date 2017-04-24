#include "Worker.h"

Worker::~Worker()
{
}

void Worker::Update()
{

	//Move between rock and home collecting/depositing resources.
	if (worker_state == WS_COLLECT_GOTO || worker_state == WS_COLLECT_RETURN)
	{
		for (int i = 0; i < gameObjectsRef->size(); i++)
		{
			if (AABBCollision(this, gameObjectsRef->at(i)))
			{
				if (worker_state == WS_COLLECT_GOTO)
				{
					if (gameObjectsRef->at(i)->OT == ObjectType::OT_RESOURCE && hasResources == false)
					{
						Resource* resource = (Resource*)gameObjectsRef->at(i);
						if (resource->GetResourcesRemaining() != 0 && resource == resourceTarget)
						{
							resourceCarrying = resource->Harvest();
							hasResources = true;
							//SetSprite(defaultSprite);
							worker_state = WS_COLLECT_RETURN;
						}
						else if (resource == resourceTarget)
						{
							worker_state = WS_COLLECT_INIT;
						}
						
					}
				}
				else if (worker_state == WS_COLLECT_RETURN)
				{
					//SetSprite(&carrySprite);
					if (gameObjectsRef->at(i)->OT == ObjectType::OT_TOWNHALL)
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

//Find nearest resource and progress to next state to move to it.
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
		std::vector<Resource*> resources;
		float closestDistance = 999999;
		Resource* closestResource = nullptr;
		resourceTarget = 0;
		for (int i = 0; i < gameObjectsRef->size(); i++)
		{
			if (gameObjectsRef->at(i)->OT == ObjectType::OT_RESOURCE)
			{
				resources.push_back((Resource*)gameObjectsRef->at(i));
			}
		}
		for (int j = 0; j < resources.size(); j++)
		{
			int resourcePosX = resources.at(j)->GetX();
			int resourcePosY = resources.at(j)->GetY();
			float yDist = resourcePosY - GetY();
			float xDist = resourcePosX - GetX();

			float distance = sqrt((yDist*yDist) + (xDist*xDist));
			if (distance < closestDistance && resources.at(j)->GetResourcesRemaining() > 0)
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
		if (resourceTarget != nullptr)
		{
			MoveToPoint(resourceTarget->GetX(), resourceTarget->GetY());
		}
		else
		{
			//Could not find resources, go to idle.
			noMoreResources = true;
			worker_state = WS_IDLE;
		}
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

