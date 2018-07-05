#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Background
{
public:
	Background();
	Background(const char *textureSheet);
	~Background();

public:
	void Update();
	void Render();
	void LoadBackground(const char * textureSheet);

protected:
	SDL_Texture * ObjTexture;
	SDL_Rect srcR, dstR;
};

