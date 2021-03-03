#pragma once
#pragma once
#include "SDL.h"
#include "Vector2.h"
#include "Inputs.h"
#include <math.h>
#include <iostream>

class Bullet
{
public:
	Bullet(Vector2 dir, Vector2 startPos);
	~Bullet();

	void Render(SDL_Renderer* renderer);
	void Update(double deltaTime);
	bool Destroy = false;

private:
	const double bulletSpeed = 30;
	const double lifeTime = 5;
	double lifeTimer = 0;
	SDL_Rect rect;
	int size = 4;
	Vector2 direction;
	Vector2 position;
};

