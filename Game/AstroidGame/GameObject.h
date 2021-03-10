#pragma once
#include "Vector2.h"
#include <iostream>
#include <vector>
class GameObject
{
public:
	GameObject();
	GameObject(Vector2 pos, double rad);
	~GameObject();

	//Gets the posiiton of the middle of the object instead of the pivot posion
	Vector2 GetRealPosition();

	virtual void OnCollision();

	static enum CollisionLayers {
		player = 1,
		bullet = 2,
		rockets = 4,
		asteroids = 8
	};

	void SetCollisionMatrix(std::vector<CollisionLayers> layers);

	Vector2 position;
	double radius;
	bool isActive = true;

	CollisionLayers layer;

	int collisionCellX, collisionCellY;

	int collisionMatrix;

	int collisionCellIndex;
};

