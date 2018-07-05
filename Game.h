#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Player.h"
#include "enemy.h"
#include "Background.h"

class Game
{
public:
	Game();
	~Game();

public:
	void Init(const char *Name, int x, int y, int w, int h);
	void EventsHandle();
	void Update();
	void Render();
	void Clean();
	bool isWin();

	bool Running();

public:
	static SDL_Renderer * renderer;
	static SDL_Event event;
	static bool isRunning;
	static bool pause;
	static const Uint8 * keystate;

private:
	SDL_Window * window;
	Background * backgound;
	GameObject * player;
	GameObject **ene;
	int numberEnemy;
};

