#pragma once
class VECTOR2
{
public:
	VECTOR2();
	VECTOR2(float x, float y);
	~VECTOR2();

	void operator+=(const VECTOR2 &a);
	void operator-=(const VECTOR2 &a);
	void operator*=(const float a);
	VECTOR2 operator*(const float a)
	{
		return VECTOR2(x * a, y * a);
	}
	VECTOR2 operator-(void)
	{
		return VECTOR2(-x, -y);
	}

	float x, y;
};

VECTOR2 operator+(const VECTOR2 &a, const VECTOR2 b);
VECTOR2 operator-(const VECTOR2 &a, const VECTOR2 b);
VECTOR2 operator*(const VECTOR2 &a, const VECTOR2 b);