#include "CollisionCheck.h"
#include "VECTOR2.h"


CollisionCheck::CollisionCheck()
{
}


CollisionCheck::~CollisionCheck()
{
}

bool CollisionCheck::RectVsRect(VECTOR2 posA, VECTOR2 posB, VECTOR2 sizeA, VECTOR2 sizeB, bool flagA, bool flagB)
{
	VECTOR2 posCenA = VECTOR2(posA.x + sizeA.x / 2, posA.y + sizeA.y / 2);
	VECTOR2 posCenB = VECTOR2(posB.x + sizeB.x / 2, posB.y + sizeB.y / 2);
	if (flagA == true) return false;
	if (flagB == true) return false;
	if ((posCenA.x - sizeA.x / 2 < posCenB.x + sizeB.x / 2)
		&& (posCenA.x + sizeA.x / 2 > posCenB.x - sizeB.x / 2)
		&& (posCenA.y - sizeA.y / 2 < posCenB.y + sizeB.y / 2)
		&& (posCenA.y + sizeA.y / 2 > posCenB.y - sizeB.y / 2))
	{
		return true;
	}
	return false;
}
