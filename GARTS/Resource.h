#ifndef _RESOURCE_H
#define _RESOURCE_H

#include "GameObject.h"

class Resource : public GameObject
{

public:

	Resource(std::string tex_path, SDL_Renderer* _renderer, std::vector<GameObject*>* _gameObjectsRef, std::vector<GameObject>* _gameObjects) : GameObject(tex_path, _renderer, _gameObjectsRef, _gameObjects)
	{
		OT = OT_RESOURCE;
	}
	~Resource();
	int Harvest();

	void Update();
	void Render();

	int GetResourcesRemaining();

protected:

private:

	int harvestAmount = 5;
	int resourceRemaining = 100;


};

#endif
