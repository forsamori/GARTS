#ifndef _BARRACKS_H
#define _BARRACKS_H

#include "GameObject.h"
#include "Spearman.h"
#include "Archer.h"
#include "Knight.h"
//#include "MilitaryUnit.h"
#include "UI.h"



class Barracks : public GameObject {

public:

	Barracks(std::string tex_path, SDL_Renderer* _renderer, std::vector<GameObject*>* _gameObjectsRef, std::vector<GameObject>* _gameObjects) : GameObject(tex_path, _renderer, _gameObjectsRef, _gameObjects)
	{
		SetHealth(100.0f);

		barracksUnit = UI(1024, 768, "..//media/infSpawn.bmp", _renderer);
		barracksUnit.SetX(1024 - barracksUnit.GetWidth());
		barracksUnit.SetY(768 - barracksUnit.GetHeight());
		OT = ObjectType::OT_BARRACKS;
		currentlySpawning = false;

		//Update();
	}
	
	~Barracks();

	void SpawnUnit(ObjectType ot, std::vector<GameObject*>* aiUnits);
	void Update();
	void Render();



private:

	GameObject spawnButton;
	UI barracksUnit;
	SDL_Event _event;



};

#endif