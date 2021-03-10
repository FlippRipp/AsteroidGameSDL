#include "Game.h"


Game::Game(const char* title, int resX, int resY, bool fullscreen)
{
	int error = SDL_Init(SDL_INIT_EVERYTHING);
	if (error == 0)
	{
		int flag = 0;
		if (fullscreen)
		{
			flag = SDL_WINDOW_FULLSCREEN;
		}
		cout << "Init Success" << endl;
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, resX, resY, flag);

		if (window)
		{
			cout << "Window successfully created" << endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer)
		{
			cout << "Renderer successfully created" << endl;
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
			int imageFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imageFlags) & imageFlags))
			{
				cout << "IMG_Init failed to created SDL_image Error: %s/n" << IMG_GetError() << endl;				
			}
			else
			{
				cout << "IMG_Init successfully created" << endl;
			}
		}

		SDL_RenderPresent(renderer);
	}
	else
	{
		cout << "Error on SDL Init Error code: " << error << endl;

	}

	inputs = new Inputs();
	collsionSystem = new Collision2D(Vector2(resX, resY));
	player = new Player(Vector2(resX / 2, resY / 2), Vector2(50, 50), Vector2(resX, resY), 25);
	hazardController = new HazardController(1, 0.001, player, Vector2(resX, resY), renderer, collsionSystem);

	collsionSystem->AddCollider(new GameObject(Vector2(-200, 0), 0));
	collsionSystem->AddCollider(player);
}

Game::~Game()
{
}

void Game::Update()
{

	cout << 1 / deltaTime << endl;
	inputs->UpdateInputs();
	player->UpdatePlayer(inputs,deltaTime, GetTimeSec());
	hazardController->Update(deltaTime, GetTimeSec());
	collsionSystem->Update();
	if (inputs->quitPressed)
	{
		isRunning = false;
	}
}

void Game::Render()
{
	SDL_RenderClear(renderer);
	player->Render(renderer);
	hazardController->Render(renderer);
	//render stuff here	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderPresent(renderer);
}

void Game::GameLoop() {

	while (isRunning)
	{
		cycleCount++;
		if (cycleCount % 3 == 0)
		{
			double newTime = SDL_GetTicks();
			cycleTime = (newTime - independedGameTime) / 3;
			independedGameTime = newTime;				
		}

		accumilator += cycleTime;		

		double framesec = 1 / DesiredFps;
		double frameMiliSec = framesec * msPerSecond;
		//cout << "accumilator = " << accumilator << endl;
		//cout << "frameMiliSec = " << frameMiliSec << endl;
		if (accumilator > frameMiliSec)
		{			
			frameCounter++;
			accumilator = 0;
			double newTime = SDL_GetTicks();
			deltaTime = (newTime - gameTime) / 1000;
			gameTime = newTime;
			//cout << "deltatime = " << deltaTime << " gametime = " << gameTime << endl;
			//cout << frameCounter / (gameTime / 1000) << endl;
			Update();
			Render();
		}
	}

	delete player;
	delete inputs;
	delete hazardController;

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}