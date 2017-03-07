#ifndef _AI_H
#define _AI_H

#include "GameObject.h"
#include "Worker.h"
#include <vector>

enum AI_STATE {
	AI_INIT,
	AI_DESTROY,
	AI_START_COLLECT_PHASE, //Collect resources, little to no fighting
	AI_START_ARMY_PHASE, //Start building army units, stop building resource units (unless new resources found/units destroyed)
	AI_MID_PHASE, //Active scouting, harrassing enemy workers
	AI_END_PHASE, //Full base assaults. If all units die, regress to AI_START_ARMY_PHASE
};

class AI {

public:

	AI(std::vector<GameObject*>* _gameObjectsRef, std::vector<GameObject>* _gameObjects, Owner _owner)
	{
		gameObjectsRef = _gameObjectsRef;
		gameObjects = _gameObjects;
		currAIState = AI_INIT;
		owner = _owner;
	}
	~AI();

	void Update();


protected:
private:

	std::vector<GameObject*>* gameObjectsRef;
	std::vector<GameObject>* gameObjects;

	std::vector<GameObject*> myBuildings;
	std::vector<GameObject*> myUnits;
	GameObject* myTownhall;
	AI_STATE currAIState;
	Owner owner;



};

#endif