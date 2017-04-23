#ifndef _SPEARMAN_H
#define _SPEARMAN_H

//#include "MilitaryUnit.h"
#include "GameObject.h"
class Spearman : public GameObject
{
public:
	Spearman(std::string tex_path, SDL_Renderer* _renderer, std::vector<GameObject*>* _gameObjectsRef, std::vector<GameObject>* _gameObjects) : GameObject(tex_path, _renderer, _gameObjectsRef, _gameObjects)
	{
		MilInit();
		//SetHealth(100.0f);

		//SetSpeed(0.1f);

		//unit_state = US_IDLE;
		//OT = OT_UNIT_SPEARMAN;


	}

	void Update();
	void Render();

protected:

private:



};

#endif