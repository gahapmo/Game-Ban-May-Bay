#pragma once
#include "GameObject.h"
#include "TextureManager.h"
#include "Amo.h"
class Player :
	public GameObject
{
public:
	Player();
	Player(const char *texture, int x, int y);
	~Player();

public:
	void Update();
	void Render();
	void EventsHanlde();
	void MoveUP();
	void MoveDOWN();
	void MoveRIGHT();
	void MoveLEFT();
	bool Collision(GameObject *);
private:
	int speed;
	Amo **amo;
	int numberAmo;
};

