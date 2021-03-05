#pragma once
#include "Asteroid.h"
#include "Player.h"

class AsteroidController
{
public:
	AsteroidController(double delayStart, double delayDecrease, Player* p, Vector2 screen);
	~AsteroidController();

	void Update(double deltaTime, double time);
	void Render(SDL_Renderer* renderer);
	

private:

	void spawnAsteroid();

	static const int asteroidPoolSize = 1000;
	Asteroid* asteroids[asteroidPoolSize];
	Player* player;

	Vector2 screenSize;

	double asteroidSpawnDelay;
	double asteroidSpawnDecrease;
	double lastSpawnTime;
};