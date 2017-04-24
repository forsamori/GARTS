#include "GameObject.h"

GameObject::GameObject()
{
	xPos = 0;
	yPos = 0;
	angle = 0;
	width = 0;
	height = 0;
	gotoX = NULL;
	gotoY = NULL;

	//1 pixel accuracy
	gotoAccuracy = 1;
	selected = false;
	velocity.x = 0;
	velocity.y = 0;
	active = true;

	speed = 0;
}

GameObject::GameObject(std::string tex_path, SDL_Renderer* _renderer, std::vector<GameObject*>* _gameObjectsRef, std::vector<GameObject>* _gameObjects)
{
	xPos = 0;
	yPos = 0;
	angle = 0;
	width = 0;
	height = 0;
	gotoX = NULL;
	gotoY = NULL;

	gotoAccuracy = 1;
	renderer = _renderer;
	selected = false;

	gameObjectsRef = _gameObjectsRef;
	gameObjects = _gameObjects;

	velocity.x = 0;
	velocity.y = 0;

	speed = 0;
	sprite = Sprite(tex_path, _renderer);
	width = sprite.GetWidth();
	height = sprite.GetHeight();
	health = 100;

	owner = Owner::OWN_NONE;

	active = true;

	inRaidingParty = false;

	if (tex_path == "")
	{
		bool breakhere;
		breakhere = true;
	}
}

GameObject::~GameObject()
{
}

Sprite* GameObject::GetSprite()
{
	return &sprite;
}

void GameObject::SetSprite(Sprite* _sprite)
{
	sprite = *_sprite;
}

float GameObject::GetX()
{
	return xPos;
}

float GameObject::GetY()
{
	return yPos;
}

void GameObject::SetX(float _x)
{
	xPos = _x;
}

void GameObject::SetY(float _y)
{
	yPos = _y;
}

float GameObject::GetSpeed() 
{
	return speed;
}

void GameObject::SetSpeed(float _speed)
{
	speed = _speed;
}

int GameObject::GetWidth()
{
	return width;
}

int GameObject::GetHeight()
{
	return height;
}

void GameObject::SetWidth(int _width)
{
	width = _width;
}

void GameObject::SetHeight(int _height)
{
	height = _height;
}

int GameObject::GetAngle()
{
	return angle;
}

void GameObject::SetAngle(int _angle)
{
	angle = _angle;
}

//Handles updating GameObject's position and logic.
//Also handles militaryunit logic, since it was moved here
//due to an issue with polymorphism and casting.
void GameObject::Update()
{

	
	//Destroy the object if its health is less than or equal to 0.
	if (GetHealth() <= 0)
	{
		for (int i = 0; i < gameObjectsRef->size(); i++)
		{
			if (gameObjectsRef->at(i) == this)
			{
				gameObjectsRef->erase(gameObjectsRef->begin() + i);
				gameObjects->erase(gameObjects->begin() + i);
				active = false;
			}
		}

	}

	if (isMilUnit == true)
	{

		//Perform actions based on the units current state.
		switch (unit_state)
		{
		case UNIT_STATE::US_IDLE:
		{
			if (prev_unit_state != unit_state)
			{
				Debug_String("US_IDLE");
			}
			break;
		}
		//Move to a target location.
		case UNIT_STATE::US_MOVE:
		{
			//if (prev_unit_state != unit_state)
			//{
				Debug_String("US_MOVE");
			//}
			MoveToPoint(xTarget, yTarget);
			break;
		}
		//Move to a target unit and engage when colliding with it.
		case UNIT_STATE::US_MOVE_ENGAGE:
		{
			//if (prev_unit_state != unit_state)
			//{
				Debug_String("US_MOVE_ENGAGE");
			//}
			if (currentTarget != nullptr)
			{
				MoveToPoint(currentTarget->GetX(), currentTarget->GetY());
				if (AABBCollision(this, currentTarget))
				{
					unit_state = UNIT_STATE::US_ENGAGE;
				}
			}
			else
			{
				unit_state = UNIT_STATE::US_RETREAT;
			}
			break;
		}
		//Attack current target if it still exists and unit is in contact with it,
		//otherwise retreat.
		case UNIT_STATE::US_ENGAGE:
		{
			//if (prev_unit_state != unit_state)
			//{
				Debug_String("US_ENGAGE");
			//}
 			if (currentTarget != nullptr)
			{
				if (AABBCollision(this, currentTarget))
				{
					if (attackCooldown <= 0.0f)
					{
						DoAttack();
						attackCooldown = 1.0f;
					}
					if (currentTarget->GetHealth() <= 0.0f)
					{
						currentTarget = nullptr;
					}
					attackCooldown -= attackSpeed;
				}
				else
				{
					unit_state = UNIT_STATE::US_MOVE_ENGAGE;
				}

	
			}
			else
			{
				unit_state = UNIT_STATE::US_RETREAT;
			}
			break;
		}
		//Retreat back to home base.
		case UNIT_STATE::US_RETREAT:
		{
			//if (prev_unit_state != unit_state)
			//{
				Debug_String("US_RETREAT");
			//}
			if (unitHome != nullptr)
			{
				int deviation = rand_range(0, 50);
				MoveToPoint(unitHome->GetX()+deviation, unitHome->GetY()+deviation);
				if (AABBCollision(this, unitHome))
				{
					inRaidingParty = false;
					unit_state = UNIT_STATE::US_IDLE;
				}
				
			}
			break;
		}
		//Unused.
		case UNIT_STATE::US_DIE:
		{
			if (prev_unit_state != unit_state)
			{
				Debug_String("US_DIE");
			}
			break;
		}
		}
	}

	//Move using velocity
	xPos += velocity.x;
	yPos += velocity.y;

	if (xPos < (gotoX + gotoAccuracy) && xPos > (gotoX - gotoAccuracy) &&
		yPos < (gotoY + gotoAccuracy) && yPos > (gotoY - gotoAccuracy))
	{
		velocity.x = 0;
		velocity.y = 0;
	}

	//Update sprite's vars
	sprite.SetAngle(angle);
	sprite.SetX(xPos);
	sprite.SetY(yPos);
	sprite.Update();

	prev_unit_state = unit_state;

}
void GameObject::Render()
{
	sprite.Render();
	if (selected == true)
	{
		DrawBox();
	}
}

