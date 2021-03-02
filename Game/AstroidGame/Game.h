#pragma once
using namespace std;
#include "SDL.h"
#include <iostream>
#include "Inputs.h"

class Game
{
public:
	Game(const char* title, int resX, int resY, bool fullscreen);
	~Game();

	void GameLoop();
	void Update();
	void Render();

	Inputs* inputs;

	const double DesiredFps = 30;
	const double msPerSecond = 1000;	
	double gameTime;
	double deltaTime;
	int frameCounter;
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	int cycleCount;
	double accumilator = 0;
	double cycleTime;
	double independedGameTime;	
};