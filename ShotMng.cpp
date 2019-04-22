#include "Player.h"
#include "ShotMng.h"
#include "Shot.h"



void ShotMng::Create(VECTOR2 pos, VECTOR2 size, int lr, int umd)
{
	if (createCnt >= 0)
	{
		Shot *shot = new Shot(pos, size, createCnt, lr, umd);
		shotList.push_back(shot);
		createCnt--;
	}
}

void ShotMng::Delete(void)
{
	for (auto itr = shotList.begin(); itr != shotList.end(); ++itr)
	{
		delete (*itr);
	}
	shotList.clear();
}

void ShotMng::Update(const PLAYER_MODE &mode)
{
	for (auto itr = shotList.begin(); itr != shotList.end(); ++itr)
	{
		(*itr)->Update();
		if (shotList[0]->mode == SHOT_MODE::STICK)
		{
			(*itr)->mode = SHOT_MODE::STICK;
		}

		if (mode == PLAYER_MODE::WALK)
		{
			(*itr)->SetRemove(true);
		}
	}

	if (!shotList.empty())
	{
		if (shotList[0]->GetRemove())
		{
			Delete();
			createCnt = 11;
		}
	}
}

void ShotMng::Draw(void)
{
	for (auto itr = shotList.begin(); itr != shotList.end(); ++itr)
	{
		(*itr)->Draw();
	}
}

ShotMng::ShotMng()
{
}


ShotMng::~ShotMng()
{
	Delete();
}
