#include "MilitaryUnit.h"

MilitaryUnit::~MilitaryUnit()
{
}

void MilitaryUnit::Update()
{

	if (GetHealth() <= 0)
	{
		//FUTURE SAM: Find a good way of destroying objects
		//safely. You may need to pop them off the gameObjects lists
		for (int i = 0; i < gameObjectsRef->size(); i++)
		{
			if (gameObjectsRef->at(i) == this)
			{
				gameObjectsRef->erase(gameObjectsRef->begin()+i);
				gameObjects->erase(gameObjects->begin() + i);
			}
		}
		
	}

	switch (unit_state)
	{
	case US_IDLE:
		break;
	case US_MOVE:
	{
		MoveToPoint(xTarget, yTarget);
		break;
	}
	case US_MOVE_ENGAGE:
	{
		if (currentTarget != nullptr)
		{
			MoveToPoint(currentTarget->GetX(), currentTarget->GetY());
			if (AABBCollision(this, currentTarget))
			{
				unit_state = US_ENGAGE;
			}
		}
	}
	case US_ENGAGE:
	{
		if (AABBCollision(this, currentTarget))
		{
			if (attackCooldown <= 0.0f)
			{
				DoAttack();
				attackCooldown = 1.0f;
			}
		}
	
		attackCooldown -= attackSpeed;
		break;
	}
		
	case US_RETREAT:
	{
		MoveToPoint(unitHome->GetX(), unitHome->GetY());
		if (AABBCollision(this, unitHome))
		{
			unit_state = US_IDLE;
		}
		break;
	}
	case US_DIE:
		break;
	}

	GameObject::Update();
}

void MilitaryUnit::Render()
{
	GameObject::Render();
}

void MilitaryUnit::DoAttack()
{
	float targetHealth = currentTarget->GetHealth();
	targetHealth -= attackVal;
	currentTarget->SetHealth(targetHealth);

	std::string s = "tHealth: ";
	s.append(std::to_string(targetHealth).c_str());
	char* debugOut = (char*)s.c_str();

	Debug_String(debugOut);

}

