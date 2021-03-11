#pragma once
#include "SDL.h"
#include "Vector2.h"
#include "Inputs.h"
#include <math.h>
#include <iostream>
#include "Bullet.h"
#include "RenderingUtilities.h"
#include "GameObject.h"
#include "Collision2D.h"

class Player : public GameObject
{
public:
	Player(Vector2 startPos, Vector2 size, Vector2 screenS, double rad, 
		std::vector<GameObject::CollisionLayers> collisionLayers, 
		CollisionLayers layer, Collision2D* cS);

	~Player();

	void Render(SDL_Renderer* renderer);
	void UpdatePlayer(Inputs* input, double deltaTime, double time);
	void Shoot();
	
	static const int BulletPoolSize = 1000;
	Bullet* bulletList[BulletPoolSize] = { };

	Collision2D* collisionSystem;
private:

	SDL_Rect rect;	
	const double speed = 200;
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
	double boostMaxFuel = 20;
	double boostFuel = 0;
	double boostConsumption = 2;
	double boostRecharge = 1.5;
	bool isBoosting = false;

	double lastFireTime = 0;
	double timeBetweenBullets = 0.2f;

	SDL_Texture* texture;
};
