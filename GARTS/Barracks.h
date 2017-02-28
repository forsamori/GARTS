#ifndef _BARRACKS_H
#define _BARRACKS_H

#include "GameObject.h"
#include "UI.h"

class Barracks : public GameObject {

public:

	//Barracks(std::string tex_path, SDL_Renderer* _renderer);
	Barracks(std::string tex_path, SDL_Renderer* _renderer, std::vector<GameObject>* _gameObjects) : GameObject(tex_path, _renderer, _gameObjects)
	{
		//spawnButton = GameObject("..//media/infSpawn.bmp", _renderer, _gameObjects);
		//spawnButton.SetX(GetX());
		//spawnButton.SetY(GetY());
		//spawnButton.SetAngle(3);
		//_gameObjects->push_back(&spawnButton);
		SetHealth(100.0f);

		barracksUnit = UI(1024, 768, "..//media/infSpawn.bmp", _renderer, UI_SPAWN, UNIT_SPEAR);
		//barracksUnit.SetX(1024 - barracksUnit.GetSprite()->GetWidth());
		//barracksUnit.SetY(768 - barracksUnit.GetSprite()->GetHeight());
		float _width = barracksUnit.GetSprite()->GetTexture()->GetWidth();
		float _height = barracksUnit.GetSprite()->GetTexture()->GetHeight();
		barracksUnit.SetX(1024 - _width);
		barracksUnit.SetY(768 - _height);
		//_gameObjects->push_back(&barracksUnit);

		//Update();
	}
	
	~Barracks();

	void SpawnUnit();
	void Update();
	void Render();

private:

	GameObject spawnButton;
	UI barracksUnit;
	SDL_Renderer* _renderer;
	std::vector<GameObject>* _gameObjects;


};

#endif