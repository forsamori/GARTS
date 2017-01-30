#include "texture.h"

Texture::Texture()
{
	width = 0;
	height = 0;
	xPos = 0;
	yPos = 0;
	texture = NULL;
	Load();
}

Texture::Texture(std::string _path, SDL_Renderer* _renderer)
{
	width = 0;
	height = 0;
	xPos = 0;
	yPos = 0;
	texture = NULL;
	path = _path;
	renderer = _renderer;
	angle = 0;
	Load();
}

Texture::~Texture()
{
}

bool Texture::Load()
{
	SDL_Texture* tex = NULL;
	
	SDL_Surface* surf = SDL_LoadBMP(path.c_str());
	if (surf == NULL)
	{
		printf("Unable to load image %s! SDL_ERROR: %s\n", path.c_str(), SDL_GetError());
	}
	else
	{
		//Colour key image
		SDL_SetColorKey(surf, SDL_TRUE, SDL_MapRGB(surf->format, 0xFF, 0xFF, 0xFF));
		tex = SDL_CreateTextureFromSurface(renderer, surf);
		if (tex == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			//Set texture height/width based on imported attributes
			width = surf->w;
			height = surf->h;
		}

	}
	
	texture = tex;
	return texture != NULL;
}

void Texture::Render()
{
	SDL_Rect renderQuad = { xPos, yPos, width, height };
	SDL_RenderCopyEx(renderer, texture, NULL, &renderQuad, angle, NULL, SDL_FLIP_NONE);
}

int Texture::GetWidth()
{
	return width;
}

int Texture::GetHeight()
{
	return height;
}

void Texture::SetWidth(int w)
{
	width = w;
}

void Texture::SetHeight(int h)
{
	height = h;
}

int Texture::GetX()
{
	return xPos;
}

int Texture::GetY()
{
	return yPos;
}

void Texture::SetX(int x)
{
	xPos = x;
}

void Texture::SetY(int y)
{
	yPos = y;
}

int Texture::GetAngle()
{
	return angle;
}

void Texture::SetAngle(int _angle)
{
	angle = _angle;
}
