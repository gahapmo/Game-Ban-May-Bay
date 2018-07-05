#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Blood
{
public:
	Blood();
	Blood(int hp, int x, int y);
	~Blood();

public:
	void Update(int x, int y);
	void Render();
	void operator-=(int);

	int getHP() { return HP; }
private:
	int HP;
	SDL_Texture * tex;
	SDL_Rect tmp, dstR;
};

