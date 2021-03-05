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

	int astroidType = (rand() % 100);
	int size = (rand() % 150) + 50;

	if (astroidType < 50)
	{
		double speed = 1000 - size * 4 + rand() % 200 - 100;

		asteroids[asteroidIndex]->Init(player->position + Vector2(0, -1000), Vector2(0, speed), Vector2(), size);
	}
	else
	{
		int speed = (rand() % 100) - 50;
		Vector2 pos;
		pos.x = (speed > 0) ? (0 - size) : screenSize.x;
		pos.y = (rand() % lroundf(screenSize.y) / 2); //-200;
		double gravity = (rand() % 5) + 20;

		cout << "exsist" << endl;

		asteroids[asteroidIndex]->Init(pos, Vector2(speed * 50, 0), Vector2(0,gravity), size);
	}

}
