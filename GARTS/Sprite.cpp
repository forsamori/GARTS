#include "Sprite.h"

Sprite::Sprite()
{
	xPos = 0;
	yPos = 0;
	angle = 0;
	tex = Texture();
}

Sprite::Sprite(std::string _tex_path, SDL_Renderer* _renderer)
{
	xPos = 0;
	yPos = 0;
	angle = 0;
	tex = Texture(_tex_path, _renderer);
}

Sprite::~Sprite()
{
}

int Sprite::GetX()
{
	return xPos;
}

int Sprite::GetY()
{
	return yPos;
}

void Sprite::SetX(int _x)
{
	xPos = _x;
	Update(); //HACK - Remove this when we get a better way of setting new values to vars.
}

void Sprite::SetY(int _y)
{
	yPos = _y;
	Update();
}

int Sprite::GetHeight()
{
	return tex.GetHeight();
}

int Sprite::GetWidth()
{
	return tex.GetWidth();
}

int Sprite::GetAngle()
{
	return angle;
}

void Sprite::SetAngle(int _angle)
{
	angle = _angle;
}

void Sprite::Update()
{
	tex.SetAngle(angle);
	tex.SetX(xPos);
	tex.SetY(yPos);
}

void Sprite::Render()
{
	tex.Render();
}

Texture* Sprite::GetTexture()
{
	return &tex;
}
