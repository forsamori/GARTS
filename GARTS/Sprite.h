#ifndef _SPRITE_H
#define _SPRITE_H

#include "texture.h"

class Sprite : public Texture
{
public:
	Sprite();
	Sprite(std::string tex_path, SDL_Renderer*);//Path version
	~Sprite();

	int GetX();
	int GetY();
	void SetX(int _x);
	void SetY(int _y);

	int GetAngle();
	void SetAngle(int _angle);

	void Update();
	void Render();



private:

	int xPos;
	int yPos;
	int angle;
	Texture tex;

};


#endif