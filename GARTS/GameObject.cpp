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

	owner = OWN_NONE;
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
