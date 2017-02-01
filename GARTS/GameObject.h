#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include "SDL.h"
#include "Sprite.h"
#include <iostream>
#include "helper_functions.h"

class GameObject
{

public:
	GameObject();
	GameObject(std::string tex_path, SDL_Renderer*);
	~GameObject();

	Sprite* GetSprite();
	void SetSprite(Sprite* _sprite);

	float GetX();
	float GetY();
	void SetX(float _x);
	void SetY(float _y);

	float GetSpeed();
	void SetSpeed(float _speed);

	int GetWidth();
	int GetHeight();
	void SetWidth(int _width);
	void SetHeight(int _height);

	int GetAngle();
	void SetAngle(int _angle);

	void Update();
	void Render();

	void AABBCollision(GameObject* AA, GameObject* BB);
	void SphereCollision(GameObject* AA, GameObject* BB);

	void MoveToPoint(int _x, int _y);



private:

	float xPos;
	float yPos;
	int angle;
	int width;
	int height;
	Sprite sprite;
	int gotoX;
	int gotoY;

	vec2f velocity;

	float speed;


};

#endif