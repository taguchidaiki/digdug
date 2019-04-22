#include "Shot.h"



Shot::Shot()
{
	SysInit();
	Init();
}

Shot::Shot(VECTOR2 pos, VECTOR2 size, int createCnt, int lr, int umd)
{
	SysInit();
	Init();
	this->lr = (DIR_LR)lr;
	this->umd = (DIR_UD)umd;
	this->pos = VECTOR2(pos.x + size.x * lr, pos.y + size.y - divSize.y);
	endPos = this->pos + VECTOR2(60 * lr, 10);
	CreateNumber = createCnt;
}


Shot::~Shot()
{
}

void Shot::SysInit()
{
	IPIMGMNG.SetID("shot", "image/shot.png", VECTOR2(60 / 12, 10), VECTOR2(12, 1));
}

void Shot::Init()
{
	mode = SHOT_MODE::MOVE;
	divSize = VECTOR2(60 / 12, 10);
	speed = 60 / 12;
	removeFlag = REMOVE_FALSE;
	turnFlag = VECTOR2(true, true);
	mov = VECTOR2(0, 0);
}

void Shot::Update()
{
	mov = VECTOR2(0, 0);
	switch (mode)
	{
	case SHOT_MODE::MOVE:
		Move();
		break;
	case SHOT_MODE::STICK:
		Stick();
		break;
	default:
		break;
	}
}

void Shot::Draw()
{
	IPIMGMNG.DrawAnimImage("shot", pos, divSize, mag, 180, turnFlag, CreateNumber, true);
	//DrawBox(pos.x, pos.y, pos.x + (divSize.x * mag.x), pos.y + (divSize.y * mag.y), 0xffffff, false);
}

void Shot::Move(void)
{

	if (lr == DIR_RIGHT)
	{
		if (umd == DIR_DOWN) turnFlag = VECTOR2(true, false);
		else {
			turnFlag = VECTOR2(true, true);
			if (umd == DIR_MIDDLE) angle = 180;
		}
	}
	else if (lr = DIR_LEFT)
	{
		if (umd == DIR_DOWN) turnFlag = VECTOR2(false, false);
		else {
			turnFlag = VECTOR2(false, true);
			if (umd == DIR_MIDDLE) angle = 180;
		}
	}

	if (umd == DIR_MIDDLE) { mov.x += speed * (int)lr; }
	else { mov.y += speed * (int)umd; }

	pos += mov;

	if (pos.x > endPos.x)
	{
		if (pos.x <= endPos.x)
		{
			removeFlag = REMOVE_TRUE;
		}
	}
	else
	{
		if (pos.x >= endPos.x)
		{
			removeFlag = REMOVE_TRUE;
		}
	}
	
}

void Shot::Stick(void)
{

}
