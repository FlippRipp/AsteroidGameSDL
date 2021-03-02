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

	bool nothingPressed = true;

	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_KEYDOWN:
			nothingPressed = false;
			ChangeKeyState(event);
			break;
		default:
			break;
		}
	}

	if (nothingPressed)
	{
	}

}

void Inputs::ChangeKeyState(SDL_Event event)
{
	switch (event.key.keysym.sym)
	{
	case SDLK_w:
		wDown = true;
		cout << "w Pressed down" << endl;
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




