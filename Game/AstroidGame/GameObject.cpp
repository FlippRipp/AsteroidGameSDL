#include "GameObject.h"

GameObject::GameObject()
{
	//radius = 10;
}

GameObject::GameObject(Vector2 pos, double rad)
{
	position = pos;
	radius = rad;
}

Vector2 GameObject::GetRealPosition()
{
	return Vector2(position.x + radius, position.y + radius);
}

void GameObject::OnCollision()
{
}

GameObject::~GameObject()
{
}
