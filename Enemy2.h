#pragma once
#include "CHARA_BASE.h"

enum class ENEMY2_MODE {
	WALK,
	ATTACK,
	HIDE = 3,
	PUNK = 5,
	PUNK_MAX = 8,
	CRUSH,
	MODE_MAX
};

class Enemy2 :
	public CHARA_BASE
{
public:
	Enemy2();
	~Enemy2();

	void SysInit(void);
	void Init(void);
	void Update(void);
	void Draw(void);

	void ChangeMode(void) {};
	void GetMode(void) {};
};

