#pragma once
#include "SDL.h"
#include "Vector2.h"
#include <math.h>
#include <iostream>
#include "Bullet.h"
#include "Player.h"

class HomingRocket
{
public:
	HomingRocket(SDL_Texture* texture);
	~HomingRocket();

	void Update(Player * player, double deltaTime, double time);
	void Render(SDL_Renderer* renderer);

	void CollisionCheck(Player* player);

	void Init(Vector2 pos, double speed);

	bool isActive = false;

private:
	Vector2 position;
	Vector2 velocity;

	SDL_Texture* rocketTexture;

	double rocketSpeed;
	
	double explodeTime;
	double SpawnTime;

	SDL_Rect rect;
};