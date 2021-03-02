#pragma once
#include "SDL.h"

class Player
{
public:
	Player();
	~Player();

private:
	int x, y;
	SDL_Rect rect;

};
