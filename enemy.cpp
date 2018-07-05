#include "enemy.h"
#include "TextureManager.h"
#include "Game.h"


enemy::enemy()
{
}

enemy::enemy(const char * textureSheet, int x, int y, int hp)
{
	isAlive = true;
	this->ObjTexture = TextureManager::LoadTexture(textureSheet);
	xpos = x;
	ypos = y;

	srcR = { 0, 0, 102, 50 };
	dstR = { x, y, 192, 96 };

	blood = new Blood(hp, xpos, ypos);
}

enemy::~enemy()
{
}

void enemy::Update()
{
	if (!isAlive)
	{
		if (count < 10)
		{
			count++;
		}
		else
			return;
		ObjTexture = TextureManager::LoadTexture("Assets/explosion.png");
		srcR.x = (SDL_GetTicks() / 50 % 7) * 82;
		srcR.y = 0;
		srcR.w = 86;
		srcR.h = 98;
		dstR.w = dstR.h = 200;
		return;
	}
	blood->Update(xpos, ypos);
	srcR.x = (SDL_GetTicks() / 100) % 3 * 102;
	xpos -= 2;

	dstR.x = xpos;
}

void enemy::Render()
{
	if (count < 10)
	{
		blood->Render();
		SDL_RenderCopy(Game::renderer, ObjTexture, &srcR, &dstR);
	}
}

void enemy::EventsHanlde()
{
}
