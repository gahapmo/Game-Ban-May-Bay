#include "Game.h"
#include <iostream>

int main(int agrc, char *argv[])
{
	const char *GameName = "Game ban may bay";
	const int w = 1280;
	const int h = 640;
	const int FPS = 60;

	Uint32 timeStart, timeFrame;
	int timeDelay = 1000 / FPS;

	Game game;
	game.Init(GameName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h);

	while (game.Running())
	{
		if (Game::pause)
		{
			continue;
		}
		timeStart = SDL_GetTicks();
		game.EventsHandle();
		game.Update();
		game.Render();

		timeFrame = SDL_GetTicks() - timeStart;
		if (timeFrame < timeDelay)
			SDL_Delay(timeDelay - timeFrame);
	}
	game.Clean();

	return 0;
}