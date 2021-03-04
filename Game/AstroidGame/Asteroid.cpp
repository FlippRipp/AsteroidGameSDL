#include "Asteroid.h"

Asteroid::Asteroid()
{
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
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderFillRect(renderer, &rect);
}

void Asteroid::Init(Vector2 pos, Vector2 vel, Vector2 gravityAccel, int size)
{
	rect.w = rect.h = size;
	position = pos;
	velocity = vel;
	gravityAcceleration = gravityAccel;
	lifeTimer = 0;
	isActive = true;
}
