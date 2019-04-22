#include "Enemy2.h"



Enemy2::Enemy2()
{
}


Enemy2::~Enemy2()
{
}

void Enemy2::SysInit(void)
{
}

void Enemy2::Init(void)
{
}

void Enemy2::Update(void)
{
}

void Enemy2::Draw(void)
{
	DrawBox(pos.x, pos.y, pos.x + divSize.x, pos.y + divSize.y, 0xffffff, false);
}
