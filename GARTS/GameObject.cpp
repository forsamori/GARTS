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

	owner = OWN_NONE;

	active = true;

	inRaidingParty = false;
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

void GameObject::Update()
{

	
	if (GetHealth() <= 0)
	{
		//FUTURE SAM: Find a good way of destroying objects
		//safely. You may need to pop them off the gameObjects lists
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

		switch (unit_state)
		{
		case US_IDLE:
		{
			if (prev_unit_state != unit_state)
			{
				Debug_String("US_IDLE");
			}
			break;
		}
		case US_MOVE:
		{
			if (prev_unit_state != unit_state)
			{
				Debug_String("US_MOVE");
			}
			MoveToPoint(xTarget, yTarget);
			break;
		}
		case US_MOVE_ENGAGE:
		{
			if (prev_unit_state != unit_state)
			{
				Debug_String("US_MOVE_ENGAGE");
			}
			if (currentTarget != nullptr)
			{
				MoveToPoint(currentTarget->GetX(), currentTarget->GetY());
				if (AABBCollision(this, currentTarget))
				{
					unit_state = US_ENGAGE;
				}
			}
			else
			{
				unit_state = US_RETREAT;
			}
			break;
		}
		case US_ENGAGE:
		{
			if (prev_unit_state != unit_state)
			{
				Debug_String("US_ENGAGE");
			}
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
					unit_state = US_MOVE_ENGAGE;
				}

	
			}
			break;
		}

		case US_RETREAT:
		{
			if (prev_unit_state != unit_state)
			{
				Debug_String("US_RETREAT");
			}
			if (unitHome != nullptr)
			{
				MoveToPoint(unitHome->GetX(), unitHome->GetY());
				if (AABBCollision(this, unitHome))
				{
					unit_state = US_IDLE;
				}
				
			}
			break;
		}
		case US_DIE:
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
//Justin was here, 14/02/17  15:57
void GameObject::Render()
{
	sprite.Render();
	if (selected == true)
	{
		DrawBox(/*Pass pointer to renderer here as well*/);
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

void GameObject::MilInit()
{
	attackSpeed = 0.1f;
	attackCooldown = 1.0f;
	attackVal = 1.0f;
	SetHealth(100.0f);

	SetSpeed(0.1f);

	inRaidingParty = false;

	unit_state = US_MOVE_ENGAGE;
	OT = OT_UNIT_SPEARMAN;

	isMilUnit = true;

}

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