bool GameObject::AABBCollision(GameObject* AA, GameObject* BB)
{

	// AABB 1
	int x1Min = AA->GetX();
	int x1Max = AA->GetX() + AA->GetWidth();
	int y1Max = AA->GetY() + AA->GetHeight();
	int y1Min = AA->GetY();

	// AABB 2
	int x2Min = BB->GetX();
	int x2Max = BB->GetX() + BB->GetWidth();
	int y2Max = BB->GetY() + BB->GetHeight();
	int y2Min = BB->GetY();

	// Collision tests
	if (x1Max < x2Min || x1Min > x2Max) return false;
	if (y1Max < y2Min || y1Min > y2Max) return false;

	return true;

}

void GameObject::SphereCollision(GameObject* AA, GameObject* BB)
{
}

void GameObject::SelectObject() 
{
	selected = true;
}

bool GameObject::IsSelected()
{
	if (selected == true)
		return true;
	else
		return false;
}

void GameObject::DeselectObject()
{
	selected = false;
}


void GameObject::MoveToPoint(int _x, int _y)
{
	gotoX = _x;
	gotoY = _y;

	int diffX = gotoX - xPos;
	int diffY = gotoY - yPos;
	//Change this to float.
	float angleApproach = atan2(diffY, diffX);

	velocity.x = speed * cos(angleApproach);
	velocity.y = speed * sin(angleApproach);
}

void GameObject::SetHealth(float _health)
{
	health = _health;
}

float GameObject::GetHealth()
{
	return health;
}

//Initialize Military Units.
void GameObject::MilInit()
{
	attackSpeed = 0.1f;
	attackCooldown = 1.0f;
	attackVal = 1.0f;
	SetHealth(100.0f);

	SetSpeed(0.1f);

	inRaidingParty = false;

	unit_state = UNIT_STATE::US_MOVE_ENGAGE;
	OT = ObjectType::OT_UNIT_SPEARMAN;

	isMilUnit = true;

}

//Attack the current target.
void GameObject::DoAttack()
{
	float targetHealth = currentTarget->GetHealth();
	targetHealth -= attackVal;
	currentTarget->SetHealth(targetHealth);

	std::string s = "tHealth: ";
	s.append(std::to_string(targetHealth).c_str());
	char* debugOut = (char*)s.c_str();

	Debug_String(debugOut);
}

void GameObject::SetTarget(GameObject * target)
{
	currentTarget = target;
}

bool GameObject::GetActive()
{
	return active;
}

void GameObject::SetActive()
{
	active = true;
}

void GameObject::DrawBox()
{
	SDL_Point points[5] = {
		{xPos, yPos},
		{xPos + width, yPos},
		{xPos + width, yPos + height},
		{xPos, yPos + height},
		{xPos, yPos}
	};

	//SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLines(renderer, points, 5);
	//SDL_RenderPresent(renderer);
}
