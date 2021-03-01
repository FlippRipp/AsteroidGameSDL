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
}

Game::~Game()
{
}

void Game::Update()
{
	inputs->UpdateInputs();

}

void Game::Render()
{
	SDL_RenderClear(renderer);
	if (inputs->wDown)
	{
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	}
	else
	{
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	}
	//render stuff here	

	SDL_RenderPresent(renderer);

}

void Game::GameLoop() {

	while (true)
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
			deltaTime = newTime - gameTime;
			gameTime = newTime;
			//cout << "deltatime = " << deltaTime << " gametime = " << gameTime << endl;
			//cout << frameCounter / (gameTime / 1000) << endl;
			Update();
			Render();
		}
	}
}