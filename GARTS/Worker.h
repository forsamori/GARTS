#ifndef _WORKER_H
#define _WORKER_H

#include "GameObject.h"
#include "Resource.h"

class Worker : public GameObject
{
public:
	Worker(std::string tex_path, SDL_Renderer* _renderer, std::vector<GameObject*>* _gameObjectsRef, std::vector<GameObject>* _gameObjects) : GameObject(tex_path, _renderer, _gameObjectsRef, _gameObjects)
	{
		hasResources = false;
		OT = OT_UNIT_WORKER;
	}
	~Worker();
	void Update();
	void Render();
	bool hasResources;
	int resourceCarrying;

protected:

private:




};

#endif
