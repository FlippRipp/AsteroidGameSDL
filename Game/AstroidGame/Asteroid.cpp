#include "Asteroid.h"

Asteroid::Asteroid(SDL_Texture* texture)
{
	AsteroidTexture = texture;
}

Asteroid::~Asteroid()
{
}

void Asteroid::Update(double deltaTime)
{
	lifeTimer += deltaTime;
	if (lifeTimer > lifeTime)
	{
		isActive = false;
	}

	velocity += gravityAcceleration;
	position += velocity * deltaTime; 
}

void Asteroid::Render(SDL_Renderer * renderer)
{	
	rect.x = round(position.x);
	rect.y = round(position.y);
	SDL_RenderCopy(renderer, AsteroidTexture, NULL, &rect);

}

void Asteroid::CollisionCheck(Player * player)
{
	if (Vector2::Distance(Vector2(position.x + asteroidSize / 2,position.y + asteroidSize / 2)
		,Vector2(player->position.x + player->radius, player->position.y + player->radius))
		< asteroidSize / 2 + player->radius)
	{
		isActive = false;
	}

	for (int i = 0; i < player->BulletPoolSize; i++)
	{
		Bullet* bullet;

		if (player->bulletList[i] != nullptr)
		{
			if (player->bulletList[i]->isActive) bullet = player->bulletList[i];
			else continue;
		}
		else continue;

		

		if (Vector2::Distance(Vector2(position.x + asteroidSize / 2, position.y + asteroidSize / 2)
			, Vector2(bullet->position.x + bullet->size / 2, bullet->position.y + bullet->size / 2))
			< asteroidSize / 2 + bullet->size / 2)
		{
				isActive = false;
				bullet->isActive = false;
		}

	}
}

void Asteroid::Init(Vector2 pos, Vector2 vel, Vector2 gravityAccel, int size)
{
	asteroidSize = size;
	rect.w = rect.h = size;
	position = pos;
	velocity = vel;
	gravityAcceleration = gravityAccel;
	lifeTimer = 0;
	isActive = true;
}
