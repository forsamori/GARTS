#include "Townhall.h"

Townhall::~Townhall()
{
}

void Townhall::Update()
{
	for (int i = 0; i < gameObjectsRef->size(); i++)
	{
		if (AABBCollision(this, gameObjectsRef->at(i)))
		{
			if (gameObjectsRef->at(i)->OT == OT_UNIT_WORKER)
			{
				Worker* worker = (Worker*)gameObjectsRef->at(i);
				if (worker->hasResources == true)
				{
					resources += worker->resourceCarrying;
					worker->hasResources = false;

					std::string s = "Resources: ";
					s.append(std::to_string(resources).c_str());
					char* debugOut = (char*)s.c_str();

					Debug_String(debugOut);
				}
			}
		}
	}
	//Execute generic GameObject update
	GameObject::Update();
}

void Townhall::Render()
{
	//Execute generic GameObject render
	GameObject::Render();
}
