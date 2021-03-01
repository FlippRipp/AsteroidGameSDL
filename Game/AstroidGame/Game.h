#pragma once
using namespace std;
#include "SDL.h"
#include <iostream>

class Game
{
public:
	Game(const char* title, int resX, int resY, bool fullscreen);
	~Game();


	void Update();
	void Render();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

};