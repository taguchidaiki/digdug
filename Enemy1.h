#pragma once
#include "ENEMY_BASE.h"

#define ENEMY1_SIZE_X 24
#define ENEMY1_SIZE_Y 20 

enum class ENEMY1_MODE {
	WALK,
	HIDE = 2,
	PUNK = 4,
	PUNK_MAX = 7,
	CRUSH,
	MODE_MAX
};

class Enemy1 :
	public ENEMY_BASE
{
public:
	Enemy1();
	Enemy1(VECTOR2);
	~Enemy1();

	void SysInit(void);
	void Init(void);
	void Update(void);
	void Draw(void);

	void ChangeMode(int);
	int GetMode(void);

	ENEMY1_MODE mode;

private:
	void WalkMode(void);
	void HideMode(void);
	void PunkMode(void);
	void PMAXMode(void);
	void CrushMode(void);

};

