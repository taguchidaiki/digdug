#include <DxLib.h>
#include "MapObj.h"



MapObj::MapObj()
{
	SysInit();
	Init();
}

MapObj::~MapObj()
{
}

void MapObj::SysInit(void)
{
	IPIMGMNG.SetID("mapChip", "image/mapChip.png");
	IPIMGMNG.SetID("hole", "image/hole.png", VECTOR2(32, 32), VECTOR2(5, 1));
}

void MapObj::Init(void)
{
	divSize = VECTOR2(32, 32);
	removeFlag = REMOVE_FALSE;
	angle = 180;
}

void MapObj::Update(void)
{
}

void MapObj::Draw(void)
{
	IPIMGMNG.DrawImage("mapChip", pos, pos + divSize, true);
	DrawBox(pos.x, pos.y, pos.x + divSize.x, pos.y + divSize.y, 0x000000, false);
	if (removeFlag == REMOVE_TRUE)
	{
		IPIMGMNG.DrawAnimImage("hole", pos, divSize, mag, angle, VECTOR2(true, true), type, true);
	}
}

void MapObj::SetDepth(int depth)
{
	this->depth = (Depth)(depth / 3);
}

void MapObj::SetHoleMode(int type)
{
	this->type = (HOLE_TYPE)type;
}
