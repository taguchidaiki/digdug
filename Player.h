#pragma once
#include "CHARA_BASE.h"

constexpr auto PLAYER_SIZE_X = 16;
constexpr auto PLAYER_SIZE_Y = 16;


enum class PLAYER_MODE {
	WALK,
	BREAK = 2,
	PUNK = 4,
	SHOT = 6,
	END = 7,
	END_MAX = 11,
	MODE_MAX
};

class Player :
	public CHARA_BASE
{
public:
	Player();
	Player(VECTOR2);
	~Player();

	void SysInit(void);
	void Init(void);
	void Update(void);
	void Draw(void);

	void Move(void);

	PLAYER_MODE mode;

private:
	bool moveFlag;
	int moveTime;

	void WalkMode(void);
	void BreakMode(void);
	void PunkMode(void);
	void ShotMode(void);
	void EndMode(void);
	
};

