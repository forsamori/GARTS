#ifndef _WORKER_H
#define _WORKER_H

#include "GameObject.h"
#include "Resource.h"

enum WORKER_STATE
{
	WS_IDLE,
	WS_COLLECT_INIT,
	WS_COLLECT_GOTO,
	WS_COLLECT_RETURN,
	WS_FIND_NEW_RESOURCE,
	WS_DIE
};

class Worker : public GameObject
{
public:
	Worker(std::string tex_path, SDL_Renderer* _renderer, std::vector<GameObject*>* _gameObjectsRef, std::vector<GameObject>* _gameObjects) : GameObject(tex_path, _renderer, _gameObjectsRef, _gameObjects)
	{
		hasResources = false;
		OT = OT_UNIT_WORKER;
		worker_state = WS_IDLE;
		SetSpeed(0.1f);
		carrySprite = Sprite("..//media/workerCarry", _renderer);
		defaultSprite = GetSprite();
		noMoreResources = false;
		

	}
	~Worker();
	void Update();
	void Render();

	void CollectCycle();

	bool hasResources;
	int resourceCarrying;
	bool noMoreResources;
	WORKER_STATE worker_state;

	Resource* resourceTarget;
	GameObject* resourceHome;

protected:

private:

	Sprite carrySprite;
	Sprite* defaultSprite;


	




};

#endif
