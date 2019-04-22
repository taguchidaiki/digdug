#include "VECTOR2.h"



VECTOR2::VECTOR2()
{
	x = 0;
	y = 0;
}

VECTOR2::VECTOR2(float x, float y)
{
	this->x = x;
	this->y = y;
}


VECTOR2::~VECTOR2()
{
}

void VECTOR2::operator+=(const VECTOR2 &a)
{
	x += a.x;
	y += a.y;
}

void VECTOR2::operator-=(const VECTOR2 &a)
{
	x -= a.x;
	y -= a.y;
}

void VECTOR2::operator*=(const float a)
{
	x *= a;
	y *= a;
}

VECTOR2 operator+(const VECTOR2 &a, const VECTOR2 b)
{
	return VECTOR2(a.x + b.x, a.y + b.y);
}

VECTOR2 operator-(const VECTOR2 & a, const VECTOR2 b)
{
	return VECTOR2(a.x - b.x, a.y - b.y);
}

VECTOR2 operator*(const VECTOR2 & a, const VECTOR2 b)
{
	return VECTOR2(a.x * b.x, a.y * b.y);
}
