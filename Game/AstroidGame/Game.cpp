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
}

Game::~Game()
{
}

void Game::Update()
{
}

void Game::Render()
{
	SDL_RenderClear(renderer);

	//render stuff here
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	SDL_RenderPresent(renderer);
}
