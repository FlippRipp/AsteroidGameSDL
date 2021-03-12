#include "RessourceManager.h"

void RessourceManager::RessourceInit(SDL_Renderer* renderer)
{
	PlayerTexture = RenderingUtilities::LoadTexture(playerTexturePath, renderer);
	AsteroidTexture = RenderingUtilities::LoadTexture(asteroidTexturePath, renderer);
	RocketTexture = RenderingUtilities::LoadTexture(rocketTexturePath, renderer);
	RollingStoneTexture = RenderingUtilities::LoadTexture(rollingStoneTexturePath, renderer);
}

SDL_Texture * RessourceManager::GetText(std::string text, int fontSize, SDL_Color color, SDL_Renderer* renderer)
{
	font = TTF_OpenFont(fontAPath.c_str(), fontSize);
	SDL_Surface* surface = TTF_RenderText_Solid(font, "SDL_TTF successfully created", color);

	SDL_Texture* fontTexture = SDL_CreateTextureFromSurface(renderer, surface);

	return fontTexture;
}
