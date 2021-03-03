#pragma once
#pragma once
#include "SDL.h"
#include "Vector2.h"
#include <math.h>
#include <iostream>

class Bullet
{
public:
	Bullet(Vector2 dir, Vector2 startPos);
	~Bullet();

	void Render(SDL_Renderer* renderer);
	void Update(double deltaTime);
	bool isActive = false;
	Vector2 direction;
	Vector2 position;
	double lifeTimer = 0;
	int size = 12;

private:
	const double bulletSpeed = 560;
	const double lifeTime = 10;
	SDL_Rect rect;
};

