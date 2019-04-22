#include "Enemy1.h"



Enemy1::Enemy1()
{
	SysInit();
	Init();
}

Enemy1::Enemy1(VECTOR2 pos)
{
	SysInit();
	Init();
	this->pos = pos;
}


Enemy1::~Enemy1()
{
}

void Enemy1::SysInit(void)
{
	IPIMGMNG.SetID("enemy1", "image/enemy1.png", VECTOR2(ENEMY1_SIZE_X, ENEMY1_SIZE_Y), VECTOR2(9, 1));
}

void Enemy1::Init(void)
{
	divSize = VECTOR2(ENEMY1_SIZE_X, ENEMY1_SIZE_Y);
	hitSize = VECTOR2(32, 32);
	mag = VECTOR2(2.0f, 2.0f);
	turnFlag = VECTOR2(true, true);
	removeFlag = REMOVE_FALSE;
	mode = ENEMY1_MODE::WALK;
	speed = 5.0f;
	animCnt = 0;
}

void Enemy1::Update(void)
{
	switch (mode)
	{
	case ENEMY1_MODE::WALK:
		WalkMode();
		break;
	case ENEMY1_MODE::HIDE:
		HideMode();
		break;
	case ENEMY1_MODE::PUNK:
		PunkMode();
		break;
	case ENEMY1_MODE::PUNK_MAX:
		PMAXMode();
		break;
	case ENEMY1_MODE::CRUSH:
		CrushMode();
		break;
	default:
		break;
	}
}

void Enemy1::Draw(void)
{
	if(mode != ENEMY1_MODE::PUNK) IPIMGMNG.DrawAnimImage("enemy1", pos, divSize, mag, 180, turnFlag, (int)mode + (animCnt / 30) % 2, true);
	else if (mode == ENEMY1_MODE::CRUSH) IPIMGMNG.DrawAnimImage("enemy1", pos, divSize, mag, 180, turnFlag, (int)mode, true);
	else IPIMGMNG.DrawAnimImage("enemy1", pos, divSize, mag, 180, turnFlag, (int)mode + (animCnt / 60) % 4, true);
	DrawBox(pos.x, pos.y, pos.x + hitSize.x, pos.y + hitSize.y, 0xffffff, false);
}

void Enemy1::ChangeMode(int x)
{
	mode = (ENEMY1_MODE)x;
}

int Enemy1::GetMode(void)
{
	return (int)mode;
}

void Enemy1::WalkMode(void)
{	
	animCnt++;

	pos.x += speed;

	if ((pos.x >= 640 - hitSize.x) || (pos.x <= 0)) {
		speed = speed * -1;
	}

}

void Enemy1::HideMode(void)
{
}

void Enemy1::PunkMode(void)
{
	if (IPKEYMNG.trgKey[KEY_SPACE])
	{
		animCnt += 60;
	}
	else
	{
		animCnt--;
	}

	if ((int)mode + (animCnt / 60) % 4 == ((int)ENEMY1_MODE::PUNK_MAX))
	{
		mode = ENEMY1_MODE::PUNK_MAX;
		animCnt = 0;
	}
	else if ((int)mode + (animCnt / 60) < (int)ENEMY1_MODE::PUNK)
	{
		mode = ENEMY1_MODE::WALK;
		animCnt = 0;
	}
}

void Enemy1::PMAXMode(void)
{
	animCnt++;

	if (((animCnt / 30) != 0))
	{
		removeFlag = REMOVE_TRUE;
	}
}

void Enemy1::CrushMode(void)
{
}
