#include "Inputs.h"


Inputs::Inputs()
{
}

Inputs::~Inputs()
{
}

void Inputs::UpdateInputs()
{
	ResetKeyState();

	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_KEYDOWN:
			ChangeKeyState(event);
			break;
		default:
			break;
		}
	}

}

void Inputs::ChangeKeyState(SDL_Event event)
{
	switch (event.key.keysym.sym)
	{
	case SDLK_w:
		wDown = true;
		break;
	case SDLK_s:
		sDown = true;
		break;
	case SDLK_a:
		aDown = true;
		break;
	case SDLK_d:
		dDown = true;
		break;
	default:
		break;
	}
}

void Inputs::ResetKeyState()
{
	wDown = false;
	sDown = false;
	dDown = false;
	aDown = false;
}




