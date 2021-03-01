using namespace std;
#include <iostream>
#include "SDL.h"

int main(int argc, char *argv[])
{
	std::cout << "Hello Universe" << std::endl;

	const char* title =  "Astroid";
	SDL_Window* window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512, 512, 0);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	int i = 0;

	while (true)
	{
		i++;
		cout << "frame: " << i << endl;
	}

	return 0;
}