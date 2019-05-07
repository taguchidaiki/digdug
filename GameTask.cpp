#include "GameTask.h"
#include "KeyMng.h"
#include "ImgMng.h"
#include "Player.h"
#include "MapCtl.h"
#include "MapObj.h"
#include "ShotMng.h"
#include "Shot.h"
#include "CollisionCheck.h"
#include "EneCtl.h"
#include "Enemy1.h"


int GameTask::SystemInit(void)
{
	SetWindowText("1701320_田口大貴_DIG DUG");
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);
	ChangeWindowMode(true);

	if (DxLib_Init() == -1)
	{
		return -1;
	}

	SetBackgroundColor(0, 0, 0);
	SetDrawScreen(DX_SCREEN_BACK);

	return 0;
}

int GameTask::Update(void)
{

	KeyMng::GetInstance().Update();

	switch (gmode)
	{
	case M_Init:
		GameInit();
		break;
	case M_Title:
		GameTitle();
		break;
	case M_Main:
		GameMain();
		break;
	case M_Clear:
		GameClear();
		break;
	case M_End:
		GameEnd();
		break;
	case E_Init:
		EditInit();
		break;
	case E_Main:
		EditMain();
		break;
	default:
		break;
	}

	return 0;
}

GameTask::GameTask()
{
	
}


GameTask::~GameTask()
{
	if (player != nullptr)
	{
		delete player;
		player = nullptr;
	}
	if (col != nullptr)
	{
		delete col;
		col = nullptr;
	}
}

int GameTask::GameInit(void)
{
	IPIMGMNG.SetID("title", "image/title.png");

	if(player == nullptr) player = new Player(VECTOR2(100, 96 - 32));
	if(col == nullptr) col = new CollisionCheck();

	IPENECTL.Create();
	IPMAPCTL.Create(VECTOR2(100, 96));

	gmode = M_Title;
	
	DrawString(0, 0, "GAMEINIT", 0xffff00);
	return 0;
}

int GameTask::GameTitle(void)
{
	if (IPKEYMNG.trgKey[KEY_SPACE])
	{
		gmode = M_Main;
	}
	IPIMGMNG.DrawImage("title", VECTOR2(110, 100),VECTOR2(550,220), true);
	DrawString(0, 0, "GAMETITLE", 0xffff00);
	return 0;
}

int GameTask::GameMain(void)
{
	if (player != nullptr)
	{
		player->Update();

		if (player->mode != PLAYER_MODE::END)
		{
			IPENECTL.Update();
			IPMAPCTL.Update();

			//フィールドとの当たり判定
			for (auto itr = IPMAPCTL.mapList.begin(); itr != IPMAPCTL.mapList.end(); ++itr)
			{
				if (col->RectVsRect(player->GetPos(), (*itr)->GetPos(), player->GetSize(), (*itr)->GetSize(), player->GetRemove(), (*itr)->GetRemove()) == true)
				{
					(*itr)->SetRemove(true);
					player->mode = PLAYER_MODE::BREAK;
				}

				if (!IPSHOTMNG.shotList.empty())
				{
					if (col->RectVsRect((*itr)->GetPos(), IPSHOTMNG.shotList[0]->GetPos(), (*itr)->GetSize(), IPSHOTMNG.shotList[0]->GetSize(), (*itr)->GetRemove(), IPSHOTMNG.shotList[0]->GetRemove()) == true)
					{
						IPSHOTMNG.shotList[0]->SetRemove(true);
					}
				}
			}

			//敵とプレイヤー関係の当たり判定
			for (auto itr = IPENECTL.enemyList.begin(); itr != IPENECTL.enemyList.end(); ++itr)
			{
				if (!IPSHOTMNG.shotList.empty())
				{
					if (col->RectVsRect((*itr)->GetPos(), IPSHOTMNG.shotList[0]->GetPos(), (*itr)->GetHitSize(), IPSHOTMNG.shotList[0]->GetSize(), (*itr)->GetRemove(), IPSHOTMNG.shotList[0]->GetRemove()) && (IPSHOTMNG.shotList[0]->mode != SHOT_MODE::STICK))
					{
						//エネミーのモードを書き換える処理
						(*itr)->ChangeMode((int)ENEMY1_MODE::PUNK);
						(*itr)->animCnt = 0;
						IPSHOTMNG.shotList[0]->mode = SHOT_MODE::STICK;
						player->mode = PLAYER_MODE::PUNK;
						player->animCnt = 0;
					}
				}

				if ((*itr)->GetMode() != (int)ENEMY1_MODE::PUNK)
				{
					if (col->RectVsRect((*itr)->GetPos(), player->GetPos(), (*itr)->GetHitSize(), player->GetSize(), (*itr)->GetRemove(), player->GetRemove()) && (player->mode != PLAYER_MODE::END))
					{
						player->animCnt = 0;
						player->mode = PLAYER_MODE::END;
					}
				}
			}
		}

		if (player->GetRemove() == true)
		{
			delete player;
			player = nullptr;
		}
	}

	IPENECTL.RemoveCheck();
	IPMAPCTL.HoleModeCheck();

	if (IPKEYMNG.trgKey[KEY_F5])
	{
		gmode = M_Clear;
	}
	else if (IPKEYMNG.trgKey[KEY_F6])
	{
		gmode = M_End;
	}

	IPMAPCTL.Draw();

	if (player != nullptr)
	{
		player->Draw();
	}

	IPENECTL.Draw();

	DrawString(0, 0, "GAMEMAIN", 0xffff00);
	return 0;
}

int GameTask::GameClear(void)
{
	if (IPKEYMNG.trgKey[KEY_F5])
	{
		if (player != nullptr)
		{
			delete player;
			player = nullptr;
		}
		gmode = M_Init;
	}
	DrawString(0, 0, "GAMECLEAR", 0xffff00);
	return 0;
}

int GameTask::GameEnd(void)
{
	if (IPKEYMNG.trgKey[KEY_F5])
	{
		if (player != nullptr)
		{
			delete player;
			player = nullptr;
		}
		gmode = M_Init;
	}
	DrawString(0, 0, "GAMEEND", 0xffff00);
	return 0;
}

int GameTask::EditInit(void)
{
	return 0;
}

int GameTask::EditMain(void)
{
	return 0;
}
