#include "Background.h"
#include "TextureManager.h"
#include "Game.h"


Background::Background()
{
}

Background::Background(const char * textureSheet)
{
	ObjTexture = TextureManager::LoadTexture(textureSheet);
	srcR = dstR = { 0, 0, 1280, 640 };
}


Background::~Background()
{
}

void Background::Update()
{
	dstR.x -= 2;
}

void Background::Render()
{
	if (dstR.x == -1280)
		dstR.x = 0;
	SDL_RenderCopy(Game::renderer, ObjTexture, NULL, &dstR);
	srcR.x = dstR.x + 1280;
	SDL_RenderCopy(Game::renderer, ObjTexture, NULL, &srcR);
}

void Background::LoadBackground(const char * textureSheet)
{
	ObjTexture = TextureManager::LoadTexture(textureSheet);
}
