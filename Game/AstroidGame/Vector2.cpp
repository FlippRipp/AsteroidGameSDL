#include "Vector2.h"
#include <stdlib.h>
#include <iostream>

Vector2::Vector2(float xValue = 0, float yValue  = 0)
{
	x = xValue;
	y = yValue;
}
Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::~Vector2()
{
}

Vector2 Vector2::Normalized()
{
	double magn = Magnitude();
	return Vector2(x / magn, y / magn);
}

double Vector2::Distance(Vector2 distanceFrom, Vector2 distanceTo)
{
	return Distance(distanceFrom.x, distanceFrom.y, distanceTo.x, distanceTo.y);
}

double Vector2::Distance(double distanceFromX, double distanceFromY, double distanceToX, double distanceToY)
{
	double power = pow(distanceFromX - distanceToX, 2) + pow(distanceFromY - distanceToY, 2) * 1.0;

	return sqrt(power);
}

double Vector2::Dot(Vector2 a, Vector2 b)
{
	return a.x * b.x + a.y * b.y;
}

Vector2 Vector2::Perpendicular(Vector2 vector, bool isClockwise)
{
	if (isClockwise) 
	{
		return Vector2(vector.y, -vector.x);

	}
	else 
	{
		return Vector2(vector.y, -vector.x);
	}
}

Vector2 Vector2::GetDirection(Vector2 from, Vector2 to)
{
	return to - from;
}

Vector2 Vector2::GetNormalizedDirection(Vector2 from, Vector2 to)
{
	return (to - from).Normalized();
}

void Vector2::Normalize()
{
	Vector2 normalizedVector = Normalized();
	x = normalizedVector.x;
	y = normalizedVector.y;
}

Vector2 Vector2::operator+(const Vector2 v)
{
	return Vector2(x + v.x, y + v.y);
}

Vector2 Vector2::operator-(const Vector2 v)
{
	return Vector2(x - v.x, y - v.y);
}

Vector2 Vector2::operator-()
{
	return Vector2(0 - x, 0 - y);
}

Vector2 Vector2::operator*(const double d)
{
	return Vector2(x * d, y * d);
}

Vector2 Vector2::operator/(const double d)
{
	return Vector2(x / d, y / d);
}

void Vector2::operator+=(const Vector2 & v)
{
	this->x += v.x;
	this->y += v.y;
}



