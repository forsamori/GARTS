#ifndef _BARRACKS_H
#define _BARRACKS_H

#include "GameObject.h"

class Barracks : public GameObject {

public:

	//Barracks(std::string tex_path, SDL_Renderer* _renderer);
	Barracks(std::string tex_path, SDL_Renderer* _renderer) : GameObject(tex_path, _renderer)
	{
		SetHealth(100.0f);
	}
	
	~Barracks();

	void SpawnUnit();
	virtual void Update();
	void Render();

private:



};

#endif