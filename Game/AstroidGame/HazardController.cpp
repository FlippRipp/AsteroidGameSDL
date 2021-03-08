#include "HazardController.h"

HazardController::HazardController(double delayStart, double delayDecrease, Player* p, Vector2 screen, SDL_Renderer* rend)
{
	asteroidSpawnDelay = delayStart;
	asteroidSpawnDecrease = delayDecrease;
	player = p;
	screenSize = screen;
	asteroidTexture = RenderingUtilities::LoadTexture("Ressources/Asteroid.png", rend);
	homingRocketTexture = RenderingUtilities::LoadTexture("Ressources/HomingRocket.png", rend);
}

HazardController::~HazardController()
{
	//Destroy All Existing Asteroids
	for (int i = 0; i < asteroidPoolSize; i++)
	{
		if (asteroids[i] != NULL)
		{
			delete asteroids[i];
		}
	}

	//Destroy All Existing Homing Rockets
	for (int i = 0; i < homingRocketPoolSize; i++)
	{
		if (homingRockets[i] != NULL)
		{
			delete homingRockets[i];
		}
	}
}

void HazardController::Update(double deltaTime, double time)
{
	//Update Asteroids
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

	//Update Homing Rockets
	for (int i = 0; i < homingRocketPoolSize; i++)
	{
		if (homingRockets[i] != NULL)
		{
			if (homingRockets[i]->isActive)
			{
				homingRockets[i]->Update(player, deltaTime, time);
				homingRockets[i]->CollisionCheck(player);
			}
		}
	}

	//Spawn Hazards
	if (time - lastSpawnTime > asteroidSpawnDelay)
	{
		lastSpawnTime = time;
		spawnHazards();
	}
}

void HazardController::Render(SDL_Renderer * renderer)
{
	//Render Asteroids
	for (int i = 0; i < asteroidPoolSize; i++)
	{
		if (asteroids[i] != NULL)
		{
			if (asteroids[i]->isActive) asteroids[i]->Render(renderer);
		}
	}

	//Render Homing Rockets
	for (int i = 0; i < homingRocketPoolSize; i++)
	{
		if (homingRockets[i] != NULL)
		{
			if (homingRockets[i]->isActive) homingRockets[i]->Render(renderer);
		}
	}
}

//Spawn Hazards
void HazardController::spawnHazards()
{
	int hazardType = (rand() % 100);

	if (hazardType < 20) {
		cout << "Will spawn rocket" << endl;
		spawnRocket();
	}
	else if(hazardType < 100)
	{
		spawnAsteroid();
	}
}

//Spawn Asteroids
void HazardController::spawnAsteroid()
{
	int asteroidIndex = -1;

	for (int i = 0; i < asteroidPoolSize; i++)
	{
		if (asteroids[i] == nullptr)
		{
			asteroids[i] = new Asteroid(asteroidTexture);
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
		pos.y = (rand() % lroundf(screenSize.y) / 2);
		double gravity = (rand() % 5) + 20;

		asteroids[asteroidIndex]->Init(pos, Vector2(speed * 50, 0), Vector2(0,gravity), size);
	}

}

//Spawn Homing Rockets
void HazardController::spawnRocket()
{
	int rocketIndex = -1;

	cout << "Trying to spawn rocket" << endl;

	for (int i = 0; i < homingRocketPoolSize; i++)
	{
		if (homingRockets[i] == nullptr)
		{
			homingRockets[i] = new HomingRocket(homingRocketTexture);
			rocketIndex = i;

			break;
		}
		else if (!homingRockets[i]->isActive)
		{
			rocketIndex = i;
			break;
		}
	}

	if (rocketIndex == -1) return;

	cout << "Rocket Spawned" << endl;

	int entrySide = rand() % 3;

	Vector2 startPos;

	//Enters from the left
	if (entrySide == 0)
	{
		startPos.x = 0;
		startPos.y = (rand() % lroundf(screenSize.y) / 2);

	}
	//Enters from the top
	else if (entrySide == 1)
	{
		startPos.x = (rand() % lroundf(screenSize.x));
		startPos.y = 0;

	}
	//Enters from the right
	else
	{
		startPos.x = screenSize.x;
		startPos.y = (rand() % lroundf(screenSize.y) / 2);

	}

	double speed = rand() % 300 + 150; 

	homingRockets[rocketIndex]->Init(startPos, speed, player);

}
