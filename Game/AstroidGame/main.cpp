using namespace std;
#include <iostream>
#include "SDL.h"
#include "Game.h"

int main(int argc, char *argv[])
{
	std::cout << "Hello Universe" << std::endl;

	Game* game = new Game("Asteroid",1920, 1080, 1);

	//const char* title =  "Astroid";
	//SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	int i = 0;

	while (true)
	{
		i++;
		cout << "frame: " << i << endl;
		game->Render();
	}

	return 0;


	//string funString;

}