#include "TextureManager.h"
#include "Game.h"

SDL_Texture * TextureManager::LoadTexture(const char *textureSheet)
{
	SDL_Surface *tmpSurface = IMG_Load(textureSheet);
	SDL_Texture *tex = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	return tex;
}
