#ifndef _TEXTURE_H
#define _TEXTURE_H

#include "SDL.h"
#include <iostream>


class Texture
{
public:
	Texture();
	Texture(std::string _path, SDL_Renderer*);
	~Texture();
	bool Load();
	void Render();

	int GetWidth();
	int GetHeight();
	void SetWidth(int w);
	void SetHeight(int h);
	
	int GetX();
	int GetY();
	void SetX(int x);
	void SetY(int y);

	int GetAngle();
	void SetAngle(int _angle);

	

private:
	int width;
	int height;
	int xPos;
	int yPos;
	int angle;
	
	SDL_Texture* texture;
	std::string path;
	SDL_Renderer* renderer;
};

#endif // !_TEXTURE_H
