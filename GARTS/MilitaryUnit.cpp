#include "MilitaryUnit.h"



MilitaryUnit::~MilitaryUnit()
{
}

void MilitaryUnit::Init()
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
	case UNIT_STATE::US_IDLE:
		break;
	case UNIT_STATE::US_MOVE:
	{
		MoveToPoint(xTarget, yTarget);
		break;
	}
	case UNIT_STATE::US_MOVE_ENGAGE:
	{
		if (currentTarget != nullptr)
		{
			MoveToPoint(currentTarget->GetX(), currentTarget->GetY());
			if (AABBCollision(this, currentTarget))
			{
				unit_state = UNIT_STATE::US_ENGAGE;
			}
		}
	}
	case UNIT_STATE::US_ENGAGE:
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
		
	case UNIT_STATE::US_RETREAT:
	{
		MoveToPoint(unitHome->GetX(), unitHome->GetY());
		if (AABBCollision(this, unitHome))
		{
			unit_state = UNIT_STATE::US_IDLE;
		}
		break;
	}
	case UNIT_STATE::US_DIE:
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

void MilitaryUnit::SetTarget(GameObject * target)
{
	currentTarget = target;
}

