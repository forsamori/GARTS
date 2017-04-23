#ifndef _KNIGHT_H
#define _KNIGHT_H

#include "MilitaryUnit.h"

class Knight : public MilitaryUnit
{
public:
	Knight(std::string tex_path, SDL_Renderer* _renderer, std::vector<GameObject*>* _gameObjectsRef, std::vector<GameObject>* _gameObjects) : MilitaryUnit(tex_path, _renderer, _gameObjectsRef, _gameObjects)
	{
		SetHealth(100.0f);

		SetSpeed(0.1f);

		unit_state = US_MOVE_ENGAGE;
		OT = OT_UNIT_KNIGHT;

	}

	void Update();
	void Render();

protected:

private:



};

#endif
