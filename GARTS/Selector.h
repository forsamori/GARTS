#ifndef _SELECTOR_H
#define _SELECTOR_H

#include <iostream>
#include <vector>
#include "GameObject.h"

/*Used for selecting units. A single instance of Selector
will hold references to selected units, allowing
easy, iterative interaction. Used mostly for mouse interaction*/
class Selector
{
public:
	Selector();
	~Selector();

	std::vector<GameObject*>* GetSelection();
	void Select(int _x, int _y, std::vector<GameObject>* _objectsVec);
	GameObject* MouseCollision(int _x, int _y, std::vector<GameObject>* _objectsVec);
	void ClearSelection(); //Possibly unnecessary. Single-line function.

private:
	std::vector<GameObject*> selection;

};

#endif
