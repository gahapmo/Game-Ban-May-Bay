#pragma once
#include "GameObject.h"
class Amo :
	public GameObject
{
public:
	Amo();
	Amo(const char *texture, int x, int y, int speed, int = 0);
	~Amo();

public:
	void Update();
	void Update(int x, int y);
	void Render();
	void EventsHanlde();
	void MoveUP();
	void shooting();

	bool Moving() { return isMoving; }
	void setShooted() { shoot = false; }
	int getDamge() { return damge; }
private:
	int x0, y0;
	bool shoot;
	bool isMoving;
	int speed;
	bool isBigAmo;
	int damge;
};

