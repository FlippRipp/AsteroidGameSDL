#include "Player.h"

Player::Player(Vector2 startPos, Vector2 size, int radius, Vector2 screenS)
{
	rect = SDL_Rect();
	rect.x = startPos.x;
	rect.y = startPos.y;
	rect.w = size.x;
	rect.h = size.y;

	position = startPos;
	screenSize = screenS;
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

	for (int i = 0; i < bulletList.size(); i++)
	{
		bulletList[i]->Render(renderer);
	}
}

void Player::UpdatePlayer(Inputs* input, double deltaTime, double time)
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
		if (!isBoosting && isGrounded)
		{
			boostStartTime = time;
			isBoosting = true;
		}
		else if(isBoosting)
		{
			if (time - boostStartTime > boostMaxTime)
			{
				isBoosting = false;
				boostSpeed = 0;
			}

			boostSpeed += boostAcceleration * deltaTime;
			position.y -= (boostSpeed + gravity) * deltaTime;
		}
	}
	else
	{
		isBoosting = false;
		boostSpeed = 0;
	}


	if (input->sDown)
	{
		position.y += speed * deltaTime;
	}

	//cout << "bottom of screen = " << (screenSize.y - rect.h) << "Player y = " << position.y << " isGrounded = " << isGrounded << endl;

	if ((screenSize.y - rect.h) - position.y < groundClearance)
	{
		gravity = 0;
		isGrounded = true;
	}
	else
	{
		if(!isBoosting) gravity += gravityAcceleration * deltaTime;
		position.y += gravity * deltaTime;
		isGrounded = false;
	}

	if (input->kDown)
	{
		Shoot();
	}

	position = Vector2::Clamp(position, Vector2(0, 0), Vector2(screenSize.x - rect.w, screenSize.y - rect.h));

	for (int i = 0; i < bulletList.size(); i++)
	{
		if (bulletList[i]->Destroy) 
		{
			bulletList.erase(bulletList.begin()+i);
			cout << bulletList[i]->Destroy << endl;
		}		

		bulletList[i]->Update(deltaTime);
	}
}

void Player::Shoot()
{
	Bullet* bullet = new Bullet(Vector2(0,-1), position);
	bulletList.push_back(bullet);
}
