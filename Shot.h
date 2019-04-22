#pragma once
#include "CHARA_BASE.h"

enum class SHOT_MODE {
	MOVE,
	STICK,
	MAX
};

class Shot :
	public CHARA_BASE
{
public:
	Shot();
	Shot(VECTOR2, VECTOR2, int, int, int);
	~Shot();

	void SysInit();
	void Init();
	void Update();
	void Draw();

	int CreateNumber;
	SHOT_MODE mode;

private:
	VECTOR2 endPos;

	void Move(void);
	void Stick(void);
};

