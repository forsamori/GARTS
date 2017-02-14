#include "UI.h"

UI::UI()
{
}

UI::UI(int _screenX, int _screenY, std::string tex_path, SDL_Renderer* _renderer)
{
	sprite = Sprite(tex_path, _renderer);
	screenX = _screenX;
	screenY = _screenY;
	sprite.SetX(screenX);
	sprite.SetY(screenY);
}

UI::~UI()
{
}

void UI::Render()
{
	sprite.Render();
}
