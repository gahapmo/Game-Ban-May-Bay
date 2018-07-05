#include "Game.h"
#include <iostream>
#include <time.h>

SDL_Renderer * Game::renderer = NULL;
SDL_Event Game::event;
bool Game::isRunning = false;
bool Game::pause = false;
const Uint8 * Game::keystate;

Game::Game()
{
}


Game::~Game()
{
}

void Game::Init(const char * Name, int x, int y, int w, int h)
{
	srand(time(NULL));
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(Name, x, y, w, h, 0);
		renderer = SDL_CreateRenderer(window, -1, 0);
		isRunning = true;
	}
	else
	{
		isRunning = false;
	}
	
	player = new Player("Assets/player_ani.png", 0, 0);
	backgound = new Background("Assets/background2.jpg");

	numberEnemy = 30;
	ene = new GameObject*[numberEnemy];
	for (int i = 0; i < 20; i++)
	{
		ene[i] = new enemy("Assets/enemy_ani.png", 2000 + rand() % 6000, 0 + rand() % 500, 5);
	}
	for (int i = 20; i < numberEnemy - 1; i++)
	{
		ene[i] = new enemy("Assets/enemy_ani.png", 8000 + rand() % 5000, 0 + rand() % 500, 10);
	}
	ene[numberEnemy - 1] = new enemy("Assets/enemy_ani.png", 13000 + rand() % 500, 0 + rand() % 500, 15);

}

void Game::EventsHandle()
{
	keystate = SDL_GetKeyboardState(NULL);

	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
	player->EventsHanlde();
}

int cnt = 0;
int countEnemy = 0;
void Game::Update()
{

	backgound->Update();
	player->Update();
	
	for (int i = 0; i < numberEnemy; i++)
	{
		if (player->Collision(ene[i]))
		{
			player->setDie();
		}
		ene[i]->Update();
		if (ene[i]->Alive())
			countEnemy++;
	}

	if (isWin())
	{
		if (cnt < 30)
		{
			cnt++;
			return;
		}
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Win", "You are win", window);
		pause = true;
	}
	else if (player->Alive() == false)
	{
		if (cnt < 30)
		{
			cnt++;
			return;
		}
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Loose", "You are loose", window);
		pause = true;
	}
}

void Game::Render()
{
	SDL_RenderClear(renderer);
	backgound->Render();

	for (int i = 0; i < numberEnemy; i++)
	{
		ene[i]->Render();
	}

	player->Render();
	SDL_RenderPresent(renderer);
}

void Game::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

bool Game::isWin()
{
	for (int i = 0; i < numberEnemy; i++)
	{
		if (ene[i]->Alive())
			return false;
	}
	return true;
}

bool Game::Running()
{
	return isRunning;
}
