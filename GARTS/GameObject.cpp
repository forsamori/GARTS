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
	
	velocity.x = 0;
	velocity.y = 0;

	speed = 0;
}

GameObject::GameObject(std::string tex_path, SDL_Renderer* _renderer)
{
	xPos = 0;
	yPos = 0;
	angle = 0;
	width = 0;
	height = 0;
	gotoX = NULL;
	gotoY = NULL;

	velocity.x = 0;
	velocity.y = 0;

	speed = 0;
	sprite = Sprite(tex_path, _renderer);
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

	//Update sprite's vars
	sprite.SetAngle(angle);
	sprite.SetX(xPos);
	sprite.SetY(yPos);
	sprite.Update();


}

void GameObject::Render()
{
	sprite.Render();
}

void GameObject::AABBCollision(GameObject* AA, GameObject* BB)
{
}

void GameObject::SphereCollision(GameObject* AA, GameObject* BB)
{
}

void GameObject::MoveToPoint(int _x, int _y)
{
	gotoX = _x;
	gotoY = _y;

	int diffX = gotoX - xPos;
	int diffY = gotoY - yPos;
	//Change this to float.
	int angleApproach = atan2(diffY, diffX);

	velocity.x = speed * cos(angleApproach);
	velocity.y = speed * sin(angleApproach);
}
