#include "Bullet.h"

Bullet::Bullet(Vector2 dir,Vector2 startPos)
{
	position = startPos;
	rect.h = rect.w = size;
	direction = dir;
}

Bullet::~Bullet()
{
}

void Bullet::Render(SDL_Renderer * renderer)
{
	rect.x = round(position.x);
	rect.y = round(position.y);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &rect);
}

void Bullet::Update(double deltaTime)
{
	position += direction * (bulletSpeed * deltaTime);
	lifeTimer += deltaTime;
	if (lifeTimer > lifeTime)
	{
		Destroy = true;
	}
}
