#pragma once
#include "SDL.h"
#include "Vector2.h"
#include <vector>
#include "Inputs.h"
#include <math.h>
#include <iostream>
#include "Bullet.h"

class Player
{
public:
	Player(Vector2 startPos, Vector2 size, int radius, Vector2 screenS);
	~Player();

	void Render(SDL_Renderer* renderer);
	void UpdatePlayer(Inputs* input, double deltaTime, double time);
	void Shoot();
	
private:
	Vector2 position;
	SDL_Rect rect;	
	const double speed = 100;
	int radius = 10;
	Vector2 screenSize;

	const double gravityAcceleration = 100;
	double gravity = 0;

	double groundClearance = 2;
	bool isGrounded = false;
	const double boostAcceleration = 75;
	double boostSpeed = 0;
	double boostMaxTime = 3;
	double boostStartTime = 0;
	bool isBoosting = false;
		
	vector<Bullet*> bulletList;
};
