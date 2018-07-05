#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Blood.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

public:
	virtual void Update() = 0;
	virtual void Render() = 0;
	
	virtual void EventsHanlde() = 0;
	virtual bool Collision(GameObject *);
	void setDie() { if(blood->getHP() <= 0) isAlive = false; }
	bool Alive() { return isAlive; }
	Blood * getblood() { return blood; }

protected:
	int xpos, ypos;
	SDL_Texture * ObjTexture;
	SDL_Rect srcR, dstR;
	Blood *blood;

	bool isAlive;
	int count = 0;
};

