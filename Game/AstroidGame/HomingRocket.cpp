#include "HomingRocket.h"

//57.295779512896171867977148875518
HomingRocket::HomingRocket(SDL_Texture* texture)
{
	rocketTexture = texture;
	rect.h = rocketSize.y;
	rect.w = rocketSize.x;
}

HomingRocket::~HomingRocket()
{
}

void HomingRocket::Update(Player * player, double deltaTime, double time)
{
	if (Vector2::Distance(position, player->position) > 10)
	{
		forwardDirection = Vector2::Lerp(forwardDirection, Vector2::GetNormalizedDirection(position, player->position), turnSpeed);

		forwardDirection.Normalize();
		//cout << angle << "  " << dir.x << "  " << dir.y << endl;

		angle = Vector2::AngleFromDirection(forwardDirection);

		debugPosition = position + forwardDirection * 60;


		position += forwardDirection * rocketSpeed * deltaTime;
	}
	else
	{
		//Go Boom
	}
}

void HomingRocket::Render(SDL_Renderer * renderer)
{
	rect.x = round(position.x);
	rect.y = round(position.y);
	SDL_RenderCopyEx(renderer, rocketTexture, NULL, &rect, angle * GameMath::radToDeg() + 90, NULL, SDL_FLIP_NONE);

	SDL_Rect debugRect;
	debugRect.x = debugPosition.x;
	debugRect.y = debugPosition.y;
	debugRect.w = 5;
	debugRect.h = 5;
	SDL_RenderFillRect(renderer, &debugRect);
}

void HomingRocket::CollisionCheck(Player * player)
{
	if (Vector2::Distance(Vector2(position.x + rocketSize.x / 2, position.y + rocketSize.y / 2)
		, Vector2(player->position.x + player->radius, player->position.y + player->radius))
		< 10 + player->radius)
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



		if (Vector2::Distance(Vector2(position.x + rocketSize.x / 2, position.y + rocketSize.y / 2)
			, Vector2(bullet->position.x + bullet->size / 2, bullet->position.y + bullet->size / 2))
			< 50 / 2 + bullet->size / 2)
		{
			isActive = false;
			bullet->isActive = false;
		}

	}

}

void HomingRocket::Init(Vector2 pos, double speed, Player* player)
{
	position = pos;
	rocketSpeed = speed;
	isActive = true;

	forwardDirection = Vector2::GetNormalizedDirection(position, player->position);
	angle = atan2(forwardDirection.y, forwardDirection.x);

}
