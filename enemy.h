#pragma once
#include "GameObject.h"
#include <SDL.h>
#include <SDL_image.h>

class enemy :
	public GameObject
{
public:
	enemy();
	enemy(const char *textureSheet, int x, int y, int hp);
	~enemy();

public:
	void Update();
	void Render();
	void EventsHanlde();


};

