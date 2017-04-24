/*
ALL MILITARYUNIT CODE MOVED TO GAMEOBJECT
This was because of an issue with polymorphism and casting.
Any derived classes using MilitaryUnit also suffer
the same fate.*/

#ifndef _MILITARY_UNIT_H
#define _MILITARY_UNIT_H

#include "GameObject.h"

class MilitaryUnit : public GameObject
{
public:

	MilitaryUnit(std::string tex_path, SDL_Renderer* _renderer, std::vector<GameObject*>* _gameObjectsRef, std::vector<GameObject>* _gameObjects) : GameObject(tex_path, _renderer, _gameObjectsRef, _gameObjects)
	{
		attackSpeed = 0.1f;
		attackCooldown = 1.0f;
		attackVal = 1.0f;
		SetHealth(100.0f);
		
		SetSpeed(0.1f);

		inRaidingParty = false;

		unit_state = UNIT_STATE::US_MOVE_ENGAGE;
		OT = ObjectType::OT_UNIT_SPEARMAN;

	}

	~MilitaryUnit();
	void Init();
	void Update();
	void Render();

	void DoAttack();

	void SetTarget(GameObject* target);

	UNIT_STATE unit_state;
	//int health;
	GameObject* currentTarget;
	GameObject* unitHome;

	bool inRaidingParty = false;
protected:

private:


	int attackVal;
	ObjectType counter;

	float moveSpeed;
	float attackSpeed;
	float attackCooldown;

	float xTarget;
	float yTarget;



};

#endif