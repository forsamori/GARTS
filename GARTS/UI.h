#ifndef _UI_H
#define _UI_H

#include "Sprite.h"

class UI : public Sprite {

public:

	UI();
	UI(int _screenX, int _screenY, std::string tex_path, SDL_Renderer* _renderer);
	~UI();

	void Render();
	void Update();


	

private:

	int screenX;
	int screenY;
	int worldX;
	int worldY;

	Sprite sprite;

};


#endif