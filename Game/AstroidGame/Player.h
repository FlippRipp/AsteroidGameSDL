#pragma once
#include "SDL.h"
#include "Vector2.h"
#include "Inputs.h"
#include <math.h>
#include <iostream>

class Player
{
public:
	Player(Vector2 startPos, Vector2 size, int radius);
	~Player();

	void Render(SDL_Renderer* renderer);
	void UpdatePlayer(Inputs* input, double deltaTime);
	
private:
	Vector2 position;
	SDL_Rect rect;	
	const double speed = 100;
	int radius = 10;
};
