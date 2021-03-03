#include "Bullet.h"

Bullet::Bullet(Vector2 dir,Vector2 startPos)
{
	position = Vector2(startPos.x + size / 2, startPos.y);
	rect.h = rect.w = size;
	direction = dir;
}

Bullet::~Bullet()
{
}

void Bullet::Render(SDL_Renderer * renderer)
{
	std::cout << position.x << std::endl;
	rect.x = round(position.x);
	rect.y = round(position.y);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &rect);
}

void Bullet::Update(double deltaTime)
{
	position += direction * (bulletSpeed * deltaTime);
	lifeTimer += deltaTime;
	if (lifeTimer > lifeTime)
	{
		isActive = false;
	}
}
