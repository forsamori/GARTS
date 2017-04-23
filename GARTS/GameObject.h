#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include "SDL.h"
#include "Sprite.h"
#include <iostream>
#include "helper_functions.h"
#include <vector>
//#include "UnitManager.h"

//extern std::vector<GameObject> gameObjects;

enum ObjectType {
	OT_UNIT,
	OT_UNIT_WORKER,
	OT_UNIT_SPEARMAN,
	OT_UNIT_ARCHER,
	OT_UNIT_KNIGHT,
	OT_RESOURCE,
	OT_TOWNHALL,
	OT_BARRACKS
};

enum Owner {
	OWN_NONE,
	OWN_P1,
	OWN_AI1,
	OWN_AI2,
	OWN_AI3,
	OWN_AI4,
	OWN_AI5,
	OWN_AI6,
	OWN_AI7
};

enum UNIT_STATE
{
	US_IDLE,
	US_MOVE,
	US_MOVE_ENGAGE,
	US_ENGAGE,
	US_RETREAT,
	US_DIE
	//Make states here.
};


class GameObject
{

public:
	GameObject();
	//Include pointer to gameobjects list so if a GameObject creates any other GameObjects, we can
	//add them to the main update/render vector.
	GameObject(std::string tex_path, SDL_Renderer*, std::vector<GameObject*>* _gameObjectsRef, std::vector<GameObject>* _gameObjects);
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

	virtual void Update();
	virtual void Render();
	void DrawBox();

	bool AABBCollision(GameObject* AA, GameObject* BB);
	void SphereCollision(GameObject* AA, GameObject* BB);

	void SelectObject();
	bool IsSelected();
	void DeselectObject();

	void MoveToPoint(int _x, int _y);

	void SetHealth(float _health);
	float GetHealth();

	void MilInit();
	void DoAttack();
	void SetTarget(GameObject* target);

	bool GetActive();
	void SetActive();

	bool beginSpawn;

	ObjectType OT;
	Owner owner;

	//Mil unit stuff

	UNIT_STATE unit_state;
	UNIT_STATE prev_unit_state;
	//int health;
	GameObject* currentTarget = nullptr;
	GameObject* unitHome;

	bool inRaidingParty = false;

protected:
	std::vector<GameObject*>* gameObjectsRef;
	std::vector<GameObject>* gameObjects;
	SDL_Renderer* renderer;
	
	

private:

	float xPos;
	float yPos;
	int angle;
	int width;
	int height;
	Sprite sprite;
	int gotoX;
	int gotoY;
	int gotoAccuracy;

	bool selected;
	


	float health;

	vec2f velocity;

	float speed;

	//MilUnit stuff
	int attackVal;
	ObjectType counter;

	float moveSpeed;
	float attackSpeed;
	float attackCooldown;

	float xTarget;
	float yTarget;

	bool isMilUnit = false;
	bool active;
};

#endif