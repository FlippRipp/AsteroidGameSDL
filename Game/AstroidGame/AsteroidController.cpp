#include "AsteroidController.h"

AsteroidController::AsteroidController(double delayStart, double delayDecrease, Player* p, Vector2 screen)
{
	asteroidSpawnDelay = delayStart;
	asteroidSpawnDecrease = delayDecrease;
	player = p;
	screenSize = screen;
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
			if (asteroids[i]->isActive) 
			{
				asteroids[i]->Update(deltaTime);
				asteroids[i]->CollisionCheck(player);
			}
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
	int asteroidIndex = -1;

	for (int i = 0; i < asteroidPoolSize; i++)
	{
		if (asteroids[i] == nullptr)
		{
			asteroids[i] = new Asteroid();
			asteroidIndex = i;

			break;
		}
		else if (!asteroids[i]->isActive)
		{
			asteroidIndex = i;
			break;
		}
	}

	if (asteroidIndex == -1) return;

	double astroidType = (rand() % 100) /100;
	int size = (rand() % 150) + 50;

	if (astroidType < 0.5)
	{
		double speed = 1000 - size * 5 + rand() % 200 - 100;

		asteroids[asteroidIndex]->Init(player->position + Vector2(0, -1000), Vector2(0, speed), Vector2(), size);
	}
	else
	{
		asteroids[asteroidIndex]->Init(player->position + Vector2(0, -1000), Vector2(0, 100), Vector2(), 100);
	}

}
