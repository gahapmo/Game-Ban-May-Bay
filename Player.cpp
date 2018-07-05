#include "Player.h"
#include "Game.h"
#include <iostream>

Player::Player()
{
}

Player::Player(const char * texture, int x, int y)
{
	isAlive = true;
	this->ObjTexture = TextureManager::LoadTexture(texture);
	xpos = x;
	ypos = y;
	srcR.w = 256;
	srcR.h = 128;
	dstR = { xpos, ypos, 192, 96 };
	speed = 10;
	numberAmo = 10;

	amo = new Amo*[numberAmo];
	for (int i = 0; i < numberAmo; i++)
	{
		if (i == numberAmo - 1)
		{
			amo[i] = new Amo("Assets/amo3.png", xpos, ypos, 4, 2);
		}
		else if (i == numberAmo - 2)
		{
			amo[i] = new Amo("Assets/amo2.png", xpos, ypos, 10, 1);
		}
		else
		{
			amo[i] = new Amo("Assets/amo.png", xpos, ypos, 22);
		}
	}

	blood = new Blood(5, xpos, ypos);
}


Player::~Player()
{
}

void Player::Update()
{
	if (!isAlive)
	{
		if (count < 30)
		{
			count++;
		}
		else
			return;

		ObjTexture = TextureManager::LoadTexture("Assets/explosion.png");
		srcR.x = (SDL_GetTicks() / 200 % 7) * 82;
		srcR.y = 0;
		srcR.w = 86;
		srcR.h = 98;
		dstR.w = dstR.h = 200;
		return;
	}
	blood->Update(xpos, ypos);
	for (int i = 0; i < numberAmo; i++)
	{
		amo[i]->Update(xpos, ypos);
		amo[i]->Update();
	}
	srcR.x = (SDL_GetTicks() / 100 % 3) * 256;
	dstR.x = xpos;
	dstR.y = ypos;
}

void Player::Render()
{
	if (count < 30)
	{
		blood->Render();
		for (int i = 0; i < numberAmo; i++)
			amo[i]->Render();
		SDL_RenderCopy(Game::renderer, ObjTexture, &srcR, &dstR);
	}
}

int index = 0;
void Player::EventsHanlde()
{
	if (!isAlive)
		return;

	if (index == numberAmo)
		index = 0;

	if (Game::keystate[SDL_SCANCODE_UP])
	{
		MoveUP();
	}
	if (Game::keystate[SDL_SCANCODE_DOWN])
	{
		MoveDOWN();
	}
	if (Game::keystate[SDL_SCANCODE_RIGHT])
	{
		MoveRIGHT();
	}
	if (Game::keystate[SDL_SCANCODE_LEFT])
	{
		MoveLEFT();
	}

	switch (Game::event.type)
	{
	case SDL_KEYDOWN:
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_SPACE:
			amo[index++]->shooting();
			break;
		default:
			break;
		}
		break;
	}
}

void Player::MoveUP()
{
	if (ypos - speed >= 0)
		ypos -= speed;
}

void Player::MoveDOWN()
{
	if (ypos + speed + 96 <= 640)
		ypos += speed;
}

void Player::MoveRIGHT()
{
	if (xpos + speed + 192 <= 1280)
		xpos += speed;
}

void Player::MoveLEFT()
{
	if (xpos - speed >= 0)
		xpos -= speed;
}

bool Player::Collision(GameObject *o)
{
	if (GameObject::Collision(o))
	{
		blood->operator-=(blood->getHP());
		return true;
	}
	for (int i = 0; i < numberAmo; i++)
	{
		if (amo[i]->Collision(o))
		{
			o->getblood()->operator-=(amo[i]->getDamge());
			o->setDie();
			amo[i]->setShooted();
		}
	}
	return false;
}
