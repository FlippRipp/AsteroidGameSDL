#pragma once
#include "Asteroid.h"
#include "Player.h"

class AsteroidController
{
public:
	AsteroidController(double delayStart, double delayDecrease, Player* p);
	~AsteroidController();

	void Update(double deltaTime, double time);
	void Render(SDL_Renderer* renderer);
	

private:

	void spawnAsteroid();

	static const int asteroidPoolSize = 50;
	Asteroid* asteroids[asteroidPoolSize];
	Player* player;

	double asteroidSpawnDelay;
	double asteroidSpawnDecrease;
	double lastSpawnTime;
};