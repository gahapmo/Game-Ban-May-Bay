#include "GameObject.h"
#include <iostream>


GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

bool GameObject::Collision(GameObject *obj)
{
	if (obj->isAlive == false)
		return false;
	if (xpos + dstR.w >= obj->xpos && xpos <= obj->xpos + obj->dstR.w)
	{
		if (ypos + dstR.h >= obj->ypos && ypos <= obj->ypos + obj->dstR.h)
		{
			return true;
		}
	}
	return false;
}