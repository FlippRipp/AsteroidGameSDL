#include "Player.h"

Player::Player(Vector2 startPos, Vector2 size, int radius)
{
	rect = SDL_Rect();
	rect.x = startPos.x;
	rect.y = startPos.y;
	rect.w = size.x;
	rect.h = size.y;

	position = startPos;
}

Player::~Player()
{
}

void Player::Render(SDL_Renderer * renderer)
{
	rect.x = round(position.x);
	rect.y = round(position.y);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &rect);
}

void Player::UpdatePlayer(Inputs* input, double deltaTime)
{	
	if (input->aDown)
	{
		position.x -= (speed * deltaTime);
	}
	if (input->dDown)
	{
		position.x += (speed * deltaTime);
	}
	if (input->wDown)
	{
		position.y -= (speed * deltaTime);
	}
	if (input->sDown)
	{
		position.y += (speed * deltaTime);
	}
}
