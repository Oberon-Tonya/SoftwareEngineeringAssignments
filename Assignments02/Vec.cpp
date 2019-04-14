#include "Vec.h"
#include <cmath>
using namespace std;

Vector2::Vector2() : x(0), y(0)
{}

Vector2::Vector2(float xf, float yf) : x(xf), y(yf)
{}

float Vector2::Length()
{
	return sqrt(x*x+y*y);
}

float Vector2::DirRad()
{
	if (IsZero()||!IsValid())
	{
		return NAN;
	}
	return atan2(y, x);
}

Vector2 Vector2::Unit()
{
	return *this / Length();
}

void Vector2::Normalize()
{
	Vector2 vUnit = this->Unit();
	*this = vUnit;
}

bool Vector2::IsNormalized()
{
	return abs(Length()-1.0f) < 1e-6;
}

bool Vector2::IsZero()
{
	return abs(x) < 1e-6 && abs(y) < 1e-6;
}

bool Vector2::IsValid()
{
	return !(isnan(x) || isnan(y) || isinf(x) || isinf(y));
}

Vector2 operator+(Vector2 v0, Vector2 v1)
{
	return Vector2(v0.x + v1.x, v0.y + v1.y);
}
Vector2 operator-(Vector2 v0, Vector2 v1)
{
	return Vector2(v0.x - v1.x, v0.y - v1.y);
}
Vector2 operator*(float s, Vector2 v)
{
	if (isnan(s) || !v.IsValid())
	{
		return Vector2(NAN, NAN);
	}
	return Vector2(v.x*s,v.y*s);
}
Vector2 operator*(Vector2 v, float s)
{
	return s * v;
}
Vector2 operator/(Vector2 v, float s)
{
	return Vector2(v.x/s,v.y/s);
}
bool operator==(Vector2 v0, Vector2 v1)
{
	return abs(v0.x-v1.x) < 1e-6 && abs(v0.y-v1.y) < 1e-6;
}
bool operator!=(Vector2 v0, Vector2 v1)
{
	return ! (v0 == v1);
}
float DotProd(Vector2 v0, Vector2 v1)
{
	return v0.x*v1.x + v0.y*v1.y;
}

float operator^(Vector2 v0, Vector2 v1)
{
	float dp = DotProd(v0, v1);
	if (!isnan(dp))
	{
		dp = dp / (v0.Length()*v1.Length());
	}
	return dp;
}
