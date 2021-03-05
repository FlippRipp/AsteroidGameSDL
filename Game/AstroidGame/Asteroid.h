#pragma once
#include "SDL.h"
#include "Vector2.h"
#include <math.h>
#include <iostream>
#include "Bullet.h"
#include "Player.h"

class Asteroid
{
public:
	Asteroid();
	~Asteroid();

	void Update(double deltaTime);
	void Render(SDL_Renderer* renderer);

	void CollisionCheck(Player* player);

	void Init(Vector2 pos, Vector2 vel, Vector2 gravityAccel, int size);

	bool isActive = false;

private:
	double lifeTimer = 0;
	double lifeTime = 10;

	int asteroidSize;
	Vector2 position;
	Vector2 velocity;
	Vector2 gravityAcceleration;
	SDL_Rect rect;
};