#include "EneCtl.h"
#include "Enemy1.h"
#include "Enemy2.h"



void EneCtl::Create(void)
{
	enemyList.clear();
	Enemy1 *obj = new Enemy1(VECTOR2(100, 96 + 32 * 8));
	enemyList.push_back(obj);
}

void EneCtl::Delete(void)
{
	for (auto itr = enemyList.begin(); itr != enemyList.end(); ++itr)
	{
		delete (*itr);
	}
	enemyList.clear();
}

void EneCtl::Update(void)
{
	for (auto itr = enemyList.begin(); itr != enemyList.end(); ++itr)
	{
		(*itr)->Update();

	}
}

void EneCtl::Draw(void)
{
	for (auto itr = enemyList.begin(); itr != enemyList.end(); ++itr)
	{
		(*itr)->Draw();
	}
}

void EneCtl::RemoveCheck(void)
{
	std::vector<ENEMY_BASE*>::iterator itr = enemyList.begin();
	while (itr != enemyList.end())
	{
		if ((*itr)->GetRemove() == true)
		{
			delete (*itr);
			itr = enemyList.erase(itr);
		}
		else itr++;
	}
}

EneCtl::EneCtl()
{
}


EneCtl::~EneCtl()
{
	Delete();
}
