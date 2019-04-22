#pragma once
#include "CHARA_BASE.h"


class ENEMY_BASE :
	public CHARA_BASE
{
public:
	ENEMY_BASE();
	virtual ~ENEMY_BASE();

	virtual void SysInit(void) = 0;
	virtual void Init(void) = 0;
	virtual void Update(void) = 0;
	virtual void Draw(void) = 0;

	virtual void ChangeMode(int) = 0;
	virtual int GetMode(void) = 0;

};

