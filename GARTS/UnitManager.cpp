#include "UnitManager.h"


std::vector<GameObject*>* UnitManager::GetGameObjectsRefList()
{
	return &std::vector<GameObject*>();
}

void UnitManager::SpawnUnit(GameObject spawnObject)
{
	gameObjects.push_back(spawnObject);
	gameObjectsRef.push_back(&spawnObject);
}
