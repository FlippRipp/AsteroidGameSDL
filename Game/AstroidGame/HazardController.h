#pragma once
#include "Asteroid.h"
#include "HomingRocket.h"
#include "Player.h"

class HazardController
{
public:
	HazardController(double delayStart, double delayDecrease, Player* p, Vector2 screen, SDL_Renderer* rend);
	~HazardController();

	void Update(double deltaTime, double time);
	void Render(SDL_Renderer* renderer);
	

private:

	void spawnHazards();
	void spawnAsteroid();
	void spawnRocket();

	static const int asteroidPoolSize = 200;
	Asteroid* asteroids[asteroidPoolSize];

	static const int homingRocketPoolSize = 200;
	HomingRocket* homingRockets[homingRocketPoolSize];

	Player* player;

	Vector2 screenSize;

	SDL_Texture* asteroidTexture;
	SDL_Texture* homingRocketTexture;

	double asteroidSpawnDelay;
	double asteroidSpawnDecrease;
	double lastSpawnTime;
};