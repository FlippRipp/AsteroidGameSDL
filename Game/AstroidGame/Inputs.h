#pragma once
#include "SDL.h"
#include <iostream>
using namespace std;

class Inputs
{
public:
	Inputs();
	~Inputs();

	void UpdateInputs();
	void ChangeKeyState(SDL_Event event);
	void ResetKeyState();

	bool wDown = false;
	bool sDown = false;
	bool dDown = false;
	bool aDown = false;	

private:

};