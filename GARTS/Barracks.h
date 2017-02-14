#ifndef _BARRACKS_H
#define _BARRACKS_H

#include "GameObject.h"

class Barracks : public GameObject {

public:

	//Barracks(std::string tex_path, SDL_Renderer* _renderer);
	Barracks(std::string tex_path, SDL_Renderer* _renderer, std::vector<GameObject*>* _gameObjects) : GameObject(tex_path, _renderer, _gameObjects)
	{
		spawnButton = GameObject("..//media/infSpawn.bmp", _renderer, _gameObjects);
		spawnButton.SetX(GetX());
		spawnButton.SetY(GetY());
		spawnButton.SetAngle(3);
		_gameObjects->push_back(&spawnButton);
		SetHealth(100.0f);

		//Update();
	}
	
	~Barracks();

	void SpawnUnit();
	void Update();
	void Render();

private:

	GameObject spawnButton;



};

#endif