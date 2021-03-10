#pragma once
#include "Vector2.h"
#include <iostream>
class GameObject
{
public:
	GameObject();
	GameObject(Vector2 pos, double rad);
	~GameObject();

	//Gets the posiiton of the middle of the object instead of the pivot posion
	Vector2 GetRealPosition();

	virtual void OnCollision();

	Vector2 position;
	double radius;
	bool isActive = true;

	int collisionCellX, collisionCellY;

	int collisionCellIndex;
};

