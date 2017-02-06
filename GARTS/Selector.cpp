#include "Selector.h"

Selector::Selector()
{
}

Selector::~Selector()
{
}

std::vector<GameObject*>* Selector::GetSelection()
{
	return &selection;
}

void Selector::Select(int _x, int _y, std::vector<GameObject>* _objectsVec)
{
	//Drop currently selected units in favour of single unit.
	ClearSelection();

	//Check all objects to see if it's been clicked on
	GameObject* obj = MouseCollision(_x, _y, _objectsVec);
	if (obj == nullptr)
	{
		Debug_String("No collision, no selection");
		ClearSelection();		
	}
	else
	{
		selection.push_back(obj);
	}

}

GameObject* Selector::MouseCollision(int _x, int _y, std::vector<GameObject>* _objectsVec)
{
	//LOOP gameobjects
	int vecSize = _objectsVec->size();
	for (int i = 0; i < vecSize; i++)
	{
		GameObject* obj = &_objectsVec->at(i);
		if (_x > obj->GetX() && _x < (obj->GetX() + obj->GetWidth()) &&
			_y > obj->GetY() && _y < (obj->GetY() + obj->GetHeight()))
		{
			return obj;
		}
	}

	return nullptr;
}

void Selector::ClearSelection()
{
	selection.clear();
}
