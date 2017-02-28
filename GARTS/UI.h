#ifndef _UI_H
#define _UI_H

#include "GameObject.h"

enum UNIT_TYPE
{
	UNIT_WORKER,
	UNIT_ARCHER,
	UNIT_SPEAR,
	UNIT_HORSE,
	UNIT_NONE
};

class UI : public GameObject {

public:

	UI();
	UI(int _screenX, int _screenY, std::string tex_path, SDL_Renderer* _renderer, UI_TYPE _type, UNIT_TYPE _unit_type);
	~UI();

	void Render();
	void Update();
	Sprite* GetSprite();

	

private:

	int screenX;
	int screenY;
	int worldX;
	int worldY;

	Sprite sprite;
	UI_TYPE _type;
	UNIT_TYPE _unit_type;


};


#endif