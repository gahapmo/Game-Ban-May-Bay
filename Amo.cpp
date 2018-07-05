#include "Amo.h"
#include "TextureManager.h"
#include "Game.h"


Amo::Amo()
{
}

Amo::Amo(const char * texture, int x, int y, int speed, int isBig)
{
	ObjTexture = TextureManager::LoadTexture(texture);
	xpos = x;
	ypos = y + 50;

	srcR = { 0, 0, 49, 16 };
	dstR = { x, y, 49, 16 };

	if (isBig == 1)
	{
		dstR.w *= 2;
		dstR.h *= 2;
	}
	else if (isBig == 2)
	{
		dstR.w *= 4;
		dstR.h *= 4;
	}

	x0 = x;
	y0 = y;
	shoot = false;
	this->speed = speed;

	damge = 1;

	if (isBig == 1)
	{
		damge = 5;
	}
	else if (isBig == 2)
	{
		damge = 10;
	}
}


Amo::~Amo()
{
}

void Amo::Update()
{
	dstR.x = xpos;
	dstR.y = ypos; 
	if (shoot)
	{
		MoveUP();
		if (xpos > 1280)
		{
			dstR.x = xpos;
			dstR.y = ypos;
			shoot = false;
			xpos = x0;
			ypos = y0;
		}
	}
}

void Amo::Update(int x, int y)
{
	
	if (!shoot)
	{
		x0 = x;
		y0 = y + 50;
		xpos = x0;
		ypos = y0;
	}
}

void Amo::Render()
{
	if(shoot)
		SDL_RenderCopy(Game::renderer, ObjTexture, &srcR, &dstR);
}

void Amo::EventsHanlde()
{
}

void Amo::shooting()
{
	shoot = true;
}

void Amo::MoveUP()
{
	xpos += speed;
}
