#pragma once
#include <math.h>

class Vector2
{
public:
	Vector2(float xValue, float yValue);
	Vector2();
	~Vector2();

	double x;
	double y;

	static double Distance(Vector2 distanceFrom, Vector2 distanceTo);
	static double Distance(double distanceFromX, double distanceFromY, double distanceToX, double distanceToY);
	static double Dot(Vector2 a, Vector2 b);
	static Vector2 Perpendicular(Vector2 vector, bool isClockwise);
	static Vector2 GetDirection(Vector2 from, Vector2 to);
	static Vector2 GetNormalizedDirection(Vector2 from, Vector2 to);
	static Vector2 Zero(){return Vector2(0,0); }

	void Normalize();
	Vector2 Normalized();
	double Magnitude() { return sqrt(x * x + y * y); }

	Vector2 operator+(const Vector2);
	Vector2 operator-(const Vector2);
	Vector2 operator-();
	Vector2 operator*(const double);
	Vector2 operator/(const double);
	void operator+=(const Vector2& v);

private:
};