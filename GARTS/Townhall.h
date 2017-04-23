#pragma once
#ifndef _TOWNHALL_H
#define _TOWNHALL_H

#include "GameObject.h"
#include "Worker.h"
#include "helper_functions.h"


class Townhall : public GameObject {

public:

	//Barracks(std::string tex_path, SDL_Renderer* _renderer);
	Townhall(std::string tex_path, SDL_Renderer* _renderer, std::vector<GameObject*>* _gameObjectsRef, std::vector<GameObject>* _gameObjects) : GameObject(tex_path, _renderer, _gameObjectsRef, _gameObjects)
	{
		OT = ObjectType::OT_TOWNHALL;
	}

	~Townhall();

	void SpawnUnit();
	void Update();
	void Render();

	int resources;

private:

};

#endif