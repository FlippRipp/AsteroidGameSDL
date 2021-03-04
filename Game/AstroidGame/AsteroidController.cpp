#include "AsteroidController.h"

AsteroidController::AsteroidController(double delayStart, double delayDecrease, Player* p)
{
	asteroidSpawnDelay = delayStart;
	asteroidSpawnDecrease = delayDecrease;
	player = p;
}

AsteroidController::~AsteroidController()
{
	for (int i = 0; i < asteroidPoolSize; i++)
	{
		if (asteroids[i] != NULL)
		{
			delete asteroids[i];
		}
	}
}

void AsteroidController::Update(double deltaTime, double time)
{
	for (int i = 0; i < asteroidPoolSize; i++)
	{
		if (asteroids[i] != NULL)
		{
			if (asteroids[i]->isActive) asteroids[i]->Update(deltaTime);
		}
	}

	if (time - lastSpawnTime > asteroidSpawnDelay)
	{
		lastSpawnTime = time;
		spawnAsteroid();
	}
}

void AsteroidController::Render(SDL_Renderer * renderer)
{
	for (int i = 0; i < asteroidPoolSize; i++)
	{
		if (asteroids[i] != NULL)
		{
			if (asteroids[i]->isActive) asteroids[i]->Render(renderer);
		}
	}
}

void AsteroidController::spawnAsteroid()
{
	for (int i = 0; i < asteroidPoolSize; i++)
	{
		if (asteroids[i] == nullptr)
		{
			asteroids[i] = new Asteroid();
			asteroids[i]->Init(player->position + Vector2(0,-1000), Vector2(),Vector2(0,5), 100 );
			break;
		}
		else if (!asteroids[i]->isActive)
		{
			asteroids[i]->Init(player->position + Vector2(0, -1000), Vector2(), Vector2(0, 5), 100);
			break;
		}
	}
}
