#include "Blood.h"
#include "TextureManager.h"
#include "Game.h"

Blood::Blood()
{
}

Blood::Blood(int hp, int x, int y)
{
	HP = hp;
	tmp = dstR = { x, y, 8, 2 };
	tex = TextureManager::LoadTexture("Assets/hp.png");
}


Blood::~Blood()
{
}

void Blood::Update(int x, int y)
{
	dstR = { x, y, 8, 2};
}

void Blood::Render()
{
	for (int i = 0; i < HP; i++)
	{
		tmp.x = dstR.x + i*8;
		tmp.y = dstR.y;
		SDL_RenderCopy(Game::renderer, tex, NULL, &tmp);
	}
}

void Blood::operator-=(int x)
{
	HP -= x;
}
