#pragma once
#include "DxLib.h"
#include "VECTOR2.h"

#define SCREEN_SIZE_X 640
#define SCREEN_SIZE_Y 480

#define IPGAMETASK GameTask::GetInstance()

class Player;
class CollisionCheck;

enum GAMEMODE {
	M_Init,
	M_Title,
	M_Main,
	M_Clear,
	M_End,
	E_Init,
	E_Main
};

class GameTask
{
public:
	static GameTask &GetInstance(void)
	{
		static GameTask getInstance;
		return getInstance;
	}

	int SystemInit(void);
	int Update(void);

private:
	GameTask();
	GameTask(const GameTask&) {};
	GameTask &operator=(const GameTask&) {};
	~GameTask();

	GAMEMODE gmode;
	Player *player = nullptr;
	CollisionCheck *col = nullptr;

	int GameInit(void);
	int GameTitle(void);
	int GameMain(void);
	int GameClear(void);
	int GameEnd(void);
	int EditInit(void);
	int EditMain(void);

};

