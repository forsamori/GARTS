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
		obj->SelectObject();
		selection.push_back(obj);
	}

}

std::vector<GameObject*> Selector::BoxSelect(vec2f startCoord, vec2f endCoord, std::vector<GameObject>* _objectsVec)
{
	ClearSelection();

	std::vector<GameObject*> selectionVec;
	//Debug_String("Alright m8?");
	int vecSize = _objectsVec->size();
	for (int i = 0; i < vecSize; i++)
	{
		GameObject* obj = &_objectsVec->at(i);
		if (obj->GetX() > startCoord.x && (obj->GetX() + obj->GetWidth()) < endCoord.x &&
			obj->GetY() > startCoord.y && (obj->GetY() + obj->GetHeight()) < endCoord.y)
		{
			selectionVec.push_back(obj);
		}
	}

	if (selectionVec.empty())
	{
		Debug_String("No Objects inside box, no selection");
		ClearSelection();
	}
	else
	{
		for (int j = 0; j < selectionVec.size(); j++)
		{
			selectionVec.at(j)->SelectObject();
			selection.push_back(selectionVec.at(j));
		}
	}
	return selectionVec;

	//Listen for left-click released.
	//If released, iterate through all game objects...
	//...put found objects into array
	//...add them to selected list.
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
	for (int i = 0; i < selection.size(); i++)
	{
		selection.at(i)->DeselectObject();
	}
	selection.clear();
}
