#include "HomingRocket.h"

HomingRocket::HomingRocket(SDL_Texture* texture)
{
	rocketTexture = texture;
}

HomingRocket::~HomingRocket()
{
}

void HomingRocket::Update(Player * player, double deltaTime, double time)
{
	
}

void HomingRocket::Render(SDL_Renderer * renderer)
{
	rect.x = round(position.x);
	rect.y = round(position.y);
	SDL_RenderCopy(renderer, rocketTexture, NULL, &rect);

}

void HomingRocket::CollisionCheck(Player * player)
{

}

void HomingRocket::Init(Vector2 pos, double speed)
{
	position = pos;
	rocketSpeed = speed;
	isActive = true;
}
