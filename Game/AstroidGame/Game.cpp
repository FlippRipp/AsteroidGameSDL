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
		}

		SDL_RenderPresent(renderer);
	}
	else
	{
		cout << "Error on SDL Init Error code: " << error << endl;

	}

	inputs = new Inputs();
	player = new Player(Vector2(resX / 2, resY / 2), Vector2(50, 50), 25, Vector2(resX, resY));
	asteroidController = new AsteroidController(3 , 0.01, player);
}

Game::~Game()
{
}

void Game::Update()
{

	//cout << frameCounter << endl;
	inputs->UpdateInputs();
	player->UpdatePlayer(inputs,deltaTime, GetTimeSec());
	asteroidController->Update(deltaTime, GetTimeSec());

	if (inputs->quitPressed)
	{
		isRunning = false;
	}
}

void Game::Render()
{
	SDL_RenderClear(renderer);
	player->Render(renderer);
	asteroidController->Render(renderer);
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
	delete asteroidController;

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}