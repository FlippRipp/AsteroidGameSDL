#include "Player.h"

Player::Player(Vector2 startPos, Vector2 size, Vector2 screenS, int radius)
{
	rect = SDL_Rect();
	rect.x = startPos.x;
	rect.y = startPos.y;
	rect.w = size.x;
	rect.h = size.y;

	if(radius = 0) radius = std::fmin(size.x, size.y);

	position = startPos;
	screenSize = screenS;
}

Player::~Player()
{
	for (int i = 0; i < BulletPoolSize; i++)
	{
		if (bulletList[i] != NULL)
		{
			delete bulletList[i];
		}
	}
}

void Player::Render(SDL_Renderer * renderer)
{
	for (int i = 0; i < BulletPoolSize; i++)
	{
		if (bulletList[i] != NULL)
		{
			if (bulletList[i]->isActive) bulletList[i]->Render(renderer);
		}
	}

	rect.x = round(position.x);
	rect.y = round(position.y);

	if(texture == nullptr)
		texture = RenderingUtilities::LoadTexture("Rocket1.png", renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	SDL_RenderCopy(renderer, texture , NULL, &rect);
	//SDL_RenderFillRect(renderer, &rect);

}

void Player::UpdatePlayer(Inputs* input, double deltaTime, double time)
{	
	bool horizontalMovement = false;
	if (input->aDown)
	{
		horizontalMovement = true;
		velocity.x = -speed;
	}
	if (input->dDown)
	{
		horizontalMovement = true;
		velocity.x = speed;
	}

	if (!horizontalMovement)
	{
		velocity.x = 0;
	}

	UpdateBoost(time, input);

	GravityUpdate();

	Move(deltaTime);




	if (input->kDown && time - lastFireTime > timeBetweenBullets)
	{
		lastFireTime = time;
		Shoot();
	}

	for (int i = 0; i < BulletPoolSize; i++)
	{
		if (bulletList[i] != nullptr)
		{
			if(bulletList[i]->isActive) bulletList[i]->Update(deltaTime);
		}
	}
}

void Player::Shoot()
{
	
	for (int i = 0; i < BulletPoolSize; i++)
	{
		if (bulletList[i] == nullptr)
		{
			bulletList[i] = new Bullet(Vector2(0, -1), Vector2(position.x + rect.w / 2, position.y));
			break;
		}
		else if (!bulletList[i]->isActive)
		{
			bulletList[i]->isActive = true;
			bulletList[i]->position = Vector2(position.x + rect.w / 2 - bulletList[i]->size / 2, position.y);
			bulletList[i]->direction = Vector2(0, -1);
			bulletList[i]->lifeTimer = 0;
			break;
		}
	}
}

void Player::UpdateBoost(double time, Inputs* input)
{
	if (input->wDown)
	{
		if (!isBoosting && isGrounded)
		{
			boostStartTime = time;
			isBoosting = true;
		}

		if (isBoosting)
		{
			if (time - boostStartTime > boostMaxTime)
			{
				isBoosting = false;
			}

			velocity.y -= boostAcceleration;
		}
	}
	else
	{
		isBoosting = false;
	}

}

void Player::GravityUpdate()
{
	if ((screenSize.y - rect.h) - position.y < groundClearance)
	{
		if (!isGrounded)
		{
			isGrounded = true;
			velocity.y = 0;
		}
	}
	else
	{
		if (!isBoosting) velocity.y += gravityAcceleration;
		isGrounded = false;
	}
}

void Player::Move(double deltaTime)
{
	position += velocity * deltaTime;

	position = Vector2::Clamp(position, Vector2(0, 0), Vector2(screenSize.x - rect.w, screenSize.y - rect.h));

}
