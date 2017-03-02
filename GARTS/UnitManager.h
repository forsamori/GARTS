#ifndef _UNIT_MANAGER_H
#define _UNIT_MANAGER_H

#include "GameObject.h"
//#include <vector>


class UnitManager
{
public:

	std::vector<GameObject*>* GetGameObjectsRefList();
	void SpawnUnit(GameObject spawnObject);

private:

	std::vector<GameObject*> gameObjectsRef;
	std::vector<GameObject> gameObjects;

};

#endif // !_UNIT_MANAGER_H