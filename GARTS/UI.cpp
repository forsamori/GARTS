#include "UI.h"

UI::UI()
{
}

UI::UI(int _screenX, int _screenY, std::string tex_path, SDL_Renderer* _renderer, UI_TYPE ui_type, UNIT_TYPE unit_type)
{
	sprite = Sprite(tex_path, _renderer);
	screenX = _screenX - 55;
	screenY = _screenY - 55;
	sprite.SetX(screenX);
	sprite.SetY(screenY);

	_type = ui_type;
	_unit_type = unit_type;

}

UI::~UI()
{
}

void UI::Render()
{
	sprite.Render();
}

void UI::Update()
{
	if (IsSelected() == true && _type == UI_SPAWN)
	{
		//Spawn Unit
		
	}
}

Sprite* UI::GetSprite()
{
	return &sprite;
	//return nullptr;
}
