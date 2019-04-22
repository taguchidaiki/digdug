#pragma once

class VECTOR2;

class CollisionCheck
{
public:
	CollisionCheck();
	~CollisionCheck();

	bool RectVsRect(VECTOR2, VECTOR2, VECTOR2, VECTOR2, bool, bool);

};

