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
	Player(Vector2 startPos, Vector2 size, Vector2 screenS, int radius = 0);
	~Player();

	void Render(SDL_Renderer* renderer);
	void UpdatePlayer(Inputs* input, double deltaTime, double time);
	void Shoot();
	
	Vector2 position;

	static const int BulletPoolSize = 1000;
	Bullet* bulletList[BulletPoolSize] = { };
	int radius = 10;
private:
	SDL_Rect rect;	
	const double speed = 100;
	Vector2 screenSize;

	void UpdateBoost(double time, Inputs* input);
	void GravityUpdate();
	void Move(double deltaTime);

	Vector2 velocity;

	const double gravityAcceleration = 20;
	double gravity = 0;

	double groundClearance = 2;
	bool isGrounded = false;
	const double boostAcceleration = 5;
	double boostMaxTime = 1.7;
	double boostStartTime = 0;
	bool isBoosting = false;

	double lastFireTime = 0;
	double timeBetweenBullets = 0.001f;

};
